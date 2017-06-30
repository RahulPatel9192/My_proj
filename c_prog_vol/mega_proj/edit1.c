#include "header_h.h"

#define STATION_NU 10
#define DISTANCE 1000

struct traininfo {
    char train_nu[6];
    char train_name[20];
    char avg_speed[5];
    char src_t[10];
    char dest_t[10];
    char arrival[8];
    char depar[8];
    char seat[3];
}var;

static const char *station[STATION_NU] ={"A","B","C","D","E","F","G","H","I","J"};

static void addrevroute();

static int time (char *avg,char *src, char *dst, char *depar)
{
    int tim;
    int avegs;
    char zero[3]="0";
    char buff[10],buff1[10];
    int distance = 100;
    int dis2;
    int st,dt;
    double t;
    int i=0,k=0,j=0;
    int m = 1440;
    int hr,min;

    for(st=0; st<STATION_NU; st++)
        if ((strcmp(src,station[st])) == 0)
            break;

    for(dt=0; dt<STATION_NU; dt++)
        if ((strcmp(dst,station[dt])) == 0)
            break;
    st+=1;dt+=1;
    dis2 = (abs(dt-st));
    dis2*=distance;
    for(i=0,j=0;depar[i];i++) {
        if( depar[i] != ':')
            buff[j++]= depar[i];
        else
            break;
    }
    buff[j] = '\0';
    for(j=0,i++;depar[i];i++) {
        buff1[j++] = depar[i];
    }
    buff1[j]='\0';

    i=0;j=0;
    hr=atoi(buff);
    min=atoi(buff1);
    min = min +(hr*60);

    tim = (dis2/(atoi(avg)));
    min += (tim * 60);
    i = min/60;
    j=i*60;
    j =min-j;

    for(k=1 ;i>=24;) {
        k++;
        i=i-24;
    }
    sprintf(buff,"%d",i);
    strcat(buff,":");
    if ( j > 10)
    sprintf(buff1,"%d",j);
    else {
    sprintf(buff1,"%d",j);
    strcat(buff1,zero);
    }
    strcat(buff,buff1);
    strcpy(var.arrival,buff);
    return k;
}

static void check (char *nu)
{

    char buff[8];
    int i=0;


}

int edittraininfo()
{

    char admin_name[10];
    char admin_pw[10];
    int option;
    int flag;

label:
   /* printf("Enter username: ");
    scanf("%s",admin_name);

    printf("Enter password: ");
    scanf("%s",admin_pw);
*/
    if ( /*(strcmp(admin_name,"admin") == 0) && (strcmp(admin_pw,"123") == 0)*/1 ) {
        while(1) {
            printf("Menu:\n");
            printf("1) Add New Trian\n2) Delete Train\n3) Edit Train Info\n");
            printf("4) Exit\n");
            scanf("%d",&option);


            switch (option) {

                case 1:
                    AddNewTrain();
                    break;
                case 2:
                    flag = DeleteTrain();
                    if ( flag == 0 )
                        printf ("Train not found\n");
                    break;
                case 3:
                    flag = EditTrainInfo();
                    if ( flag == 0 )
                        printf ("Train not found\n");
                    break;
                case 4:
                    break;
                default:
                    printf("Enter valid option\n");

            }
            if ( option == 4 )
                break;
        }


    }
    else {

        printf("username or password is incorrect ");
        printf("enter valid username or password\n");
        goto label;

    }

}

int AddNewTrain()
{
    char trainnu[5];
    char trainname[20];
    char avgspeed[3];
    char source[6];
    char destination[6];
    char departuretime[8];
    char arrivaltime[8];
    char seat[3];
    char Day[5]="Day-";
    char comma = ',';
    int flag = 0,day;
    FILE *t_info;

    t_info = fopen("traininfo.csv","a");

    printf("enter train number: ");
    scanf("%s",trainnu);
    flag = TrainInfoNumber(atoi(trainnu));
    if ( flag == 1 )
        return 0;
    else {
        strcpy(var.train_nu,trainnu);

        printf("enter train name: ");
        scanf("%s",trainname);
        strcpy(var.train_name,trainname);

        printf("enter average speed: ");
        scanf("%s",avgspeed);
        strcpy(var.avg_speed,avgspeed);

        printf("enter source station: ");
        scanf("%s",source);
        strcpy(var.src_t,source);

        printf("enter destination station: ");
        scanf("%s",destination);
        strcpy(var.dest_t,destination);

        printf("enter departure time: ");
        scanf("%s",departuretime);
        strcpy(var.depar,departuretime);

        day=time(avgspeed,source,destination,departuretime);

        printf("enter total seat: ");
        scanf("%s",seat);
        strcpy(var.seat,seat);

        fprintf(t_info,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%d\n",var.train_nu,comma,var.train_name,comma,var.avg_speed,comma,
                var.src_t,comma,var.dest_t,comma,var.depar,comma,var.arrival,comma,var.seat,comma,Day,comma,day);
        printf("arrival time: %s\n",var.arrival);
        fclose(t_info);
        addrevroute();
    }
}

void addrevroute()
{
    FILE *t_info;
    int temp;
    char revtime[8];
    char comma = ',';
    int day;
    char Day[5]= "Day-";

    t_info = fopen("traininfo.csv","a");
    printf("Enter Time: ");
    scanf("%s",revtime);
    strcpy(var.depar,revtime);
    day=time(var.avg_speed,var.src_t,var.dest_t,revtime);
    temp = (atoi(var.train_nu)+1);
    sprintf(var.train_nu,"%d",temp);
    fprintf(t_info,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%d\n",var.train_nu,comma,var.train_name,comma,var.avg_speed,comma,
            var.dest_t,comma,var.src_t,comma,var.depar,comma,var.arrival,comma,var.seat,comma,Day,comma,day);
    fclose(t_info);
    perror("fclose: ");

}

int DeleteTrain()
{

    char trainnu[5];
    int cnt = 0,i=0,j=0;
    char str[200];
    char buff1[10],buff[10];
    FILE *t_info,*temp;
    int flag = 0;
    printf("Enter train number: ");
    scanf("%s",trainnu);

    t_info = fopen("traininfo.csv","r");
    temp = fopen("temp.csv","w");

    while ( fgets(str,200,t_info) != NULL) {
        for(i=0,j=0;str[i];i++) {

            if (str[i] == ',') {
                buff1[j] = '\0';
                break;
            }
            else {
                buff1[j++] = str[i];

            }
        }
        if ((strcmp(trainnu,buff1)) == 0)
            flag =1;
        else
            fputs(str,temp);
    }
    rewind(t_info);
    rewind(temp);

    t_info=fopen("traininfo.csv","w");
    temp=fopen("temp.csv","r");

    while(fgets(str,200,temp) != NULL) 
        fputs(str,t_info);

    fclose(t_info);
    fclose(temp);


    return flag;
}

int EditTrainInfo()
{

    char str[200],buff[10];
    int cnt = 0,i=0,j=0;
    char trainnu[8];
    char comma = ',';
    char Day[5]="Day-";
    int flag = 0,day;
    int option;
    FILE *t_info;
    FILE *temp;

    t_info = fopen("traininfo.csv","r");
    temp = fopen("temp.csv","w");
    printf("Enter train number: ");
    scanf("%s",trainnu);
    flag=TrainInfoNumber(atoi(trainnu));
    if(flag == 0) {
        return flag;
    }
    flag = 1;
    printf("Menu: \n");
    printf("1) Average Speed\n2) Source station\n3) Destination station\n4) Departure Time\n");
    scanf("%d",&option);

    while( fgets(str,200,t_info) != NULL ) {
        for ( i =0,cnt=0 ; str[i]; i++) {
            if( str[i] != ',' && str[i] != '\n') 
                buff[j++] = str[i];

            else {
                cnt++;
                buff[j] = '\0';
                j=0;
                switch(cnt) {

                    case 1: 
                        strcpy(var.train_nu,buff);
                        break;
                    case 2:
                        strcpy(var.train_name,buff);
                        break;
                    case 3:
                        strcpy(var.avg_speed,buff);
                        break;
                    case 4:
                        strcpy(var.src_t,buff);
                        break;
                    case 5:
                        strcpy(var.dest_t,buff);
                        break;
                    case 6:
                        strcpy(var.depar,buff);
                        break;          
                    case 7:
                        strcpy(var.arrival,buff);
                        break;          
                    case 8:
                        strcpy(var.seat,buff);
                        break;          
                }
            }
        }
        if ((strcmp(var.train_nu,trainnu)) == 0) {
            switch(option) {

                case 1: 
                    printf("Enter New avg speed: ");
                    scanf("%s",buff);
                    strcpy(var.avg_speed,buff);
                    day=time(var.avg_speed,var.src_t,var.dest_t,var.depar);
                    break;
                case 2:
                    printf("Enter New source station: ");
                    scanf("%s",buff);
                    strcpy(var.src_t,buff);
                    day=time(var.avg_speed,var.src_t,var.dest_t,var.depar);
                    break;
                case 3:
                    printf("Enter New destination station: ");
                    scanf("%s",buff);
                    strcpy(var.dest_t,buff);
                    day=time(var.avg_speed,var.src_t,var.dest_t,var.depar);
                    break;
                case 4:
                    printf("Enter New departure Time: ");
                    scanf("%s",buff);
                    strcpy(var.depar,buff);
                    day=time(var.avg_speed,var.src_t,var.dest_t,var.depar);
                    break;
            }
            fprintf(temp,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%d\n",var.train_nu,comma,var.train_name,comma,var.avg_speed,comma,
                    var.src_t,comma,var.dest_t,comma,var.depar,comma,var.arrival,comma,var.seat,comma,Day,comma,day);

        }
        else {
            fprintf(temp,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%d\n",var.train_nu,comma,var.train_name,comma,var.avg_speed,comma,
                    var.src_t,comma,var.dest_t,comma,var.depar,comma,var.arrival,comma,var.seat,comma,Day,comma,day);
        }
    }
    rewind(t_info);
    rewind(temp);
    fclose(t_info);
    fclose(temp);
    t_info = fopen("traininfo.csv","w");
    temp = fopen("temp.csv","r");

    while (fgets(str,200,temp) != NULL) 
        fputs(str,t_info);

    fclose(t_info);
    fclose(temp);

    return flag;

}


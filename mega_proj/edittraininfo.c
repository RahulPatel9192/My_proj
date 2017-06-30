/*Copyright(c) <2016>, Volansys Technologies 
 *  *  * 
 * Description: 
 * @edittraininfo.c   
 * @This is part of rail reservation system this module do Add New Train, Delete Exsisting Train,
 *  or Edit Exisiting Train informations.
 *    
 * Author       - Rahul Patel 
 *    
 ********************************************************************************* 
 *             
 * History 
 *               
 * Aug/31/2016, Rahul P  
 *                                            
 * Aug/31/2016, Rahul P, Created
 * 
 *********************************************************************************/
#include "header_h.h"

/* traininfo structure hold some train related info */
static struct traininfo {
    char train_nu[6];      /* Train numbe */
    char train_name[20];   /* Train name */
    char avg_speed[5];     /* Average speed */
    char src_t[10];        /* source station */
    char dest_t[10];       /* Destination station */
    char arrival[8];       /* arrival time */
    char depar[8];         /* Departure time */
    char t_day[5];          /* Days */
}var;

/* array contains name of stations */
static const char *station[STATION_NU] ={"A","B","C","D","E","F","G","H","I","J"};

/* Add reverce route of the train */
static void addrevroute();

/* editing train releted information*/
static int EditTrainInfo();

/* Add new trian into database*/
static int AddNewTrain();

/* Delete train into database */
static int DeleteTrain();

/* find arrival time 
 * time function return day of journey and set arrvial time
 * into the struct traininfo 
 * @avg: average speed
 * @src: source station
 * @dst: destination station 
 * @depr: departure time*/
static int time (char *avg,char *src, char *dst, char *depar)
{
    int tim;
    char zero[3]="0"; /* zero string */
    char buff[10],buff1[10]; /* Temporary buffer */
    int distance = 100; /* distance between two station */
    int dis2; /* distance between two station */
    int st,dt; /* source/destination station */
    int i=0,k=0,j=0; /* counting purpose */
    int hr,min;  /* hold hour and minute */

    /* find source station */
    for(st=0; st<STATION_NU; st++)
        if ((strcmp(src,station[st])) == 0)
            break;

    /* find destination station */
    for(dt=0; dt<STATION_NU; dt++)
        if ((strcmp(dst,station[dt])) == 0)
            break;

    st+=1;dt+=1;
    dis2 = (abs(dt-st)); 
    dis2*=distance;     /* distance between two stations */

    /* store hr in string */
    for(i=0,j=0;depar[i];i++) {
        if( depar[i] != ':')
            buff[j++]= depar[i];
        else
            break;
    }
    buff[j] = '\0';

    /* store min in string */
    for(j=0,i++;depar[i];i++) {
        buff1[j++] = depar[i];
    }
    buff1[j]='\0';

    i=0;j=0;
    hr=atoi(buff); /* convert hour ascii to int */
    min=atoi(buff1); /* convert min ascii to int */
    min = min +(hr*60); /* total minute between two stations */

    tim = (dis2/(atoi(avg)));
    min += (tim * 60);
    i = min/60; /* find hour */
    j=i*60;
    j =min-j; /* find minutes */

    /* find day */
    for(k=1 ;i>=24;) {
        k++;
        i=i-24;
    }

    sprintf(buff,"%d",i); /* convert hr into ascii */
    strcat(buff,":");
    /* convert min into ascii */
    if ( j > 10)
        sprintf(buff1,"%d",j);
    else {
        sprintf(buff1,"%d",j);
        strcat(buff1,zero);
    }
    strcat(buff,buff1);
    strcpy(var.arrival,buff); /* copy arrival time into stucture in string format */
    return k; /* return day */
}

/* edittraininfo: give option to admin*/
int edittraininfo()
{

    char admin_name[10]; /* store  username */
    char admin_pw[10]; /* store password */
    int option;
    int flag = 1;

    /* checking username and pasword */
label:
    printf("Only Admin have Permission to access\n");
    printf("Enter Admin's username: ");
    scanf("%s",admin_name);

    printf("Enter Admin's password: ");
    scanf("%s",admin_pw);

    /* check admin username and password is right */
    if ( (strcmp(admin_name,UNAME) == 0) && (strcmp(admin_pw,PW) == 0) ) {
        while(1) {
            printf("\n\nMenu:\n");
            printf("1) Add New Train\n2) Delete Train\n3) Edit Train Info\n");
            printf("4) Exit\n");
            scanf("%d",&option);


            switch (option) {

                case 1:
                    AddNewTrain(); /* add new train*/
                    break;
                case 2:
                    flag = DeleteTrain(); /* delete train */
                    if ( flag == 0 )
                        printf ("Train not found\n");
                    break;
                case 3:
                    flag = EditTrainInfo(); /* edit train info */
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
    return flag;
}

/* AddNewTrain: adding new train into data base 
 * and return 1 or 0*/
static int AddNewTrain()
{
    char trainnu[5]; /* train number */
    char trainname[20]; /* train name */
    char avgspeed[3]; /* average speed */
    char source[6]; /* source station */
    char destination[6]; /* destination station */
    char departuretime[8]; /* departure time */
    char t_day[5]; /* number of seat */
    char comma = ',';
    int flag = 0,day;
    int i = 0; /* counting purpose */
    char w_day[10]; /* store week day */
    int wday; /* how many day train run */
    FILE *t_info; /* point to traininfo data base */
    FILE *fp_wday; /* point to the week day file */

    t_info = fopen("traininfo.csv","a"); /* open file in append mode */

    printf("enter train number: ");
    scanf("%s",trainnu);
    flag = TrainInfoNumber(atoi(trainnu)); /* check train number is present on not*/
    if ( flag == 1 )
        return 0;
    else {                        /* train number is not present than take detail*/
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

        /* find day and arrival time */
        day=time(avgspeed,source,destination,departuretime);
        sprintf(var.t_day,"%d",day);
       
        /* put all data into trainnfo.csv file */
        fprintf(t_info,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s\n",var.train_nu,comma,var.train_name,comma,var.avg_speed,comma,
                var.src_t,comma,var.dest_t,comma,var.depar,comma,var.arrival,comma,var.t_day);
        printf("Day-: %d\n",day);
        printf("arrival time: %s\n",var.arrival);
        fclose(t_info);

        /* add week day */
        fp_wday = fopen("wday.csv","a");
        printf("Enter how many days per week train run: ");
        scanf("%d",&wday);
        fprintf(fp_wday,"%s%c%s%c",trainnu,comma,trainname,comma);
        for( i = 0; i < wday; i++) {
            scanf("%s",w_day);
            fprintf(fp_wday,"%s%c",w_day,comma);
        }
        fprintf(fp_wday,"\n");
        fclose(fp_wday);

        addrevroute(); /* add reverse rout of the train */
    }
    return flag;
}
/* addrevroute: add reverce route to the database */
void addrevroute()
{
    FILE *t_info; /* point to the traininfo details */
    int temp,i; 
    char revtime[8]; /* arrival time for return */
    char comma = ',';
    int day; /* store week day */
    FILE *fp_wday; /* point week day file */
    int wday; /* how many days train will run */
    char w_day[10]; /* week day name */

    t_info = fopen("traininfo.csv","a");

    printf("Enter Return Time: "); /* Enter departure time */
    scanf("%s",revtime);
    strcpy(var.depar,revtime);

    /* find day and arrival time */
    day=time(var.avg_speed,var.src_t,var.dest_t,revtime);
    temp = (atoi(var.train_nu)+1); /* creat train number */
    sprintf(var.train_nu,"%d",temp);

    /* store data  into database */
    fprintf(t_info,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s\n",var.train_nu,comma,var.train_name,comma,var.avg_speed,comma,
            var.dest_t,comma,var.src_t,comma,var.depar,comma,var.arrival,comma,var.t_day);
    fclose(t_info);

    /* store week paer day */
        fp_wday = fopen("wday.csv","a");
        printf("Enter how many days per week train run: ");
        scanf("%d",&wday);
        fprintf(fp_wday,"%s%c%s%c",var.train_nu,comma,var.train_name,comma);
        for( i = 0; i < wday; i++) {
            scanf("%s",w_day);
            fprintf(fp_wday,"%s%c",w_day,comma);
        }
        fprintf(fp_wday,"\n");
        fclose(fp_wday);

}

/* DeleteTrain: delete train according to train number 
 * and return 1 or 0 */
int DeleteTrain()
{

    char trainnu[5]; /* train number */
    int i=0,j=0; /* counting purpose */
    char str[200]; /* storing line from file */
    char buff1[10]; /* temporary buffer */
    FILE *t_info; /* point to database file */
    FILE *temp; /* point to temporary file */
    int flag = 0;
    FILE *fp_wday;

    /* enter train name you wants to delete */
    printf("Enter train number: ");
    scanf("%s",trainnu);

    /* open file in read mode */
    t_info = fopen("traininfo.csv","r");
    temp = fopen("temp.csv","w"); /* open temporary file in write mode */

    while ( fgets(str,200,t_info) != NULL) {
        for(i=0,j=0;str[i];i++) { /* take trainumber to the databse */

            if (str[i] == ',') {
                buff1[j] = '\0';
                break;
            }
            else {
                buff1[j++] = str[i];

            }
        }
        /* if compare then set flag */
        if ((strcmp(trainnu,buff1)) == 0) 
            flag =1;
        else  /* if not match then put line into temporary file */
            fputs(str,temp);
    }

    /* rewind boh file pointer to the beganing */
    rewind(t_info); 
    rewind(temp);

    t_info=fopen("traininfo.csv","w");
    temp=fopen("temp.csv","r");

    /* copy all data from temporary file to our database */
    while(fgets(str,200,temp) != NULL) 
        fputs(str,t_info);

    fclose(t_info);
    fclose(temp);

    /* Delete train into the weday.csv databse */
    fp_wday = fopen("wday.csv","r");
    temp = fopen("temp.csv","w");

    while ( (fgets(str,200,fp_wday)) != NULL) {
        for(i=0,j=0;str[i];i++) {
            if( str[i] == ',') {
                buff1[j] = '\0';
                break;
        }
            else
                buff1[j++] = str[i];
    }
        if((strcmp(trainnu,buff1)) == 0);
        else
            fputs(str,temp);
    }

    rewind(temp);
    rewind(fp_wday);

    fp_wday = fopen("wday.csv","w");
    temp = fopen("temp.csv","r");

    while( (fgets(str,200,fp_wday) ) != NULL)
        fputs(str,fp_wday);
    fclose(temp);
    fclose(fp_wday);



    return flag;
}

/* EditTrainInfo: edit train information 
 * and return 1 or 0 */
int EditTrainInfo()
{

    char str[200],buff[10]; /*Temporary buffer */
    int cnt = 0,i=0,j=0; /* counting purpose */
    char trainnu[8]; /* train name */
    char comma = ',';
    int flag = 0,day; /* flags */
    int option;
    FILE *t_info; /* point to train info file */
    FILE *temp;  /* Point to temporary file */

    t_info = fopen("traininfo.csv","r");
    temp = fopen("temp.csv","w");

    printf("Enter train number: ");
    scanf("%s",trainnu);

    /* check train number is present or not */
    flag=TrainInfoNumber(atoi(trainnu));
    if(flag == 0) {
        return flag;
    }
    flag = 1;

    /* if present than show menu */
    printf("Menu: \n");
    printf("1) Average Speed\n2) Source station\n3) Destination station\n4) Departure Time\n");
    scanf("%d",&option);

    /* takin all field into structure */
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
                    /*case 8:
                        strcpy(var.t_day,buff);
                        break;*/          
                }
            }
        }
        /* if trainnumber is match the change the detail according to option */
        if ((strcmp(var.train_nu,trainnu)) == 0) {
            switch(option) {

                case 1: 
                    printf("Enter New avg speed: ");
                    scanf("%s",buff);
                    strcpy(var.avg_speed,buff);
                    /*find day and arrival time */
                    day=time(var.avg_speed,var.src_t,var.dest_t,var.depar);
                    sprintf(var.t_day,"%d",day);
                    break;
                case 2:
                    printf("Enter New source station: ");
                    scanf("%s",buff);
                    strcpy(var.src_t,buff);
                    /*find day and arrival time */
                    day=time(var.avg_speed,var.src_t,var.dest_t,var.depar);
                    sprintf(var.t_day,"%d",day);
                    break;
                case 3:
                    printf("Enter New destination station: ");
                    scanf("%s",buff);
                    strcpy(var.dest_t,buff);
                    /*find day and arrival time */
                    day=time(var.avg_speed,var.src_t,var.dest_t,var.depar);
                    sprintf(var.t_day,"%d",day);
                    break;
                case 4:
                    printf("Enter New departure Time: ");
                    scanf("%s",buff);
                    strcpy(var.depar,buff);
                    /*find day and arrival time */
                    day=time(var.avg_speed,var.src_t,var.dest_t,var.depar);
                    sprintf(var.t_day,"%d",day);
                    break;
            }
            /* put all data into temporary file */
            fprintf(temp,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s\n",var.train_nu,comma,var.train_name,comma,var.avg_speed,comma,
                    var.src_t,comma,var.dest_t,comma,var.depar,comma,var.arrival,comma,var.t_day);

        }
        else { /* if trainnumber is not match */
            /* put all database into temporary file */
            fprintf(temp,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s\n",var.train_nu,comma,var.train_name,comma,var.avg_speed,comma,
                    var.src_t,comma,var.dest_t,comma,var.depar,comma,var.arrival,comma,var.t_day);
        }
    }

    rewind(t_info);
    rewind(temp);

    fclose(t_info);
    fclose(temp);

    t_info = fopen("traininfo.csv","w");
    temp = fopen("temp.csv","r");

    /* put all data from temp file to databse */
    while (fgets(str,200,temp) != NULL) 
        fputs(str,t_info);

    fclose(t_info);
    fclose(temp);

    return flag;

}


/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @reservation.c   
 * @This is part of rail reservation system this module is use for book a ticket
 *  and it will also give a ticket number and seat number.
 *    
 * Author       - Rahul Patel 
 *   
 ******************************************************************************** 
 *            
 * History 
 *              
 * Aug/29/2016, Rahul P  
 *                                      
 * Aug/29/2016, Rahul P, Created
 * 
 *********************************************************************************/



#include "header_h.h"


/* Reservation Details */
static struct reservation {

    char trainnu[5]; /* train number */
    char trainname[20]; /* train name */
    char date[12];  /* reservation date */
    char seatnu[5]; /* seat number */
    char tktno[20]; /* ticket number */
    char name[20];  /* passenger name */
    char mno[11];  /* mobile number */
    char mail[50]; /* mail id */
}var;

/* week day array */
static char *day[8] = {"sun","mon","tue","wed","thu","fri","sat"};

/* array contains name of stations */
static const char *station[STATION_NU] ={"A","B","C","D","E","F","G","H","I","J"};

/* reset the structure */
static void reset();

static int checkwday(char *,int );

/* update seatinfo data base 
 * which take trainnumberand date and integer array which containt ticket info */
static void PutSeatDatabase(char *,int *);

/* Find day of week and return one number */
static int dayofweek()
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int d,m,y;
    char buff[5];
    int cnt = 0,i = 0 ,j = 0;

    /* convert string format into integer and find day,minute,year */
    for ( i = 0; var.date[i]; i++) {

        if ( var.date[i] != '/' && var.date[i] != '\0') { 
            buff[j++] = var.date[i];
        }
        else {

            cnt++;

            buff[j] = '\0';
            j = 0;
            switch(cnt) {
                case 1: 
                    d = atoi(buff); /* convert day to integer */
                    break;
                case 2:
                    m = atoi(buff); /* convert month into integer */
                    break;
            }

        }

    }
    y=atoi(buff); /* convert year to integer */
    y -= m < 3;
    /* find total day in year and % by 7 */
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7; 

}

/* SetNu: Give seat number to the user */
static int SeatNu( int st, int dt )
{
    int i =0,j=0,k=0; /* counting purpose */
    int temp,start; /* temporary storage */
    int vacant_seat; /* vacant seat */
    char buff[20]={0},buff1[20]={0}; /* temporary buffer */
    FILE *t_seat; /* point to the seat releted info file */
    char comma = ','; /* store comma character */
    int cnt = 0,p=0; /* counting purpose */
    char str[200]; /* store line from file */
    char *ptr; /* character pointer*/
    char number[5]={0}; /* store number */
    int seat[STATION_NU]; /* array of seats*/

    t_seat = fopen("seat.csv","a+"); /*open seat releted info file in append mode */

    //creating entry into reservation databased with train number and date
    strcpy(buff,var.trainnu);

    strcat( buff,var.date);

    /* remove '/' to the date */
    for( i =0 ; buff[i]; i++) {
        if ( buff[i] == '/')
            strcpy( buff+i,buff+i+1);
    }

    /* takinig line from the file and match with trainnumber and date */
    while ((ptr=fgets(str,200,t_seat)) != NULL) {
        cnt = 0;
        for(i=0,j=0;str[i]; i++) {
            if( str[i] != ',' && str[i] != '\n') {
                buff1[j++] = str[i];
            }
            else {
                buff1[j] = '\0';
                j =0;
                cnt++;
                if (cnt == 1)
                    break;
            }
        }
        if ((strcmp(buff1,buff)) == 0) { /* if match */
            //allocate new seat and update entries in the file
            p = 1;
            for( i+=1,j =0, k =0;str[i] && k < STATION_NU; i++) {
                if ( str[i] != ',' && str[i] != '\n')
                    number[j++] = str[i];
                else {
                    number[j] = '\0';
                    j = 0;
                    seat[k++] = atoi(number);
                }
            }

            if ( (st - dt) >= 0 ) { /* Down direction */
                temp=dt;
                dt=st;
                st=temp;
                st+=1;
            }

            /* find vacant seat */
            vacant_seat = seat[st];
            for( start = st; start < dt; start++) { 
                vacant_seat = vacant_seat & seat[start];
            }

            /* check seat are avalible or not  */
            for ( i=0,j=0;i<8 ;i++){
                if( ((vacant_seat >> i) & 1) == 1)
                    j++;
            }
            printf("Number of seats are avalible-%d\n",j);

            for( j= 0; j<8; j++) {
                if( ((vacant_seat >> j) & 1) == 1){
                    sprintf(var.seatnu,"%d",j); /* store seat number into structure */
                    break;
                }

                if ( j == 9 ){     /* If seats are full */
                    printf("No vacnacy\n");
                    return 0;
                }
            }

            /* put zero to the source-detination station's seat number */   
            for ( start = st; start<dt; start++) {
                seat[start] = (seat[start]) & ~(1<<j);

            }

            /* update seat data base*/
            PutSeatDatabase(buff,seat);

            fclose(t_seat);
            break;
        }
    }

    /* if new entry is present */
    if (p==0)
    {
        //new entry in file

        if ( (st - dt) >= 0 ) { /* Down direction */
            temp=dt;
            dt=st;
            st=temp;
            st+=1;
        }

        /* store trainnumber and date */
        fprintf(t_seat,"%s%c",buff,comma);

        /* if source station match than write all ones except one bit */
        for ( i = 0; i<STATION_NU; i++ ) {
            if( i == st) {
                for(i=st;i<=dt-1;i++ ) 
                    fprintf(t_seat,"%s%c","254",comma);
            }
            /* otherwise write all ones in every bit */
            else
                fprintf(t_seat,"%s%c","255",comma);

            if( i == dt ) {
                i--;
                dt=0;
            }
        }

        fprintf(t_seat,"%s","\n");
        sprintf(var.seatnu,"%d",0);

        fclose(t_seat);
    }
    return 1;
}

/* PutSeatDatabse: updating seat data base */
void PutSeatDatabase(char *num, int *seat)
{
    FILE *temp; /* point temporary file */
    FILE *fp_seat; /* point seat reaiated info file */
    char str[200],str1[200]; /* store file's lines */
    char buff1[20]; /* temporary buffer */
    int i=0,cnt=0,j=0; /* counting purpose */

    temp = fopen("temp.csv","w"); /* open file in writting mode */
    fp_seat = fopen("seat.csv","r"); /* open file in reading mode */

    /* make string in which trainnumber seat realeted data present */
    strcpy(str1,num);
    strcat(str1,","); 

    for(i=0;i<STATION_NU;i++) {
        sprintf(buff1,"%d",seat[i]);
        strcat(str1,buff1);
        strcat(str1,",");
    }


    while ((fgets(str,200,fp_seat)) != NULL) {
        cnt = 0;
        /* take train number to the file */
        for(i=0,j=0;str[i]; i++) {
            if( str[i] != ',' && str[i] != '\n') {
                buff1[j++] = str[i];
            }
            else {
                buff1[j] = '\0';
                j =0;
                cnt++;
                if (cnt == 1)
                    break;
            }
        }
        /* if comapre than put str1 into temporary file */
        if ( (strcmp(num,buff1)) == 0) {
            fputs(str1,temp);
        }
        /* if not comapre than put str to temporary file */
        else {
            printf("num-%s buff1-%s\n",num,buff1);
            fputs(str ,temp);
        }
    }

    fclose(temp);
    fclose(fp_seat);

    temp = fopen("temp.csv","r");
    fp_seat = fopen("seat.csv","w");

    /* copy all data to temporary file to seat.csv file */
    while(fgets(str,200,temp) != NULL)
        fputs(str,fp_seat);

    fclose(temp);
    fclose(fp_seat);
}

/* TicketNu: gives ticket number */
static void TicketNu(char *t_src, char *t_dest)
{
    char buff[20];
    int i=0;
    /* make ticket number which is combination of source station, destination station, 
     * trainnumber, journey date and seat number*/
    strcpy(buff,t_src);
    strcat(buff,t_dest);
    strcat(buff,var.trainnu);
    strcat(buff,var.date);
    strcat(buff,var.seatnu);

    for( i =0 ; buff[i]; i++) {
        if ( buff[i] == '/')
            strcpy( buff+i,buff+i+1);
    }

    strcpy(var.tktno,buff); /* copy ticket number into structure variable */
}

/*Reservation: take passenger info and give ticket number and seat number */
int Reservation()
{

    char t_src[5];  /* source station */
    char t_dest[5]; /* destination station */
    int flag = 1; /* flag */
    int wday; /* week day */
    int cnt = 0,i = 0, j = 0, k = 0; /* counting purpose */
    FILE *t_info; /* point to train info file */
    FILE *t_res; /* point to reservation info file */
    char str[200]; /* store file's line */
    char buff[10],buff1[10]; /* temporary buffer */
    char comma = ',';
    int login_option; /* option for login module*/
    int st,dt;
    char com[6] = ".com"; /* for comparision */
    char username[22]; /* username */
    char password[10]; /* password */

    printf("Login or Sign up is required \n");
    printf("1) Login\n2) sign up\n");
    scanf("%d",&login_option);
    printf("Enter username(Max 20 character): ");
    scanf("%s",username);
    printf("Enter password(Max 10 Character): ");
    scanf("%s",password);
    if( LoginModule(username,password,login_option) == 0) {
        flag = 0;
        return flag;
    }
    else {     
    t_info = fopen("traininfo.csv","r"); /* opening for reading purpose */

    /* Take reservation releted info and check its valid or not */
    printf("Enter source station(in capital): ");
    scanf("%s",buff);
    strcpy(t_src,buff);

    printf("Enter destination Staion(in capital): ");
    scanf("%s",buff1);
    strcpy(t_dest,buff1);

    flag=TrainInfoStation(buff,buff1);

    if( flag == 0 ) {
        printf("Train not found\n");
        return 0;
    }

    /* find source station */
    for(st=0; st<STATION_NU; st++)
        if ((strcmp(t_src,station[st])) == 0)
            break;

    /* find destination station */
    for(dt=0; dt<STATION_NU; dt++)
        if ((strcmp(t_dest,station[dt])) == 0)
            break;


    printf("Train number: ");
    scanf("%s",var.trainnu);
    /* checking train number is valid or not */
    flag = TrainInfoNumber(atoi(var.trainnu));
    if( flag == 0 ) {
        printf("Train not found\n");
        return 0;
    }

    printf("Reservation date(dd/mm/yyyy): ");
    scanf("%s",var.date);
    /* fin day weekday */
    wday = dayofweek();
    /* check at that day train is present or not */
    flag = checkwday(var.trainnu,wday);
    if ( flag == 0) {
        printf("Train is not going at that day\n");
        return 0;
    }

    printf("passenger name: ");
    scanf("%s",var.name);

    printf("Mobile number: ");
    scanf("%s",var.mno);

    /* Checking mobile number validation */
    if(strlen(var.mno) == 10) {
        for(i=0;var.mno[i];i++) {
            if( var.mno[i] >= '0' && var.mno[i] <= '9');
            else {
                printf("Enter valid mobile number\n");
                return 0;
            }
        }
    }
    else {
        printf("Enter 10digit Mobile number\n");
        return 0;
    }

    printf("e-mail id: ");
    scanf("%s",var.mail);

    /* Checking mail-id is valid or not */
    j = strlen(var.mail);

    if( strstr(var.mail,com) == NULL) {
        printf("Enter valid Mail id\n");
        return 0;
    }

    for ( i = j-4,k = 0; buff[i]; i++) {
        if(com[k++] != buff[i])
            break;
    }
    if( com[k-1] != buff[i-1]) {
        printf("Enter valid mailid\n");
        return 0;
    }
    for( i = 0; var.mail[i]; i++) {
        if((var.mail[i]>='a' && var.mail[i]<='z') || (var.mail[i]>='A' && var.mail[i]<='Z') 
                || (var.mail[i] >= '0'&& var.mail[i] <= '9')  || var.mail[i] == '.' || var.mail[i]=='@');
        else{
            printf("Enter valid mailid\n");
            return 0;
        }
    }

    while ( fgets(str,200,t_info) != NULL ) {

        for( i = 0, j = 0, cnt = 0; str[i]; i++) {
            if ( str[i] != comma && str[i] != '\n') {
                buff[j++] = str[i];
            }
            else {
                cnt++;
                buff[j] = '\0';
                j = 0;
                if( cnt == 1 )
                    strcpy(buff1,buff);

                if ( cnt == 2 ) {
                    strcpy(var.trainname,buff);
                    break;
                }
            }
        }   


        if ( (strcmp(var.trainnu,buff1)) == 0) {

            break;
        }
    }

    /* taking seat number */
    SeatNu(st,dt);

    /* taking ticket number */
    TicketNu(t_src,t_dest);

    t_res = fopen("reservation.csv","a");
    /* puuting all data into reservation file */
    fprintf(t_res,"%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s\n",var.trainnu,comma,var.trainname,comma,var.date,comma,
            var.name,comma,var.mno,comma,var.mail,comma,var.tktno,comma,var.seatnu);

    printf("%s %s %s %s %s %s %s %s\n",var.trainnu,var.trainname,var.date,var.name,var.mno,
            var.mail,var.tktno,var.seatnu);
    reset();


    fclose(t_res);
    fclose(t_info);
    }
    return flag;
}

/* All structure data is reset or NULL */
void reset()
{
    strcpy(var.trainnu,"\0");
    strcpy(var.trainname,"\0");
    strcpy(var.date,"\0");
    strcpy(var.seatnu,"\0");
    strcpy(var.tktno,"\0");
    strcpy(var.name,"\0");
    strcpy(var.mno,"\0");
    strcpy(var.mail,"\0");
    //strcpy(var.uid,"\0");
}

/* checkwday: check at particular week day train is present or not */
int checkwday( char *tname, int wday)
{

    int i=0,j=0,cnt=0; /* counting purpose */
    char str[200],buff1[20]; /* temporary buffer */
    FILE *fp_wday; /* point to weekday file */
    char w_day[5]; /* store week day */
    int flag = 0;

    strcpy(w_day,day[wday]);

    fp_wday = fopen("wday.csv","r");

    /* check for the week day */
    while ((fgets(str,200,fp_wday)) != NULL) {
        cnt = 0;
        for(i=0,j=0;str[i]; i++) {
            if( str[i] != ',' && str[i] != '\n') {
                buff1[j++] = str[i];
            }
            else {
                buff1[j] = '\0';
                j =0;
                cnt++;
                if (cnt == 1)
                    break;
            }
        }
        if ((strcmp(buff1,tname)) == 0 ) {
            if ((strstr(str,w_day)) != NULL)
                return 1;
        }
    }
    fclose(fp_wday);
    return flag;
}



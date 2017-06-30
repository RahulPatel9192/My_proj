/*Copyright(c) <2016>, Volansys Technologies 
 *  * 
 * Description: 
 * @traininfo.c   
 * @This is part of rail reservation system this module find train info according to 
 *  train number, train name and station name.
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
 ********************************************************************************/

#include "header_h.h"

#define TRAINNAME 50 /* length of tharin name */
#define SOURCE 50 /* length of sourcr station name */
#define DEST 50 /* length of destination station name */
#define STATION_NU 10 /* number of total stations */

/* structure which contains some train related info */
static struct train {      

    char avg_speed[5]; /* average speed */
    char src[5];  /* source station */
    char dest[5];  /* destination station */
    char s_time[10]; /* departure time */
    char d_time[10]; /* arrival time */
}var; /* structure varible */

/* array which contains station name */
static const char *station[STATION_NU] = {"A","B","C","D","E","F","G","H","I","J"};

/* Time(): calculate arrival time and departure time according to arguments*/
static int Time(int t1,int s, int d,int t)
{

    char buff[10],buff1[10]; /* buffer array */
    char zero[5] = "0"; /* hold zero*/
    int i = 0, j = 0, k = 1; /* counting purpose */
    float dis = 100, dis2; /* distance between 2 stations */
    //int m = 1440; /* total minutes in 24hr */
    float hr,min; /* storing hour and min */
    float tim; 


    t+=1; t1+=1; s+=1; d+=1;
    dis2 = (abs(s-t1)); 
    dis2*=dis;  /* distance between 2 stations */
    
    /* store hr in array */
    for( i = 0, j = 0; var.s_time[i]; i++ ) {
        if( var.s_time[i] != ':' )
            buff[j++] = var.s_time[i];
        else
            break;
    }       
    
    buff[j] = '\0';
    /* store min in array */
    for( j = 0, i++; var.s_time[i]; i++ ) {
        buff1[j++] = var.s_time[i];
    }
    buff1[j] = '\0';

    i = 0; j = 0;
    hr = atoi(buff); /* convert hr into integer */
    min = atoi(buff1); /* convert min into integer */
    min = min + (hr*60); /* total minutes between 2 stations */

    tim = (dis2/(atoi(var.avg_speed))); /* time between 2 stations */
    min += (tim * 60); 
    i = min/60;
    j = i * 60;
    j = min - j;  /* finding remaing minutes */

    /* find day */
    for( ;i >= 24;) {
        k++;
        i = i - 24;
    }

    sprintf(buff,"%d",(int)i); /* convert hr into string */
    strcat(buff,":");
    /* convert min into string */
    if ( j > 10)
        sprintf(buff1,"%d",(int)j);
    else {
        sprintf(buff1,"%d",(int)j);
        strcat(buff1,zero);
    }
    
    strcat(buff,buff1);
    strcpy(var.s_time,buff);
    /* find arrival time */
    hr = i;
    min = j;
    dis2= (abs(t-t1));
    dis2*=dis;
    tim = roundf(dis2/(atof(var.avg_speed))); /* time between 2 stations */
    hr = (hr + tim);
    

    for( ;hr>=24;) {
        k++;
        hr=hr-24;
    }
    
    sprintf(buff,"%d",(int)hr);
    strcat(buff,":");
    
    if ( min > 10)
        sprintf(buff1,"%d",(int)min);
    else {
        sprintf(buff1,"%d",(int)min);
        strcat(buff1,zero);
    }
    
    strcat(buff,buff1);
    strcpy(var.d_time,buff);
    return k;
}

/* TrainInfo: finding train according to parameters */
void TrainInfo()
{

    int option; /* save option */
    int flag; 
    int t_number;
    char t_name[TRAINNAME]; /* train number */
    char t_source[SOURCE]; /* source station */
    char t_dest[DEST];  /* destination station */

    /* Inquiry releted options */
    printf("\n\nsearch train by \n" );
    printf("1) Train number\n2) Train name\n3) Station\n");
    scanf("%d",&option);

    /* check option value and call releted function */
    switch(option) {

        case 1: 
            printf("Enter Train Number\n");
            scanf("%d",&t_number);
            flag = TrainInfoNumber(t_number);
            if(flag == 0)
                printf("Train not found\n");
            break;

        case 2:
            printf("Enter Train name\n");
            scanf("%s",t_name);
            flag = TrainInfoName(t_name);
            if(flag == 0)
                printf("Train not found\n");
            break;

        case 3:
            printf("Write Station name in capital letters \n");
            printf("Enter source station \n");
            scanf("%s",t_source);
            printf("Enter destination station \n");
            scanf("%s",t_dest);
            flag = TrainInfoStation(t_source,t_dest);
            if(flag == 0)
                printf("Train not found\n");
            break;
        default:
            printf("Enter valid option\n");
            break;
    }

}

/* TrainInfoNumber: find train according to train number */
int TrainInfoNumber ( int t_num )
{
    char buff[20]; /* buffer */
    char buff1[20]; /* buffer */
    char str[200]; /* line of file */
    int i=0,j=0; /* counting purpose */
    FILE *t_info; /* point to train info data base */
    FILE *fp_wday; /** point to weekday data base */
    int flag = 0;
    int cnt = 0; /* count comma */

    t_info = fopen("traininfo.csv","r"); /* open file in read mode */
    sprintf(buff1,"%d",t_num);

    for(i=0;buff1[i];i++)
        buff[j++]=buff1[i];

    buff[j++]=',';
    buff[j]='\0';
    i=0;
    j=0;

    /* find train number into data base */
    while( fgets(str,200,t_info) != NULL) {
        if( (strstr(str,buff)) != NULL) {  /* train found */ 
            flag = 1;
            /* Print train deatails */
            printf("\nTrainNumber  TrainName      AvgSpeed(Kmph) SrcStation ");
            printf("DestStation DepTime ArrTime Day\n");
            for(i = 0; str[i]; i++) {
                if( str[i] != ',' && str[i] != '\n')
                    buff1[j++] = str[i];
                else {
                    buff1[j] = '\0';
                    j = 0;
                    if(strlen(buff1)<10)
                        printf("%10s",buff1);
                    else
                        printf("   %-17s",buff1);
                }
            }

            /* find week day of given train number */
            /* open wday file */
            fp_wday = fopen("wday.csv","r");
            /* open file and find train number and print days */
            while( fgets(str,200,fp_wday) != NULL) {
                if( strstr(str,buff) != NULL) {
                    for( i = 0,cnt = 0; str[i]; i++) {
                        if(str[i] != ',' && str[i] != '\n')
                            buff1[j++] = str[i];
                        else {
                            cnt++;
                            buff1[j] = '\0';
                            j = 0;
                            if ( cnt > 2)
                                printf("%6s",buff1);
                        }
                    }


                }

            }
            fclose(fp_wday);
        }
    }
    fclose(t_info);
    printf("\n");
    return flag;
}

/* TrinINfoName: find traininfo according to name */
int TrainInfoName (char *t_name)
{
    char str[200]; /* store line */
    FILE *t_info; /* point to train info data bse */
    int flag = 0; /* flag */
    int i=0,j=0,cnt = 0,count = 0; /* counting purpose */
    char buff1[20]; /* temporary buffer */
    FILE *fp_wday; /* fp which hold wday file */

    t_info = fopen("traininfo.csv","r"); /* open file in reading mode */

    /* get line into the file and find train name */
    while(fgets(str,200,t_info) != NULL) {
        if ((strstr(str,t_name)) != NULL) { /* train found */
            flag = 1;
            printf("\nTrainNumber  TrainName      AvgSpeed(Kmph) SrcStation ");
            printf("DestStation DepTime ArrTime Day\n");
            /* seperate a  word and print */
            for(i = 0; str[i]; i++) {
                if( str[i] != ',' && str[i] != '\n')
                    buff1[j++] = str[i];
                else {
                    buff1[j] = '\0';
                    j = 0;
                    if(strlen(buff1)<10)
                        printf("%10s",buff1);
                    else
                        printf("   %-17s",buff1);
                }
            }

            /* open wday file */
            fp_wday = fopen("wday.csv","r");
            count = 0;

            /* open file and find train number and print days */
            while( fgets(str,200,fp_wday) != NULL) {
                if( strstr(str,t_name) != NULL) {
                    for( i = 0,cnt = 0; str[i]; i++) {
                        if(str[i] != ',' && str[i] != '\n')
                            buff1[j++] = str[i];
                        else {
                            cnt++;
                            buff1[j] = '\0';
                            j = 0;
                            if( count == 0)
                                if ( cnt > 2)
                                    printf("%6s",buff1);
                        }
                    } count++;
                }
            }
            fclose(fp_wday);
        }
    }
    fclose(t_info);
    printf("\n");

    return flag;
}

/* TrianInfoStation: find train according to source and 
   destination stations*/
int TrainInfoStation (char *src, char *dst)
{

    int flag = 0; /* flag */
    int direction; /* up direction or down direction */
    char str[200]; /* store lines */
    char buff1[50],t_nu[20]; /* temporary buffer */
    char *buff;
    int day; /* hold week day*/
    char t_source[10]; /* source station */
    char t_desti[10]; /* destination station */
    int count = 0; /* counting purpose */
    int i = 0, j = 0, comma = 3,cnt = 0; /* counting purpose */
    int src_cnt,dest_cnt,temp,temp1; /* hold source and destination stations number */
    FILE *t_info;  /* point traininfo file */
    FILE *fp_wday;  /* point weekday file */

    t_info = fopen("traininfo.csv","r"); 

    /* find source station in array */
    for(src_cnt = 0; src_cnt < STATION_NU; src_cnt++)
        if (strcmp(src,station[src_cnt]) == 0)
            break;
    temp1=src_cnt;

    /*find destination station in array */
    for(dest_cnt = 0; dest_cnt < STATION_NU; dest_cnt++)
        if(strcmp(dst,station[dest_cnt])== 0)
            break;
    temp = dest_cnt;

    /* check direction up or down */
    if ( src_cnt < dest_cnt) /* up direction */
        direction = 0;
    else
        direction = 1; /* down direction */

    if( direction == 0) {
        for ( ; src_cnt >= 0; src_cnt--) {
            for (dest_cnt = temp ;dest_cnt < STATION_NU; dest_cnt++) {    
                strcpy(src,station[src_cnt]);
                strcpy(dst,station[dest_cnt]);

                t_source[j++] = ',';
                for(i=0;src[i];i++)
                    t_source[j++] = src[i];

                t_source[j]='\0'; /* source station pattern */

                i=0;
                j=0;
                t_desti[j++] = ',';
                for(i=0;dst[i];i++)
                    t_desti[j++] = dst[i];

                t_desti[j++]=',';
                t_desti[j]='\0'; /* Destination pattern */

                i=0;
                j=0;

                /* make pattern to find the station */
                buff = strcat(t_source,t_desti);

                while( fgets(str,200,t_info) != NULL ) {
                    if( strstr(str,buff) != NULL) { /* if found */
                        flag = 1;
                        cnt = 0;
                        printf("\nTrainNumber  TrainName      AvgSpeed(Kmph) ");
                        printf("  DepTime   ArrTime Day\n");
                        /* take all words in structure variable */
                        for(i = 0; str[i]; i++) {
                            if( str[i] != ',' && str[i] != '\n')
                                buff1[j++] = str[i];
                            else {
                                buff1[j] = '\0';
                                j = 0;
                                cnt++;
                                if (cnt == 1)
                                    strcpy(t_nu,buff1);

                                if( cnt >= comma && cnt <= 7) {
                                    switch( cnt ) {

                                        case 3:
                                            strcpy(var.avg_speed,buff1);
                                            break;
                                        case 4:
                                            strcpy(var.src,buff1);
                                            break;
                                        case 5:
                                            strcpy(var.dest,buff1);
                                            break;
                                        case 6:
                                            strcpy(var.s_time,buff1);
                                            break;
                                        case 7:
                                            strcpy(var.d_time,buff1);
                                            break;
                                    }
                                    continue;
                                }
                                if ( cnt == 8) {
                                    /* find week day and arrival time */
                                    day=Time(temp1,src_cnt,dest_cnt,temp);
                                    printf("  %10s %13s %13s  %6d",var.avg_speed,
                                            var.s_time,var.d_time,day);
                                    break;
                                }
                                else {
                                    if(strlen(buff1)<10)
                                        printf("%10s",buff1);
                                    else
                                        printf("   %-17s",buff1);
                                }
                            }
                        }

                        fp_wday = fopen("wday.csv","r");
                        count = 0;
                        /* open file and find train number and print days */
                        while( fgets(str,200,fp_wday) != NULL) {
                            if( strstr(str,t_nu) != NULL) {
                                for( i = 0;str[i]; i++) {
                                    if(str[i] != ',' && str[i] != '\n')
                                        buff1[j++] = str[i];
                                    else {
                                        count++;
                                        buff1[j] = '\0';
                                        j = 0;
                                        if ( count > 2)
                                            printf("%6s",buff1);
                                    }
                                }
                            }

                        }
                        fclose(fp_wday);   
                    }
                }
                rewind(t_info);
            }
        }
    }
    else { /* for down direction */
        for ( ; src_cnt < STATION_NU; src_cnt++) {
            for (dest_cnt = temp ;dest_cnt >= 0; dest_cnt--) {    
                strcpy(src,station[src_cnt]);
                strcpy(dst,station[dest_cnt]);
                t_source[j++] = ',';
                for(i=0;src[i];i++)
                    t_source[j++] = src[i];

                t_source[j]='\0';
                i=0;
                j=0;
                t_desti[j++] = ',';
                for(i=0;dst[i];i++)
                    t_desti[j++] = dst[i];

                t_desti[j++]=',';
                t_desti[j]='\0';
                i=0;
                j=0;

                buff = strcat(t_source,t_desti);

                // printf("%s \n",buff);
                while( fgets(str,200,t_info) != NULL ) {
                    if( strstr(str,buff) != NULL) {
                        flag = 1;
                        cnt = 0;
                        printf("\nTrainNumber  TrainName      AvgSpeed(Kmph) ");
                        printf("  DepTime   ArrTime   Day\n");
                        for(i = 0; str[i]; i++) {
                            if( str[i] != ',' && str[i] != '\n')
                                buff1[j++] = str[i];
                            else {
                                buff1[j] = '\0';
                                j = 0;
                                cnt++;
                                if( cnt == 1)
                                    strcpy(t_nu,buff1);
                                if( cnt >=comma && cnt <= 7) {
                                    switch( cnt ) {

                                        case 3:
                                            strcpy(var.avg_speed,buff1);
                                            break;
                                        case 4:
                                            strcpy(var.src,buff1);
                                            break;
                                        case 5:
                                            strcpy(var.dest,buff1);
                                            break;
                                        case 6:

                                            strcpy(var.s_time,buff1);
                                            break;
                                        case 7:

                                            strcpy(var.d_time,buff1);
                                            break;
                                    }
                                    continue;
                                }
                                if ( cnt == 8) {
                                    day=Time(temp1,src_cnt,dest_cnt,temp);
                                    printf("  %10s %13s %13s %6d",var.avg_speed,var.s_time,var.d_time,day);
                                    break;
                                }
                                else {
                                    if(strlen(buff1)<10)
                                        printf("%10s",buff1);
                                    else
                                        printf("   %-17s",buff1);
                                }
                            }
                        }

                        /* finding at ehich day train is run */
                        /* open wday file */
                        fp_wday = fopen("wday.csv","r");

                        /* open file and find train number and print days */
                        while( fgets(str,200,fp_wday) != NULL) {
                            if( strstr(str,t_nu) != NULL) {
                                for( i = 0, cnt = 0;str[i]; i++) {
                                    if(str[i] != ',' && str[i] != '\n')
                                        buff1[j++] = str[i];
                                    else {
                                        count++;
                                        buff1[j] = '\0';
                                        j = 0;
                                        if ( count > 2)
                                            printf("%6s",buff1);
                                    }
                                }
                            }
                        }
                        fclose(fp_wday);
                    }
                }
                rewind(t_info);
            }
        }
    }

    fclose(t_info);

    printf("\n");

    return flag;
}

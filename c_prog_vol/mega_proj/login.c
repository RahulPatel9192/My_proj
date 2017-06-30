/*Copyright(c) <2016>, Volansys Technologies 
 *  *  * 
 * Description: 
 * @login.c   
 * @This is part of rail reservation system this is a login module we check user is
 * valid or not if valid then access application. or we can creat new user also.
 *     
 * Author       - Rahul Patel 
 *  
 ********************************************************************************* 
 *             
 * History 
 *               
 * Aug/29/2016, Rahul P  
 *                                      
 * Aug/29/2016, Rahul P, Created
 * 
 *********************************************************************************/


#include "header_h.h"

/* Signup: add new user */
static int Signup();

/* Login: login for exsisting user */
static int Login();

int LoginModule(char *uname, char *pw, int op)
{

    int flag;

    switch( op ) {

        case 1: 
            flag = Login(uname,pw);
            break;
        case 2: 
            flag = Signup(uname,pw);
            break;
    }

    return flag;
}

/* Signup: creat new user */
int Signup(char *name, char *pw)
{
    FILE *fp_user; /* point to user.csv file */
    char comma = ','; /* comma character */
    int i,j,cnt; /* counting purpose */
    char buff[22],str[50]; /* buffer array */
    int flag = 1;

label:
    /* Checking range of username */
    if ( strlen(name) > 21) {
        printf("please write ur name within range\n");
        flag = 0;
        return flag;
    }

    fp_user = fopen("user.csv","r");
    while ( fgets( str,50,fp_user) != NULL) {
        for( i = 0, j = 0, cnt = 0; str[i]; i++ ) {
            if( str[i] != comma) 
                buff[j++] = str[i];
            else {
                buff[j] = '\0';
                j = 0;
                cnt++;
                if ( cnt == 1) {
                    if ((strcmp(name,buff)) == 0) {
                        printf("username exist choose different\n");
                        goto label;
                    }
                }
            }
        }
    }
    fclose(fp_user);
    
    /* checking range of password */
    if ( strlen(pw) > 10) {
        printf("please write ur password within range\n");
        flag = 0;
        return flag;
    }

    /* open file in append mode */
    fp_user = fopen("user.csv","a");

    /* Write data into file */
    fprintf(fp_user,"%s%c%s\n",name,comma,pw);

    fclose(fp_user);
    return flag;
} 

/* Login: checking usename or password is correct or not */
int Login(char *name, char *pw)
{       

    FILE *fp_user; /* Point to user.csv file */
    char comma = ','; /* comma character */
    char str[50]; /* store file line */
    char buff_name[22]; /* store usename to the databse */
    char buff_pw[12]; /* Store password to the database */
    char buff[22]; /* buffer */
    int i,j,cnt = 0; /* counting purpose */
    int flag = 0; /* flag */
    int option;  /* Store  Menu option */   
    
    /* checking range of username */
    if ( strlen(name) > 21) {
        printf("please write ur name within range\n");
        return 0;
    }
    
    /* check range of password */
    if ( strlen(pw) > 10) {
        printf("please write ur password within range\n");
        return 0;
    }


    /* open database in read mode and take username and password */
    fp_user = fopen("user.csv","r");
    while ((fgets(str,50,fp_user)) != NULL) {
        for(i=0,cnt = 0,j=0;str[i];i++) {
            if (str[i] != comma && str[i] != '\n')
                buff[j++] = str[i];

            else{
                buff[j] = '\0';
                j = 0;
                cnt++; 

                switch(cnt) {
                    case 1: 
                        strcpy(buff_name,buff); /* store username */
                        break;
                    case 2:
                        strcpy(buff_pw,buff); /* store password */
                        break;
                }       
            }   
        }

        /* check usename or password is correct or not */
        if ( (strcmp(name,buff_name)) == 0) {
            if( (strcmp(pw,buff_pw)) == 0) {
                flag = 1;
                break; 
            }
        }   
    }
    /* if correct than enter to the menu */
    if (flag)
        ;
    else /* else written to the main page */
        printf("Wrong username or password\n");
    
    return flag; 
}

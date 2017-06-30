/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_5_strncmp.c   
 *@compare nth characters from the 2nd string and 1st string.
 *  
 *Author       - Rahul Patel 
 *   
 ******************************************************************************* 
 *           
 *History 
 *             
 *Aug/09/2016, Rahul P  
 *                                    
 *Aug/09/2016, Rahul P, Created
 * 
 *******************************************************************************/ 
 #include<stdio.h>

    int mystrncmp(char* ,int ,char*);   /* compare nth char from 1st and 2nd string */

int main(void)
{
    char str1[100];   /* store first string */
    char str2[50];   /* store second string */
    int ch;          /* number of character */
    int flag;        /* store flag value */

    printf("Enter 1st string\n");
    scanf("%s",str1);

    printf("Enter 2nd string\n");
    scanf("%s",str2);

    printf("number of char \n");
    scanf("%d",&ch);

    flag = mystrncmp(str1, ch, str2);
    
    if ( flag == 0 )
        printf( "string compare\n");
    else if ( flag == -1)
        printf("string2 is greater than sring1\n");
    else 
        printf("string1 is greater than string2\n");

    return 0;
}

/* strend: is 2nd string present return 1,otherwise 0 */

int mystrncmp(char* str1, int ch, char* str2)
{
    int i,j;  /* counting purpose */

    for( i = 0; i < ch; i++) {
        if( str1[i] != str2[i] ) {
            if ( str1[i] < str2[i] )
                return -1;
            else
                return 1;
        }
    }
    return 0;
            
}

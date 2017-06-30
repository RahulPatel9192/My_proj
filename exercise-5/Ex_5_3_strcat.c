/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_3_strcat.c   
 *@strcat() function concat two string.
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

void mystrcat(char* ,char*);   /* concat two string */
int main(void)
{
    char str1[50];   /* store first string */
    char str2[50];   /* store second string */

    printf("Enter 1st string\n");
    scanf("%[^\n]",str1);

    printf("Enter 2nd string\n");
    scanf(" %[^\n]",str2);

    mystrcat(str1, str2);
    printf("%s\n",str1);

    return 0;
}

/* mystrcat: take two string and concat it and return the first string address */

void mystrcat(char* s1, char* s2)
{

    for( ; *s1; s1++);   /* finding length of the string1*/

    while( (*s1++ = *s2++) );
    *s1='\0';
}

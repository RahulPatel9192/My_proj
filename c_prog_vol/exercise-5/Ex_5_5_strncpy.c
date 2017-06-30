/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_5_strncpy.c   
 *@copy the nth character from the 2nd string to 1st string.
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

    void mystrncpy(char* ,int ,char*);   /* copy nth char from 1st to 2nd string */

int main(void)
{
    char str1[100];   /* store first string */
    char str2[50];   /* store second string */
    int ch;          /* number of character */

    printf("Enter 1st string\n");
    scanf("%s",str1);

    printf("Enter 2nd string\n");
    scanf("%s",str2);

    printf("number of char \n");
    scanf("%d",&ch);

    mystrncpy(str1, ch, str2);
    
    printf("string: %s\n",str1);

    return 0;
}

/* strend: is 2nd string present return 1,otherwise 0 */

void mystrncpy(char* str1, int ch, char* str2)
{
    int i,j;  /* counting purpose */

    for( i = 0; i < ch; i++) 
        str1[i] = str2[i];
        str1[i] = '\0';
}

/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_4_strend.c   
 *@strend check if the second string is at end of the first string or not 
    if present retrun 1,otherwise 0.
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

    int strend(char* ,char*);   /* check 2nd string is present at the end of 1st string */

int main(void)
{
    char str1[20];   /* store first string */
    char str2[20];   /* store second string */
    int flag;        /* string is present or not */
    printf("Enter 1st string\n");
    scanf("%s",str1);

    printf("Enter 2nd string\n");
    scanf("%s",str2);

    flag = strend(str1, str2);

    if ( flag == 1) 
        printf("string2 is present at the end of string1\n");
    else
        printf("string is not present\n");

    return 0;
}

/* strend: is 2nd string present return 1,otherwise 0 */

int strend(char* str1, char* str2)
{
    int i,j;  /* counting purpose */
    int s1;   /* length of string1 */
    int s2;   /* length of string2 */

    for( s1 = 0; str1[s1]; s1++ );  /* length of string 1 */
    for( s2 = 0; str2[s2]; s2++ );  /* length of string 2 */

    for ( ;s2 >= 0; s2--,s1-- ) {
        if( str1[s1] != str2[s2])
            return 0;
    }
    if(str1[s1+1] == str2[s2+1])
    return 1;
    

} 

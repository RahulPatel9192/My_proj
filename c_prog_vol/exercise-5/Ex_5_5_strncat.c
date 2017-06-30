/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_5_strncat.c   
 *@concat two stirngup to n number of characters
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

    void mystrncat(char* ,int ,char*);   /* concat two string */
int main(void)
{
    char str1[20];   /* store first string */
    char str2[20];   /* store second string */
    int nch;         /* number of characters */

    printf("Enter 1st string\n");
    scanf("%s",str1);

    printf("Enter 2nd string\n");
    scanf("%s",str2);

    printf("Enter number of characters\n");
    scanf("%d",&nch);


    mystrncat(str1, nch, str2);
printf("%s\n",str1);
    return 0;
}

/* mystrncat: take two string and concat it upto n number of characters */

void mystrncat(char* s1, int n, char* s2)
{
    int i,j;  /* counting purpose */
    
    for( i=0; *s1; s1++);   /* finding length of the string1*/
    
    j=0;
    while(j < n) {
        *s1++ = *s2++;
        j++;
    }
    *s1='\0';
    

}

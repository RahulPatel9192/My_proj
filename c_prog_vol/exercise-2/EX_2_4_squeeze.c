/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description:  
 * Squeeze(string_1,string_2).c   
 * @Squeeze deletes each character in string_1 that matches any character in the string_2.
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P (Added comments)
 *                      
 * Aug/03/2016, Rahul P, Created
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<string.h>
#include<stdint.h>

/*squeeze() function removing an all char in string_1 which are present in string_2*/

void Squeeze(char* string_1, char* string_2)
{
    int s1,s2;         /*using for counting element */ 

    for( s1 = 0; string_1[s1] ; s1++ ) {
      
       for ( s2 = 0 ;string_2[s2] ; s2++ ) {
       
           if( string_1[s1] == string_2[s2] ) {
             strcpy( string_1+s1, string_1 +s1+ 1 );
             s1--;
           }
       }
    }

    printf("After complet s1= %s\n",string_1);
}


int main(void)
{
    char string_1[10]; /* store 1st string*/
    char string_2[10]; /* store 2nd string*/

    printf("Enter the 1st string \n");
    scanf("%s",string_1);

    printf("Enter the 2nd string \n");
    scanf("%s",string_2);

    Squeeze(string_1,string_2);

    return 0;
}

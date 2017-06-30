/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_1_22_fold.c   
 * @A program is to fold long input lines into two or more shorter lines after the last non-blank
 * character that occurs before the n-th column of input.
 * 
 *   
 * Author       - Rahul Patel 
 *    
 ******************************************************************************* 
 *            
 * History 
 *           
 * Aug/10/2016, Rahul P  
 *                                     
 * Aug/10/2016, Rahul P, Created
 * 
 *********************************************************************************/

#include<stdio.h>

#define LENGTH 10       /* Length of the folded line */ 
#define MAXVALUE 100    /* size of input string */
int main(void)
{
    char string[MAXVALUE];      /* input string */
    int count = -1;             /* counting character */
    int ele;                    /* counting elements */

    printf("Enter string: \n");
    scanf("%[^\n]",string);

    for( ele = 0; string[ele]; ele++ ) {
        count++;
        if( count == LENGTH) {              /* equal if folded line size are same */
            if(string[ele+1] != ' ' && string[ele+1] != '\t' ) {         /* check whwther the  space or tab is present or not */
                printf("\n");
                ele--;
                count = -1;
            }
            else {
                while( string[++ele] == ' ' || string [++ele] == '\t');
                putchar(string[ele]);
                printf("\n");
                count = -1;
            }
        }
        else 
            putchar (string[ele]);
    }

    printf("\n");

    return 0;
}

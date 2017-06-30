/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_6_9_isupper.c   
 *@Functions like isupper can be implemented to save space or to save time. Explore both
 *  possibilities.
 * 
 * 
 *  
 *Author       - Rahul Patel 
 *   
 ******************************************************************************* 
 *           
 *History 
 *             
 *Aug/12/2016, Rahul P  
 *                                    
 *Aug/12/2016, Rahul P, Created
 * 
 *******************************************************************************/ 

#include<stdio.h>
#include<ctype.h>

int myisupper(char );       /* check if character is upper or not */

int main(void)
{

    char ch;     /* check character */
    int flag;    /* checkin for upper case */

    printf("Enter char: \n");
    scanf("%c",&ch);

    if( isupper(ch) )
        printf("uppercase\n");
    else
        printf("lowercase\n");

    /*
       flag = myisupper(ch);

       if( flag )
       printf("uppercase\n");
       else
       printf("lowercase\n");

*/

    return 0;
}

int myisupper(char ch)
{

    if( ch >='A' && ch <= 'Z')
        return 1;
    else
        return 0;
}

/* isupper function is good for saving time but not for memory saving because of header file size */

/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_11_getop.c   
 * @getop() function is here which is geting operand.
 * 
 *   
 * Author       - Rahul Patel 
 *    
 ******************************************************************************* 
 *           
 * History 
 *              
 * Aug/08/2016, Rahul P  
 *                                   
 * Aug/08/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>
#include"Ex_4_11_calc_h.h"


/* getop: get next character or numeric operand */

int getop(char s[])
{
    int i, c;
    static int temp;      /* solution for theis exercise take static variable */

    if(temp != 0 ) {
        c = temp;
        temp = 0;
    }

    printf("c-%c\n",c);
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')    /*If not a number*/
        return c;

    i = 0;

    if (isdigit(c))        /* Collect integer part */
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')    /*collecting fractional part */
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';

    if (c != EOF)
        temp = c;
    return NUMBER;
}




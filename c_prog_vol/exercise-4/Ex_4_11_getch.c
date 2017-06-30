/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_11_getch.c   
 * @In this file getch() and ungetch() functions are present
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


/* Global variable for getch() Function */
/****************************************************************/
    char buf[BUFSIZE];    /* buffer for ungetch */
    int bufp = 0;         /* next free position in buf */
/****************************************************************/

int getch(void)       /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)    /* Push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}



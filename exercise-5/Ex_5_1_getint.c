/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_1_getint.c   
 *@getint treats a + or - not followed by a digit as a valid representation of zero. 
 * Fix it to push such a character back on the input.
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
#include<ctype.h>

#define BUFSIZE 100     /* definr maximum limit for buffer*/

/* Global variable for getch() Function */
/****************************************************************/
    char buf[BUFSIZE];    /* buffer for ungetch */
    int bufp = 0;         /* next free position in buf */
/****************************************************************/

        int getch(void);     /* take charecter by charecte from input */ 
        void ungetch(int);   /* using push-back character */
        int getint(int *);    /* Take string as a input and gives integer */

int main(void)
{
    int n,i,SIZE,val;
    int array[SIZE];

    printf("Enter sizeof arrray \n");
    scanf("%d",&SIZE);
    printf("Enter array \n");
   
    /* changes here by me */
    for (n = 0; n < SIZE; n++) {
        getint(&array[n]);
        printf("%d ",array[n]);
        //printf("%d ",val ?array[n] : 0);    
    } 
   /* 
    for (n = 0; n < SIZE; n++) {
        printf("%d ",array[n]);
    }*/

    printf("\n");

    return 0;
}

/* get integer */

int getint(int *pn)
{
    int c=0;                   /* store integer */
    int sign;                /* store sign (+ve or -ve) */

    while (isspace(c = getch()));      /* skip white space */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {      /* it is not a number */
       //ungetch(c);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    if ( !isdigit(c) ) {
         if (sign == -1)
            ungetch('-');
         else
             ungetch('+');
            ungetch(c);
         return 0;
    }
    
    for (*pn = 0; isdigit(c); c = getch() )
        *pn = 10 * *pn + (c - '0');


    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

/* get a (possibly pushed-back) character */

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input*/

void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

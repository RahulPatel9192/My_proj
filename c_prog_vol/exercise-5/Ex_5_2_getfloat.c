/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_2_getfloat.c   
 *@getfloat function take only float values from input
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
        int getfloat(double *);    /* Take string as a input and gives integer */

int main(void)
{
    int n,i,SIZE;
    double array[SIZE];

    printf("Enter sizeof arrray \n");
    scanf("%d",&SIZE);
    printf("Enter array \n");
    
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);


    for( i=0; i<SIZE; i++) {
        printf("%lf ",array[i]);
    }
    printf("\n");


    return 0;
}

/* get a float numbers */

int getfloat(double *p)
{
    double val,power;
    int c,sign;

    while( isspace (c=getch()) );   /* check whether space or not*/

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' ) {
        ungetch(c);
        return 0;
    }

    sign = (c == '-')? -1: 1;

    if(c == '+' || c == '-' )
        c = getch();

    for ( val = 0.0; isdigit(c); c=getch() ) 
            val = 10.0 * val + (c - '0');

    if ( c == '.' )
        c = getch();
    else {
        ungetch(c);
        return 0;
    }

    for ( power = 1.0; isdigit(c); c=getch() ) {
            val = 10.0 * val + (c - '0');
            power *= 10;
    }

    *p = (sign * val) / (power);

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



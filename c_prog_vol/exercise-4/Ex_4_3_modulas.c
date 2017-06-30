/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_3_modulas.c   
 * @modifie calculater program for % operator.
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
#include<stdlib.h>
#include<math.h>

#define MAXOP 100      /* max size of operand or operator */
#define MAXVAL 100    /* max value of depth stack */
#define NUMBER '0'    /* signal that a number was found */
#define BUFSIZE 100

/* Global variable for getch() Function */
/****************************************************************/
    char buf[BUFSIZE];    /* buffer for ungetch */
    int bufp = 0;         /* next free position in buf */
/***************************************************************/

/* Global variable for push(),pop() function*/
/*************************************************************/
    int sp = 0;  /*next free stack position*/
    double val[MAXVAL];  /* value stack*/
/*************************************************************/

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */

int main(void)
{
    int type;          /*Which type of data is present numeric or sign*/
    double op2,op1;        /* operand store*/
    char s[MAXOP];     /* operand store in ascii format */

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 > 0 && op1 > 0) {
                    push(fmod(pop(),op2));
                }
                else
                    printf("error: negative number\n");
                break;
            case '\n':
                printf("ans-%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}



/* push: push f onto value stack */

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

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


/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')    /*If not a number*/
        return c;

    i = 0;

    if (isdigit(c) || c == '-')        /* Collect integer part */
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')    /*collecting fractional part */
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}



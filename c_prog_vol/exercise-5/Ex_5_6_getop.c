/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_5_6_getop.c   
 * @geting number or option from the calculater 
 * 
 *   
 * Author       - Rahul Patel 
 *  
 ******************************************************************************** 
 *            
 * History 
 *              
 * Aug/09/2016, Rahul P  
 *                                     
 * Aug/09/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100      /* max size of operand or operator */
#define MAXVAL 100    /* max value of depth stack */
#define NUMBER '0'    /* signal that a number was found */
#define BUFSIZE 100

/* Global variable for getch() Function */
/****************************************************************/
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */
/***************************************************************/


int getop(char []);
void push(double);
double pop(void);


/* reverse Polish calculator */

int main(void)
{
    int type;          /*Which type of data is present numeric or sign*/
    double op2;        /* operand-2 store*/
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


int sp = 0;  /*next free stack position*/
double val[MAXVAL];  /* value stack*/  

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
int getop(char* s)
{
    int i, c;
    while ((*(s+0) = c = getch()) == ' ' || c == '\t');
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')    /*If not a number*/
        return c;

    i = 0;
    
    if (isdigit(c)) {        /* Collect integer part */
        i++;
        while (isdigit(*(s+i) = c = getch()));
    }
            
    if (c == '.') {   /*collecting fractional part */
        i++;
        while (isdigit(*(s+i) = c = getch()));
    }

    *(s+i) = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_5_libfun.c   
 * @Add lib function like sin,exp,pow...
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

/*global variable forr pop and push functions  */
/***************************************************************/
    int sp = 0;  /*next free stack position*/
    double val[MAXVAL];  /* value stack*/
/****************************************************************/

int getop(char []);   /*getop() used to getting operand */
void push(double);    /* push operand to the stack  */
double pop(void);     /* Poping the operand to the stack */
void clearsp();  /* clear stack */



/* reverse Polish calculator */

int main(void)
{
    int type;          /*Which type of data is present numeric or sign*/
    double op2,op1;        /* operands store*/
    char s[MAXOP];     /* operand store in ascii format */
    char ch;           /* store chararacter */

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:                /* check number is present or not */                        
                push(atof(s));
                break;
            case '+':                   /* addition */
                push(pop() + pop());
                break;
            case '*':                   /* Multiplication */
                push(pop() * pop());
                break;
            case '-':                   /* Subtratction */
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':                  /* Division */
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case 'p':                    /* Print first value of stack */
                printf("ele- %lf\n",val[sp]);
                break;
            case 's':                   /* swaping first two element in stack  */
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c':                /* clear stack */
                clearsp();
                break;
            case 'd':               /* Duplicate first element */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 'o':               /* Power function */
                push( pow(pop(), pop()) );
                break;
            case 'e':             /* Exponent value */
                push( exp(pop()) );
                break;
            case 'i' :         /* Sin value of the number */
                push( sin(pop()) );
                break;
            case '\n':          /* enter detect  */
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
    if (!isdigit(c) && c != '.')    /*If not a number*/
        return c;

    i = 0;

    if (isdigit(c))        /* Collect integer part */
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')    /*collecting fractional part */
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* clear stack pointer */

void clearsp()
{
    sp = 0;
    val[sp] = 0;
    printf("Clear stack....\n");
}

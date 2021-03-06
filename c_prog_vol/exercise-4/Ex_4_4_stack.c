/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_4_modulas.c   
 * @Add commend to print top element of stack and swap top two element of stack.
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
            case 'p':
               /* op2 = pop();
                printf("op2- %lf\n",op2);
                printf("first elememnt:- %.8g\n",op2);
                push(op2);*/
                printf("ele- %lf\n",val[sp]);
                break;
            case 's':
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c':
                clearsp();
                break;
            case 'd':
                op2 = pop();
                push(op2);
                push(op2);
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

void clearsp()
{
sp = 0;
val[sp]=0;
printf("Clear stack....\n");
}

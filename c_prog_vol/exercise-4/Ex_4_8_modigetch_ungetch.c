/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_8_modigetch_ungetch.c   
 * @getch() and ungetch() push only one character
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
#include<string.h>

#define MAXOP 100      /* max size of operand or operator */
#define MAXVAL 100    /* max value of depth stack */
#define NUMBER '0'    /* signal that a number was found */
#define BUFSIZE 100

/* Global variable for getch() Function */
/****************************************************************/
    char buf[BUFSIZE];    /* buffer for ungetch */
    int bufp = 0;         /* next free position in buf */
/****************************************************************/

/*global variable forr pop and push functions  */
/****************************************************************/
    int sp = 0;  /*next free stack position*/
    double val[MAXVAL];  /* value stack*/
/****************************************************************/

    

int getop(char []);   /*getop() used to getting operand */
void push(double);    /* push operand to the stack  */
double pop(void);     /* Poping the operand to the stack */

/* reverse Polish calculator */

int main(void)
{
    int type;              /*Which type of data is present numeric or sign*/
    double op2,op1=0;        /* operands store*/
    char s[MAXOP];         /* operand store in ascii format */
    char ch;               /* store chararacter */
  //  struct key_value obj[26];  /* Structure of array */
    double recent_value = 0;          /* most recently printed value */

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
                    push( pop() / op2 );
                else
                    printf("error: zero divisor\n");
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

    if( bufp != 0 )
        return ( buf[--bufp] );
    else
        return getchar();
}

void ungetch(int c)    /* Push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp] = c;
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




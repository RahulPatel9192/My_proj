/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_5_6_getline.c   
 * @make getline fun using pointer concept.
 *   
 * Author       - Rahul Patel 
 *    
 ******************************************************************************* 
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
#include<math.h>
#include<string.h>

#define MAXOP 100     /* max size of operand or operator */
#define MAXVAL 100    /* max value of depth stack */
#define NUMBER '0'    /* signal that a number was found */
#define BUFSIZE 100   /* maximum Buffer size */
#define MAXLINE 100   /* maximum limit for array */

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

/* global varibals for getline() function*/    
/****************************************************************/
    int li = 0;            /* index */   
    char line[MAXLINE];    /* store character */
/****************************************************************/

int getop(char []);   /*getop() used to getting operand */
void push(double);    /* push operand to the stack  */
double pop(void);     /* Poping the operand to the stack */
void mygetline(void); /* getline() function to take whole string */

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

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
 if(line[li] == '\0')
        mygetline();

    while ((s[0] = c = line[li++]) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')    /*If not a number*/
        return c;

    i = 0;

    if (isdigit(c))        /* Collect integer part */
        while (isdigit(s[++i] = c = line[li++]));

    if (c == '.')    /*collecting fractional part */
        while (isdigit(s[++i] = c = line[li++]));

    s[i] = '\0';

    return NUMBER;
}

/* getline: get character or numeric operand from the string and return length of the string */

void mygetline()
{
    int c,i=0;
    while( (c = getchar()) != EOF && c != '\n' ) {
    *(line+i) = c;
    i++;
    }

    if ( c == '\n' ) {
        *(line+i) = c;
        i++;
    }
    *(line+i) = '\0';
}

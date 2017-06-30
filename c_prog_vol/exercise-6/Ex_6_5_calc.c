/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_6_5_calc.c   
 * @Rewrite the postfix calculator to use scanf and/or sscanf to do the input
 * and number conversion.
 * 
 *  Author       - Rahul Patel 
 *   
 ******************************************************************************** 
 *            
 * History 
 *             
 * Aug/12/2016, Rahul P  
 *                                    
 * Aug/12/2016, Rahul P, Created
 * 
 ********************************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100      /* max size of operand or operator */
#define MAXVAL 100    /* max value of depth stack */
#define NUMBER '0'    /* signal that a number was found */
#define BUFSIZE 100

/* Global variable for push and pop Function */
/****************************************************************/
    int sp = 0;  /*next free stack position*/
    double val[MAXVAL];  /* value stack*/  
/***************************************************************/


void push(double);     /* pushing character to the stack */

double pop(void);      /* poping charater to the stack */


/* reverse Polish calculator */

int main(void)
{
    char *cpointer;    /* char pointer */
    double op,op2;     /* operand store*/
    char s[MAXOP];     /* operand store in ascii format */
    char temp[MAXOP];  /* store input string */
    char end ='\0';    /* end point */

    while ((scanf("%s%c",s,&end)) == 2) { /* changes here */
        if (sscanf(s,"%lf",&op) ==1)     /* changes here */
            push(op);
        else if (sscanf(s,"%s",temp)) {
            for(cpointer = temp; *cpointer; cpointer++) {
                switch (*cpointer) {
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

                    default:
                        printf("error: unknown command %s\n", s);
                        break;
                }

            }

            if(end == '\n')
                printf("ans-%.8g\n", pop());
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


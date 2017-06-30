/*Copyright(c) <2016>, Volansys Technologies 
 *  * 
 * Description: 
 * @Ex_8_4_reverpolish_calc.c   
 * @Make revercepolish calculator using command line argument
 * 
 * 
 * Author       - Rahul Patel 
 *   
 ********************************************************************************* 
 *           
 * History 
 *              
 * Aug/17/2016, Rahul P  
 *                                     
 * Aug/17/2016, Rahul P, Created
 *                
 ********************************************************************************/



#include<stdio.h>
#include<ctype.h>

#define MAXOP 100
#define MAXVAL 100

void push(int );
int pop(void);

/*global varibles for push and pop */
/***************************************************/
int sp = 0;  /*next free stack position*/
double val[MAXVAL];  /* value stack*/
/**************************************************/

/* reverse Polish calculator */

int main(int argc, char **argv)
{
    char type;          /*Which type of data is present numeric or sign*/
    double op2;        /* operand-2 store*/
    char s[MAXOP];     /* operand store in ascii format */
    int i = 1;

    while (argc > 1) {    /* changes here */

        if(isdigit(*argv[i]))  /* changes here */
            type = '0';
        else 
            type = *argv[i];

        switch (type) {
            case '0':
                push(atoi(argv[i])); /* changes here */
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x': /* Multiplication */
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
                printf("error: unknown command \n");
                break;
        }
        i++;
        argc--;
    }
    printf("ans-%d\n", pop());
    return 0;
}



/* push: push f onto value stack */

void push(int f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %d\n", f);
}


/* pop: pop and return top value from stack */
int pop(void)
{

    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}   

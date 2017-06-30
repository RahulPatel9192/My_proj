/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_11_main.c   
 * @main program is here
 * 
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
#include"Ex_4_11_calc_h.h"
/* reverse Polish calculator */

int main(void)
{
    int type;              /*Which type of data is present numeric or sign*/
    double op2,op1=0;        /* operands store*/
    char s[MAXOP];         /* operand store in ascii format */

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




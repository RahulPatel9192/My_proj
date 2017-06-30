/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_11_stack.c   
 * @In this file push ,pop releted functions are Here.
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
#include"Ex_4_11_calc_h.h"


/*global variable for pop and push functions  */
/****************************************************************/
    int sp = 0;  /*next free stack position*/
    double val[MAXVAL];  /* value stack*/
/****************************************************************/


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
    if (sp > 0) { 
        return val[--sp];
    }
    
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


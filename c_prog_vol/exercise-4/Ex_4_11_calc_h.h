/*Copyright(c) <2016>, Volansys Technologies
 * 
 * Description:
 * @Ex_4_11_calc_h.h	
 * @In this all Header files for calc programme are here
 *    
 * In this Common_Header file we add all header files which we will use in our
 * project/Exercise.
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
 * Aug/08/2016, Rahul P,
 *
 ******************************************************************************/

#ifndef Ex_4_11_calc_h
#define Ex_4_11_calc_h

#define MAXOP 100    /* max size of operand or operator */
#define MAXVAL 100   /* max value of depth stack */
#define NUMBER '0'   /* signal that a number was found */
#define BUFSIZE 100  /* Buffer size for ungetch and getch function */

int getop(char []);   /* getop() used to getting operand */
void push(double);    /* push operand to the stack  */
double pop(void);     /* Poping the operand to the stack */
int getch(void);      /* take charecter by charecter from input */
void ungetch(int);    /* using for push_back character */


#endif  /* '#endif' of Ex_4_11_calc_h.h */

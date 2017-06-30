/*Copyright(c) <2016>, Volansys Technologies 
 *  *  * 
 * Description: 
 * @addDemo.c   
 * @This program is written for understanding of static linking.
 *  here we write simple adtiond and subtraction,multiplication 
 *  and division programs.
 * 
 *  
 * Author       - Rahul Patel 
 *   
 *********************************************************************************** 
 *            
 * History 
 *              
 * Aug/22/2016, Rahul P  
 *                                          
 * Aug/22/2016, Rahul P, Created
 * 
 *********************************************************************************/

#include<stdio.h>
#include "heymath.h"

int main(void)
{
    int x = 20; /* 1st integer */
    int y = 10; /* 2nd integer */

    printf("\n%d + %d = %d\n", x, y, add(x,y)); /* call add function */
    printf("\n%d - %d = %d\n", x, y, sub(x,y)); /* call sub function */
    printf("\n%d * %d = %d\n", x, y, mul(x,y)); /* call mul function */
    printf("\n%d / %d = %d\n", x, y, div(x,y)); /* call div function */

    return 0;

}

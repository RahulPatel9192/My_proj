/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Ex_4_14_swap.c   
 * @creat one macro which convert any type of variable
 *   
 * Author       - Rahul Patel 
 *   
 ***************************************************************************** 
 *            
 * History 
 *             
 * Aug/05/2016, Rahul P  
 *                                    
 * Aug/05/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>

#define swap(type,x,y) { type t; \
                      t=x; \
                      x=y; \
                      y=t; }

int main(void)
{
   int num1,num2;  /* two integer value  */

   printf("Enter 1st number: \n");
   scanf("%d",&num1);

   printf("Enter 2nd number: \n");
   scanf("%d",&num2);

   swap(int,num1,num2);

   printf("Swaped Result num1- %d num2- %d\n",num1,num2);



    return 0;
}

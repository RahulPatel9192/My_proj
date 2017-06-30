/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Bit_count.c   
 * @In this we count how many 1's in binary of that number
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P  (Added comments)
 *                      
 * Aug/03/2016, Rahul P, Created  
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<stdint.h>

int main(void)
{
   uint32_t number; /*storing the number*/
   uint32_t count;  /*countuing purpose*/
   uint32_t i;

   printf("Enter number \n");
   scanf("%d",&number);
  
   for ( count=0 ; number; number&=(number-1) )
   count++;

   printf("Number of 1's in given number is %u \n",count);
   return 0;
}

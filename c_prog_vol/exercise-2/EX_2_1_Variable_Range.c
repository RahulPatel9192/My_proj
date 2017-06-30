/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Variable_Range.c   
 * @In this we print range of variable
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/03/2016, Rahul P 
 *                      
 * Aug/03/2016, Rahul P, Created (description) 
 * 
 ******************************************************************************/ 

#include <stdio.h>


int main(void)
{
    printf("For char:- \n");
    printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));
    
    printf("\n");
    printf("For Short:- \n");
    printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

    printf("\n");
    printf("For Integer:- \n");
    printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

    printf("\n");
    printf("For Long:- \n");
    printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

    /* Unsigned Maximum Values */

    printf("\n");
    printf("Unsigned Max values....\n");
    printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n",(unsigned long)~0);




return 0;
}

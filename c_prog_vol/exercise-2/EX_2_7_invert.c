/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @invert.c   
 * @function invert(number,pos,nbit) that returns number with the nbit bits that begin at position pos
inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P (Added comments)
 *                      
 * Aug/03/2016, Rahul P, Created  
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<stdint.h>

/* Invert(number, pos, nbit) will invert the number of  nbit started from pos position */

int Invert(uint32_t number, uint32_t pos, uint32_t nbit)
{
    return (number ^ (~(~0 << nbit)<< pos));
}

int main(void)
{
    uint32_t number; /* hold the number which user enter*/
    uint32_t pos;    /*hold the position if the bit at which we start to converted*/
    uint32_t nbit;   /*number of bits we convert*/

    printf("Enter number: \n");
    scanf("%d",&number);

    printf("Enter position: \n");
    scanf("%d",&pos);

    printf("Enter bits u want to change: \n");
    scanf("%d",&nbit);

    printf("Final Result %d\n",Invert(number,pos,nbit));
    return 0;
}

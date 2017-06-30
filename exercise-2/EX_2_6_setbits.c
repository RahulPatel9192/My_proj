/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @setbits.c   
 * @A function setbits(num1,pos,nbit,num2) that returns num1 with the nbit bits that begin at position
 * pos set to the rightmost nbit bits of num2, leaving the other bits unchanged.
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P  (Added comments)
 *                      
 * Aug/03/2016, Rahul P, Created (description) 
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<stdint.h>

/*setbit(num1,pos,nbit,num2) set the nbit of num1 which started with pos to rightmost of num2's nbit */

int setbit(uint32_t num1, uint32_t pos ,uint32_t nbit ,uint32_t num2)
{
    uint32_t bits;
    uint32_t cleanbit,x;
    
    bits= ~ ( ~ 0 << nbit) & num2;                                        /*getting n number of bits from number2*/
    cleanbit = ( ~ 0 << pos | ~ ( ~ 0 << ( pos - nbit + 1 ) ) ) & num1 ; /*clean n bits from pos of num1*/
    return ( cleanbit | ( bits << (pos - nbit + 1 ) ) );                 /*set bits in num1*/
}

int main(void)
{
    uint32_t num1;  /* number1 */
    uint32_t pos;   /* position of bit */
    uint32_t nbit;  /* number of bits */
    uint32_t num2;  /* number2 */

    printf("Enter number1: \n");
    scanf("%d",&num1);

    printf("Enter position: \n");
    scanf("%d",&pos);

    printf("Enter number of bits: \n");
    scanf("%d",&nbit);

    printf("Enter number2: \n");
    scanf("%d",&num2);

    printf("Answer is %d \n",setbit(num1,pos,nbit,num2));
    return 0;
}

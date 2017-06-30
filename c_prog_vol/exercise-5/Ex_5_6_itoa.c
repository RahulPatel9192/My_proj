/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Ex_5_6_itoa.c   
 * @itoa function convert integer to ASCII.   
 * 
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/09/2016, Rahul P 
 *                      
 * Aug/09/2016, Rahul P, Created (description) 
 * 
 ******************************************************************************/ 
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<limits.h>

/*itoa() converts any integer number in to ascii */ 


void itoa(uint32_t number,char* string)
{
    
    int i,sign,j;
    char c;

    if ((sign = number) < 0) /* record sign */
        number = -number;   /* make n +ve */

    i = 0;
    do {
       j = abs(number % 10);
       printf("j %d\n",j);
       *(string+i) = j + 48;
       i++;
       }while((number /=10));   

    if(sign < 0)
    *(string+i) = '-';
    i++;

    /*checking for width*/


    *(string+i) = '\0';
    
    printf("%s",string);
    /*Reverse the string*/

    j=strlen(string)-1;

    for( i = 0; j >= i; i++, j-- ) { 
       c = *(string+i);
       *(string+i) = *(string+j);
       *(string+j) = c;
    }

   printf("string- %s\n",string);


}

int main(void)
{
    
    uint32_t number;  /*hold number which user enter*/
    char string[20];  /*ascii format of integer*/

    printf("Enter integer\n");
    scanf("%d",&number);
    
    itoa(number,string);

//  itoa(INT_MIN,string);
 
   return 0;
}


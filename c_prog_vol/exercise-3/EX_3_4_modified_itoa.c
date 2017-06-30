/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @updated_itoa.c   
 * @In this solve the probleam of our own itoa() function.   
 * 
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P (Added comments)
 *                      
 * Aug/04/2016, Rahul P, Created (description) 
 * 
 ******************************************************************************/ 
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<limits.h>

/*itoa() converts any integer number in to ascii. this is a modified version in which we can also convert minimum integer number into ascii format */


void itoa(uint32_t number,char string[])
{
    
    int i,sign,j;
    char c;

    sign = number;
    i = 0;

    do {
       j = abs(number % 10);    /*1st solution*/ 
       string[i++] = j + 48;
       }while((number /=10));   

    if(sign < 0)
    string[i++] = '-';

    /*checking for width*/


    string[i] = '\0';
    

    /*Reverse the string*/

    j=strlen(string)-1;

    for( i = 0; j >= i; i++, j-- ) { 
       c = string[i];
       string[i] = string[j];
       string[j] = c;
    }

   printf("string- %s\n",string);


}

int main(void)
{
    
    uint32_t number;  /*hold number which user enter*/
    char string[20];  /*ascii format of integer*/

    printf("Enter integer\n");
    scanf("%d",&number);
  //  itoa(number,string);

  itoa(INT_MIN,string);
 
   return 0;
}


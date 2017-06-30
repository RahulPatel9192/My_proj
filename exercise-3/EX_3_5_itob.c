/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @itob.c   
 * @In this we creat one function called itob(number,base,string), which convert any number into desierd base  
 *  system and store into string.
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P  (Added comments)
 *                      
 * Aug/04/2016, Rahul P, Created  
 * 
 ******************************************************************************/ 
#include<stdio.h>
#include<string.h>
#include<stdint.h>

/*itob() converts any integer to desierd base and give as a string   */

void itob(uint32_t number,uint32_t base,char string[])
{
    
    int i,sign,j; 
    char c;

    if( (sign = number) < 0)
    number = -number;
    i = 0;

    do {
    j = number % base; 
      if(base > 10)
        string[i++] = j +'a'-10;
      else
        string[i++] = j + 48;
    }while( (number /= base) > 0);

    if(sign < 0)
      string[i++] = '-';
      string[i] = '\0';

/*Reverse the string*/

    j=strlen(string)-1;

    for(i=0;j>=i;i++,j-- ) { 
       c = string[i];
       string[i] = string[j];
       string[j] = c;
    }

   printf("string- %s\n",string);


}
int main(void)
{
    
    uint32_t base,number; /*base and number store*/
    char string[20];     /*final output is store*/

    printf("Enter integer\n");
    scanf("%d",&number);

    printf("Enter the base \n");
    scanf("%d",&base);
    
    if( base > 16)
        printf("Please enter correct base i.e upto 16\n");

    itob(number,base,string);
    return 0;
}


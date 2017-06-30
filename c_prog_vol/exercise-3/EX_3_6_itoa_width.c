/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @itoa.c   
 * @In this we creat one function called itoa(number,string,width) which convert integer to ascii values   
 * and padded with width.
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

/* itoa() converts integer to ascii but in thi function we add left side of a number with particular width size which user want */

void itoa(uint32_t number,uint32_t width,char string[])
{
    
    int i,sign,j,z;
    char c;

    if( (sign =number) < 0)
       number = -number;
       i = 0;

    do {
       j = number % 10;  
       string[i++] = j + 48;
    }while( (number /= 10) > 0);

    if(sign < 0)
      string[i++] = '-';

    /*checking for width*/

    if(i != width) {
      z=(width-i)+1;
        for( ; i <= z; ) 
           string[i++] = ' ';
    }

    string[i] = '\0';
    

    /*Reverse the string*/

    j = strlen(string) - 1;

    for( i = 0; j >= i; i++, j-- ) { 
       c = string[i];
       string[i] = string[j];
       string[j] = c;
    }

   printf("string- %s\n",string);
}

int main(void)
{
    
    uint32_t width,number; /*width of the fiels and number store*/
    char string[20];      /*final result will store*/

    printf("Enter integer\n");
    scanf("%d",&number);

    printf("Enter the width \n");
    scanf("%d",&width);

    itoa(number,width,string);
    return 0;
}


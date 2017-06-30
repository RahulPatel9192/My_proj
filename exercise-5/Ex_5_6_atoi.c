/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_6_atoi.c   
 *@convert ASCII to integer number. 
 * 
 *  
 *Author       - Rahul Patel 
 *   
 ******************************************************************************* 
 *           
 *History 
 *             
 *Aug/09/2016, Rahul P  
 *                                    
 *Aug/09/2016, Rahul P, Created
 * 
 *******************************************************************************/ 

#include<stdio.h>
#include<ctype.h>

/* atoi: convert s to integer */
/* changes here use pointers insted of string */
int myatoi(char s[])
{
    int i, n; 
    int sign;    /* content sign*/

    for (i = 0; isspace(*(s+i)); i++);  /* skip white space */

    sign = (*(s+i) == '-') ? -1 : 1;

    if (*(s+i) == '+' || *(s+i) == '-')
        i++;

    for (n = 0; isdigit(*(s+i)); i++)
        n = 10 * n + (*(s+i) - '0');

    return sign * n;
}

int main(void)
{
    char str[20];        /* ASCII format of integer */
    int number;          /* Integer result */

    printf("Enter ASCII string\n");
    scanf("%s",str);

    number = myatoi(str);

    printf("number: %d\n",number);

    return 0;
}

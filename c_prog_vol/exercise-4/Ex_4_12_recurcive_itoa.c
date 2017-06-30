/*Copyright(c) <2016>, Volansys Technologies 
 *   
 *Description: 
 *@Ex_4_12_recursive_itoa.c   
 *@we make itoa() using recursive concept
 *  
 *Author       - Rahul Patel 
 *   
 ******************************************************************************** 
 *           
 * History 
 *             
 * Aug/05/2016, Rahul P  
 *                                    
 * Aug/05/2016, Rahul P, Created
 *                 
 ********************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*reverse() reverse the string */

void reverse(char *st)
{
	int i,j;      /* counting purpose */
	char c;       /* store character */

	j = strlen(st) - 1;

	for ( i = 0; j >= i; i++, j-- ) {
		c = st[i];
		st[i] = st[j];
		st[j] = c;
	}
}

/* itoa() function convert integer to ascii format */

void itoa(int n,char s[])
{
    static int sign;   /* store sign value*/
	static int i,j;    /* counting purpose*/
    static int count;  /* counting purpose*/

	if(n < 0) {
        sign=n;
    }
    

	if(n != 0) {
        j = abs ( n % 10 );

		s[i++] = j + 48;
        itoa( n /= 10, s );
    }

	if( sign < 0 && count == 0 ) {
		s[i++] = '-';
        count++;
    }

	s[i] ='\0';
}



int main(void)
{
	int number;      /* hold integer value */
        
	char string[20]; /* hold ascii value of the integer which user entered */
    
	printf("Enter integer\n");
	scanf("%d",&num);

    itoa(number,string);

    reverse(string);

    printf("%s\n",string);
	return 0;
}

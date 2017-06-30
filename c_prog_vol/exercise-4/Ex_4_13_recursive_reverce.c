/*Copyright(c) <2016>, Volansys Technologies 
 *   
 *Description: 
 *@Ex_4_12_recursive_reverse.c   
 *@Creat reverse() using recursive concept
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

/*reverse() function reverse the string using recursive concept*/

void reverse(char *st)
{
    static int i=0,j;  /* counting purpose */
	char c;            /* store character */
    static int len;   /* length of the string*/
    static int t;

   
    if (t == 0) {
	len = strlen(st);
    j=len-1;
    t++;
    }

	if ( j > i) {
		c = st[i];
		st[i] = st[j];
		st[j] = c;
        i++;
        j--;

        reverse(st);
	}

    st[len] = '\0';
}

int main(void)
{
        
	char string[20]; /* hold ascii value of the integer which user entered */
    
    printf("Enter string: \n");
    scanf("%s",string);

    reverse(string);

    printf("%s\n",string);
	return 0;
}

/*Copyright(c) <2016>, Volansys Technologies 
 *   
 * Description: 
 * Ex_4_2_atof_extended.c   
 * @This atof() fun converts ascii to float integer with its exponent value 
 *    
 * Author       - Rahul Patel 
 *         
 ******************************************************************************** 
 *           
 * History 
 * 
 * Aug/05/2016, Rahul P  
 *                       
 * Aug/05/2016, Rahul P, Created
 * 
 *******************************************************************************/
#include <ctype.h>
#include<stdio.h>
#include<stdint.h>

/* atof: convert string to its equvalent float value */

double atof(char s[])
{
    double val1;   /*storing float value*/
    double val;    /*store integer value*/
    int power;     /*store power*/
    int sign,j=1;  /*store sign +ve or -ve*/
    int i,k,l;     /*counting purpose*/
    int e;         /*exponant value*/

    for (i = 0; isspace(s[i]); i++);   /* skip white space */
        
    sign = (s[i] == '-') ? -1 : 1;  
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
   
    if (s[i] == 'e' || s[i] == 'E'){
        i++;
    }

    if (s[i] == '+' || s[i] == '-') {
      j = (s[i] == '-') ? -1 : 1;
      i++;
    }

    for ( k = 0; isdigit(s[i]); i++ ) {
        k = 10 * k + (s[i] - '0');
    }

    for( e = 1, l = 0; l < k; l++ ) 
        e *= 10;
    
    val1 = (( sign * val) / power );
    
    if( j < 0 )
        return ( val1 / e );
    else
        return ( val1 * e );
}



int main(void)
{
    double ans;
    char s[10];

    printf("Enter float value\n");
    scanf("%s",s);

    ans=atof(s);
    printf("ans-%lf\n",ans);

    return 0;
}

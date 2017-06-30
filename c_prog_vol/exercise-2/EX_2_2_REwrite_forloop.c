/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description:
 * @Rewrite_forloop.c   
 * @Rewrite for loop without using && and ||
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P (Added Comments)
 *                      
 * Aug/03/2016, Rahul P, Created (description) 
 * 
 ******************************************************************************/

#include<stdio.h>
#include<stdint.h>

int main(void)
{

    uint8_t s[5];   /*store string */
    uint8_t c;      /*for storing the char to stdin*/
    uint32_t i=0;   /*counting purpose */     
    uint32_t lim;   /*how many elements are in the array */

    lim = sizeof(s) / sizeof(s[0]);
   
    for( i = 0; i <= (lim-1); i++ ) {
       if( ( c = getchar()) != '\n' ) {
          if( c != EOF ) {
    	      s[i] = c;
          }
          else 
            return 0;
        }
        else 
         return 0;
       
    }       
    s[i] ='\0';

    printf("%s\n",s);

    

    return 0;
}



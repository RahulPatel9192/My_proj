/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_8_5_2_entab.c   
 * @A program entab is replaces strings of blanks by the minimum number of tabs and blanks
 * to achieve the same spacing.
 * 
 *   
 * Author       - Rahul Patel 
 *    
 ******************************************************************************* 
 *            
 * History 
 *           
 * Aug/19/2016, Rahul P  
 *                                     
 * Aug/19/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>
#include<string.h>

#define MAXVALUE 100        /* Define mmaximum size of array */
//#define SPACE 4               /* set tab space */

int main(int argc, char **argv)
{
    char string[MAXVALUE];           /* input string */
    char space = ' ';                /* containing space */
    int count = 0;
    int i;                        /* using counting purpose */
    int spaces;

    if(argc != 2) {
        printf("Error:Enter Space value\n");
        return 0;
    }

    printf("Enter string\n");
    scanf("%[^\n]",string);

    printf("before-%ld\n",strlen(string));
    spaces = atoi(argv[1]);
    /* changes here */
    for( i = 0; i< MAXVALUE || string[i]; i++ ) {      
        if(string[i] == space) {                      /* Detect space and replace space with tab */
            count++;
            if ( count == spaces ) {
           strcpy(string+i-(spaces-2), string+i+1);
            string[i-(spaces-1)] = '\t'; 
            }    
        }
    }

   printf("after-%ld\n",strlen(string));

    printf("%s\n",string);

    return 0;
}

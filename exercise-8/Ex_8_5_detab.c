/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_8_5_detab.c   
 * @detab that replaces tabs in the input with the proper number of blanks to space to
 * the next tab stop.
 * 
 *   
 * Author       - Rahul Patel 
 *    
 ******************************************************************************* 
 *            
 * History 
 *           
 * Aug/10/2016, Rahul P  
 *                                     
 * Aug/10/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>
#include<string.h>

#define MAXVALUE 100        /* Define mmaximum size of array */

int main(int argc, char **argv)
{
    char string[MAXVALUE];           /* input string */
    int i,j,k;                       /* using counting purpose */   
    int TAB;
    printf("Enter string\n");
    scanf("%[^\n]",string);
   
    if(argc != 2) {
        printf("Error: enter tab space\n");
        return 0;
    }

    TAB = atoi(argv[1]);

    printf("before-%ld\n",strlen(string));
   /* changes here */ 
    for( i = 0; i< MAXVALUE || string[i]; i++ ) {      
        if(string[i] == '\t') {                      /* Detect Tab and replace Tab with space */
           strcpy(string+i+4, string+i+1);
            for (k=i, j=0; j<TAB; j++,k++ )
                string[k] = ' ';
                i=k;
        }
    }

   // printf("after-%ld\n",strlen(string));

    printf("%s\n",string);

    return 0;
}

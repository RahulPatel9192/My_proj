/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_8_6_2_entab.c   
 * @Extend entab -m +n mean tab stops every n columns, starting at column m.
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
#define SPACE 4               /* set tab space */

int main(int argc, char **argv)
{
    char string[MAXVALUE];           /* input string */
    char space = ' ';                /* containing space */
    int count = 0;
    int i;                       /* using counting purpose */ 
    int sp = 0;  /* every n tab */
    int cnt = 0;  /* starting coloum */

    if(argc != 3) {
        printf("Error:Enter Space value\n");
        return 0;
    }

    printf("Enter string\n");
    scanf("%[^\n]",string);

   // printf("before-%ld\n",strlen(string));

    cnt = atoi(argv[1]);
    for( i = 0; i< MAXVALUE || string[i]; i++ ) {      
        if(string[i] == space) {                      /* Detect space and replace space with tab */
            count++;
            cnt++;
            if ( count == 4 ) {
           strcpy(string+i-2, string+i+1);
            string[i-3] = '\t'; 
            }    
        }
    }

//    printf("after-%ld\n",strlen(string));

    printf("%s\n",string);

    return 0;
}

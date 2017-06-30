/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_8_6_detab.c   
 * @extend detab. detab -m +n..mean spaces  every n columns, starting at column m
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
#include<stdlib.h>

#define MAXVALUE 100        /* Define mmaximum size of array */
#define TABS 4
int main(int argc, char **argv)
{
    char string[MAXVALUE];           /* input string */
    int i,j,k;                       /* using counting purpose */   
    int TAB;
     int cnt = 0, tab_cnt = 0;
    int start;

    if(argc != 3) {
        printf("Error: enter tab space\n");
        return 0;
    }
    printf("Enter string\n");
    scanf("%[^\n]",string);
   
    start = atoi(argv[1]);
    TAB = atoi(argv[2]);

    //printf("before-%ld\n",strlen(string));
    
    for( i = 0; i< MAXVALUE || string[i]; i++ ) {      
        if(string[i] == '\t') {   /* Detect Tab and replace Tab with space */
            cnt++;
            tab_cnt++;
            if( cnt >= start && tab_cnt < atoi(argv[2])) {
           strcpy(string+i+TAB, string+i+1);
        
            for (k=i, j=0; j<TAB; j++,k++ )
                string[k] = ' ';
                i=k;
                tab_cnt = 0;
            }
            else {
           strcpy(string+i+TABS, string+i+1);
        
            for (k=i, j=0; j<TABS; j++,k++ )
                string[k] = ' ';
                i=k;
            
            }
        }
    }

   // printf("after-%ld\n",strlen(string));

    printf("%s\n",string);

    return 0;
}

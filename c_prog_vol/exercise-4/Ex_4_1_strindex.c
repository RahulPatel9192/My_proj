/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_4_1_strindex.c   
 *@we find the position of the rightmost occurrence of string2 in string1, or -1 if there is none.
 *  
 *Author       - Rahul Patel 
 *   
 ******************************************************************************* 
 *           
 *History 
 *             
 *Aug/05/2016, Rahul P  
 *                                    
 *Aug/0/2016, Rahul P, Created
 * 
 *******************************************************************************/ 

#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define MAXLINE 100  /*Define macro for maxline*/

uint32_t strindex (uint8_t* string1, uint8_t* pattern )
{
    uint8_t j,k,t;      /* counting purpose */
    uint32_t index;
    uint32_t len_pattern;  /* length of pattern */
    uint32_t len_string;   /* length of string */

    len_pattern = strlen(pattern) - 1;  /* find length of the pattern */
    len_string = strlen(string1) - 1;  /* find the length of the string */
    
    for( ; len_string >= 0; len_string--) {
        if(string1[len_string] == pattern[len_pattern] ) {
            for( j = len_pattern-1, k = len_string-1; j >= 0; j--, k--) {
                if( string1[k] != pattern[j]) {
                    return k+2;
                }
            }
        }
    }                    

}

int main()
{
    uint8_t string1[MAXLINE]; /*hold string in which we want to find*/
    uint8_t pattern[MAXLINE]; /*hold pattern to serch for*/
    uint32_t index;   /*hold index number*/

    printf("Enter string \n");
    scanf("%[^\n]",string1);

    printf("Enter pattern \n");
    scanf("%s",pattern);


    index=strindex (string1, pattern);
    
    if( index < 0)
        printf("No Match found\n");
    else
        printf("Match found and index number is %d\n",index);


    return 0;
}

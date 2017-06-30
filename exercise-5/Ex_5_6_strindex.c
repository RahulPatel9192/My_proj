/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_5_6_strindex.c   
 *@we find the position of the rightmost occurrence of string2 in string1, or -1 if there is none.
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
#include<stdint.h>
#include<string.h>

#define MAXLINE 100  /*Define macro for maxline*/

uint32_t strindex (uint8_t* string1, uint8_t* pattern )
{
    printf("str-%s  p-%s\n",string1,pattern);
    uint8_t i,j,k;
    uint32_t index;

    for( i = 0; *(string1+i); i++) {
        if(*(string1+i) == *(pattern+0) ) {
            for( j=1, k=i; *(pattern+j); j++) {
                if( *(string1+k) != *(pattern+j) ) {
                    k++;
                    return i;
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

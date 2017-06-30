/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @My_strpbrk.c   
 * @ Function My_strpbrk(string_1,string_2) returns the first location in a string string_1 where any
 *   character from the string string_2 occurs, or -1 if string_1 contains no characters from string_2.
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P (Added comments) 
 *                      
 * Aug/03/2016, Rahul P, Created  
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<stdint.h>

/*My_strpbrk(string_1,string_2) gives first location of char in string_1 which are present in string_2 */

uint32_t My_strpbrk( uint8_t* string_1, uint8_t* string_2 )
{

	uint32_t s1,s2,pos=-1;  /*using for counting purpose*/
   
    for( s1 = 0; pos == -1 && string_1[s1]; s1++ ) {

       for( s2 = 0; pos == -1 && string_2[s2]; s2++ ) {
     
          if( string_1[s1] == string_2[s2] )
            pos = s1; 
        
       }  

   }

   return pos;
}



int main(void)
{

    uint8_t string_1 [10];  /*hold 1st string*/
    uint8_t string_2 [10];  /*holds 2nd string in which we write what char we find from 1st string*/
    uint32_t pos;           /* holds the position of finding char*/
    
    printf("Enter string \n");
    scanf("%s",string_1);

    printf("Enter string in  which finding char present \n");
    scanf("%s",string_2);
    
    pos=My_strpbrk(string_1,string_2);

    if(pos == -1)
    printf("There are no matching \n");
    else
    printf("Position is %d \n",pos+1);
   


    return 0;
}


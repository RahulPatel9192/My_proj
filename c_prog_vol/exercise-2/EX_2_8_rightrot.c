/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Rightrot(number,ntime).c   
 * @This function rotate the number right side for ntimes.
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P (Added comment)
 *                      
 * Aug/03/2016, Rahul P, Created  
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<stdint.h>

/* Rightrot(number,ntime) it rotate the number right side for ntimes */

uint32_t Rightrot ( uint32_t number, uint32_t ntime ) 
{
    return ( (number>>ntime) | (number << (32 - ntime) ) );
}

uint32_t main(void)
{
    uint32_t number;  /*Number which we want to enter*/
    uint32_t ntime;  /* how many times we rotate the bit that number we write here*/
    uint32_t i,ans;
    
    printf("Enter number \n");
    scanf("%d",&number);
    
    printf("How many times rotate \n");
    scanf("%d",&ntime);
    
    for( i = 31 ; i >= 0 ; i-- ) 
    printf("%d",number>>i & 1);

    printf("\n");
    
    ans = Rightrot ( number, ntime );
    
    for( i = 31 ; i >= 0 ; i-- ) 
    printf("%d",ans>>i & 1);

    printf("\n");
    return 0;
}

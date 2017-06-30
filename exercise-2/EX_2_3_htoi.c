/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @my_htoi.c   
 * @In this we convert hex string into its equvalent integer value
 *     
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P (Added comments)
 *                      
 * Aug/03/2016, Rahul P, Created (description) 
 * 
 ******************************************************************************/ 


#include<stdio.h>
#include<stdint.h>

/*This My_htoi(uint8_t* p) converts the hex string to its equvalent integer value
  this fun accecpt hex string and return integer digit.  */

int My_htoi(uint8_t* p)
{
    uint32_t hexdigit;     /*hold integer value*/
    uint32_t flag;         /*using as a flag*/
    uint32_t element=0,n=0; /*using for element counting purpose*/
    
    if( p[element]== '0' ) {
     
       element++;
         if ( p[element] == 'x' || p[element] == 'X' ) {
            element++;
         }
    }

    flag=1;
    
    for( ; flag == 1; element++ ) {
       if( p[element] >= '0' && p[element] <= '9' ) 
          hexdigit = p[element] - '0';
    
       else if( p[element] >= 'a' && p[element] <= 'z' )
          hexdigit = p[element] - 'a' + 10;
        
       else if( p[element] >= 'A' && p[element] <= 'Z' )
          hexdigit = p[element] - 'A' + 10;

       else 
       flag=0;
    
       if(flag==1)
         n=16 * n + hexdigit;
    }
    printf("%d\n",n);
    
    return n; 
    
}



int main(void)

{

    uint8_t string[10];
    uint32_t number;
    
    printf("Enter the string\n");
    scanf("%s",string);
    
    number = My_htoi(string);

    printf("Equvalent number is %d \n",number);




    return 0;
}

/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Change_lowercase.c   
 * @In this program we convert char uppercase to lowercase
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

int main(void)
{
    uint8_t uppercase;  /*Hold uppercase value*/
    uint8_t lowercase;  /*Hold lowercase value*/

    printf("Enter one cahracter: \n");
    scanf("%c",&uppercase);

    lowercase= ( uppercase >= 'A' && uppercase <= 'Z' ) ? ( uppercase + 32 ) : uppercase;
    printf("%c\n",lowercase);

    return 0;
}

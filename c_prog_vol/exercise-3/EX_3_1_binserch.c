/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Binserch.c   
 * @In this we creat one function called binserch() which is find the number in array and 
 *  give the position of that number.successfully return position, else -1.   
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P  (Added comments)
 *                      
 * Aug/04/2016, Rahul P, Created
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<stdint.h>

/*This function find the number from the array user want and gives position from that number in array */

uint32_t binserch(uint32_t num, uint32_t arr[], uint32_t ele)
{    	

    uint32_t high; /*holding higher position of array*/
    uint32_t low;  /*holding lower position of array*/
    uint32_t mid;  /*holding middel position value of array*/

    low = 0;
    high = ele - 1;
    mid = ( low + high) / 2;

    while( low <= high && num != arr[mid] ) {

        if( num < arr[mid] ) 
            high = mid - 1;
        else 
            low = mid + 1;
        mid = ( low + high) / 2;
    }

    if( num == arr[mid] )
        return mid;
    else
        return -1;
}

int main(void)
{

    uint32_t arr[] = {10,20,30,40,50,60};  /*array in which sorted data present*/
    uint32_t num; /*number which you want to find*/
    uint32_t element;  /*number of element in array*/

    element = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the number you want to find\n");
    scanf("%d",&num);

    printf("Answer is %d\n",binserch(num,arr,element));

    return 0;
}

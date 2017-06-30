/*Copyright(c) <2016>, Volansys Technologies 
 *  *  * 
 * Description: 
 * @main.c   
 * @This is part of rail reservation system thi is a menu we can call our modules 
 *  using this main module.
 *     
 * Author       - Rahul Patel 
 *  
 ********************************************************************************* 
 *             
 * History 
 *               
 * Aug/29/2016, Rahul P  
 *                                      
 * Aug/29/2016, Rahul P, Created
 * 
 *********************************************************************************/


#include "header_h.h"

int main(void)
{
    int option;  /* Store option */

    while (1) {

        printf("\n\nMenu: \n");
        printf("1) Train  Inquiry\n2) Reservation\n3) Edit Train Info\n4) Exit\n");
        scanf("%d",&option);
        switch(option) { /* checking which option is present */

            case 1:
                TrainInfo(); /* call train related info module */
                break;
            case 2:
                Reservation(); /* call reservation module */
                break;
            case 3:
                edittraininfo(); /* call edit train module */
                break;
            case 4:
                break;
            default:
                printf("Enter valid option\n");
                break;
        }
        if (option == 4)
            break;

    }

    return 0;

}

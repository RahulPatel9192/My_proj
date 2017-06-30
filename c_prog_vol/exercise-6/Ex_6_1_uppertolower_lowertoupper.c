/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_6_1_uppertolower_lowertoupper.c   
 *@we creat two functions uppertolower()  which convert uppetcase to lowercase or lowertoupper()
 * which convert lowercase to uppercase. 
 *Author       - Rahul Patel 
 *   
 ******************************************************************************* 
 *           
 *History 
 *             
 *Aug/12/2016, Rahul P  
 *                                    
 *Aug/12/2016, Rahul P, Created
 * 
 *******************************************************************************/ 

#include<stdio.h>
#include<string.h>

void uppertolower(char *);   /* convert uppercase to lowercase */
void lowertoupper(char *);   /* convert lowercase to uppecase */

int main(int argc, char **argv)
{
    int flag = 1;          /* checking flag */
    char type;             /* check charecter use for uppertolower or lowertoupper function */

    if ( argc != 2 ) {              /* checking valid variable argument condition */
        printf("Error: write file name and string \n");
        return 0;
    }

    if(flag != 0) {                        /* Check ./ul file enter */
        flag = strcmp(argv[0], "./ul");
        type = argv[0][2];
    }
    if(flag != 0) {                       /* Check ./lu file enter */  
        flag = strcmp(argv[0], "./lu");
        type = argv[0][2];
    }

    if ( flag == 0) {

        switch( type ) {
            case 'u' :
                uppertolower(argv[1]);
                break;
            case 'l' :
                lowertoupper(argv[1]);
                break;
        }
    }
    else
        printf("Enter valid executable file \n -ul(for upper to lower)\n -lu(for lower to upper)\n");

    return 0;
}

void uppertolower(char string[])
{
    int count;   /* use for counting element of the string */

    for( count = 0; string[count]; count++ ) {
        if( string[count] >= 'A' && string[count] <= 'Z' )      
            string[count] = string[count] + 32;       /* convert upper to lower */
    }
    
    string[count] = '\0';
    
    printf("%s\n",string);
}

void lowertoupper(char string[])
{
    int count;   /* use for counting element of the string */
    for( count = 0; string[count]; count++ ) {
        if( string[count] >= 'a' && string[count] <= 'z' )
            string[count] = string[count] - 32;      /* convert lower to upper*/
    }
    
    string[count] = '\0';
    
    printf("%s\n",string);
}

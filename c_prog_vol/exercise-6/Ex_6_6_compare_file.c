/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_6_6_compare_file.c   
 * @This program is to compare two files, printing the first line where they differ.
 * 
 * 
 *  Author       - Rahul Patel 
 *   
 ******************************************************************************** 
 *            
 * History 
 *             
 * Aug/12/2016, Rahul P  
 *                                    
 * Aug/12/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>
#include<string.h>

#define LENGTH 200    /* size of the line */

int main(int argc ,char **argv)
{
    FILE *file1;    /* file1's file pointer */
    FILE *file2;    /* file2's pointer */

    char l_file1[LENGTH];    /* store 1st file's line */
    char l_file2[LENGTH];    /* store 2nd file's line */
    int line = 0;                /* count line number */
    
    if ( argc != 3) {
        printf("Error: enter 2 file name\n");
        return 0;
    }

    file1 = fopen(argv[1], "r");    /* open file1 in read mode*/
    file2 = fopen(argv[2], "r");    /* open file2 in read mode*/

    while (fgets(l_file1, LENGTH, file1) != NULL && 
           fgets(l_file2, LENGTH, file2) != NULL) {    /* Takeing line from files */
        line++;
       if( strcmp(l_file1,l_file2) != 0) {                   /* compare 2 lines */
            printf("In file1 Diiference in line number %d- %s",line,l_file1);
            printf("In file2 Diiference in line number %d- %s",line,l_file2);
            break;
        }
    }


    return 0;
}

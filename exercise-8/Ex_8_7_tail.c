/*Copyright(c) <2016>, Volansys Technologies 
*  * 
* Description: 
* @Ex_8_7_tail.c   
* @print last -n number of lines from the file.
* 
* 
* Author       - Rahul Patel 
*   
********************************************************************************* 
*           
* History 
*              
* Aug/17/2016, Rahul P  
*                                     
* Aug/17/2016, Rahul P, Created
*                
********************************************************************************/

#include<stdio.h>

#define LENGTH 200
#define start 10

int main(int argc,char **argv)
{

    FILE *file;  /* input file pointer */
    char line[LENGTH]; /* storing line of file */
    int line_nu = 1; /* counting file number */
    int lin; /* line number */

    if( argc == 1) {
        printf("Error: Enter filename\n");
        return 0;
    }

    file = fopen(argv[1],"r");

    while(fgets(line,LENGTH,file) != NULL) {   /*counting line number */
        line_nu++;
    }

    rewind(file);

    if(argc == 2)      /* default number */
        lin = line_nu - start;
    else
        lin = line_nu - atoi(argv[2]); /* uesre's line number*/

    line_nu = 1;

    while(fgets(line,LENGTH,file) != NULL) {
        line_nu++;
        if( line_nu > lin)
            puts(line);
    }

    return 0;
}


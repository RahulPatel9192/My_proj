/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_6_7_find_filneame.c   
 *@In this program take its input from a set of named files
 * or, if no files are named as arguments, from the standard input. Should the file name be printed when a
 * matching line is found.
 * 
 *  
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

#define LENGTH 50   /* length of filename */

int main(int argc,char **argv)
{
    char stdini_file[LENGTH];   /* store file name */
    int i,j=0;

    if(argc <= 2) {          
        while(1) {                                       /* check if user gave filename at stdin */               
            while ((stdin_file[j++]= getchar())!= '\n'); 
            stdin_file[--j]='\0';
            j=0;
            if( strcmp(stdin_file,argv[1]) == 0) {
                printf("Match found\n");
                return 0;
            }
            else
                printf("Match not found\n");
        }
    }

    else if ( argc > 2) {    /* check if user find filename at var argument */

        for(i=2; argc != 2; i++,argc--) {

            if( strcmp(argv[1],argv[i]) == 0) {
                printf("Match found\n");
                return 0;
            }
            if (argc == 3)
                printf("Match not found\n");
        }



    }
    else      /* proper input was not */
        printf("Error: enter valid input\n");



    return 0;
}

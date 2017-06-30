/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_6_8_print_files.c   
 *@This program is to print a set of files, starting each new one on a new page, with a title and
 * a running page count for each file.
 * 
 * 
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

#define LENGTH 200   /* length of string */
#define PAGE 10      /* line par page */

int main(int argc,char **argv)
{
    
    FILE *dest;          /* Destination file pointer */
    FILE *src;           /* Source file pointer */  
    
    dest = fopen(argv[1],"w");    /* open destination file in write mode */

    char line[LENGTH];   /* store line of the file */
    int cnt = 2;             /* counting purpose*/
    int flag = 0;
    int line_nu = 0;       /* counting lines */
    int page = 0;         /* counting page number*/

    if (argc < 2) {
        printf("Error: Enter proper input\n");
        return 0;
    }

    while ( argc != 2) {
        src =fopen(argv[cnt],"r");

        flag = 1;

        if (flag == 1)               /* checking for new file and print name */
            fprintf(dest,"\t\t\t\t filename:-%s\n",argv[cnt]);

        while (fgets(line,LENGTH,src)!= NULL) { /* copy source to destination file */
            fputs(line,dest);
            line_nu++;
        
            if( line_nu == PAGE){      /* setting page number */
            fprintf(dest,"\t\t\t\t\t page-%d\n",page);
            page++;
            line_nu = 0;
            }

            fputs("\n",dest);

        }

        fprintf(dest,"\t\t\t\t\t page-%d\n",page);
        page++;
        argc--;

        cnt++;

        flag=0;


    }
    return 0;
}



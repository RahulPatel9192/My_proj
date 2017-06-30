/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_6_2_print_sensibal.c   
 *@This program will print arbitrary input in a sensible way. As a minimum, it should
 * print non-graphic characters in octal or hexadecimal according to local custom, 
 * and break long text lines.
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
#include<ctype.h>

#define MAXLINE 100  /* Maxline length of string */

int main(int argc, char **argv)
{

    char ch;   /* storing char */
    int pos = 0; /* checking for maxline */
    int i = 0; 

    if(argc != 3) {
        printf("usage: <hex/octal> <String>\n");
        return 0;
    }


    while ((ch = argv[2][i])!= '\0') {
        if ( pos > MAXLINE) {                  /* checking for maxline condition */
            printf("\n");
            pos = 0;
        }
        if( iscntrl(ch) || ch == ' ') {      /* detect presence of graphical character */
            pos++;
            if(argv[1][0] == 'o') 
                printf("/%0o\n",ch);
            else if(argv[1][0] == 'x')
                printf("0x%x\n",ch);
            else {
                printf("enter hex(x) or octal(o) format\n");
                return 0;
            }


            if( pos == MAXLINE) {
                putchar('\n');
                pos = 0;
            }
        }
        else {                              /* non-graphical character*/
            if(argv[1][0] == 'o') 
                printf("/%0o\n",ch);
            else if(argv[1][0] == 'x')
                printf("0x%x\n",ch);
            else {
                printf("enter hex(x) or octal(o) format\n");
                return 0;
            }
            pos++;
        }
        i++;
    }




    return 0;
}

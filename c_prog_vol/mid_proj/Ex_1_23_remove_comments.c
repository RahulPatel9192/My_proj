/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_1_23_remove_comments.c   
 * @Rmove comments from the C file.
 * 
 * 
 * Author       - Rahul Patel 
 *    
 ******************************************************************************* 
 *            
 * History 
 *           
 * Aug/10/2016, Rahul P  
 *                                     
 * Aug/10/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>

int main(int argc, char** argv)
{
    FILE *source_file,*opfile;      /* file pointers */
    char ch,ch2;                /* storing characters */

    if( argc != 2) {                         /* check proper vriable argument */
        printf("usage: enter filename\n");
        return 0;
    }

    source_file = fopen(argv[1],"r");       /* Open .c file for reading */

    opfile = fopen("data","w");        /* open file for writting purpose */

    while ( (ch=fgetc(source_file))!= EOF) {
        if( ch != '"') {
            printf("%c\n",ch);
        if( ch == '/') {                  
            ch=fgetc(source_file);
            if(ch == '*' || ch == '/') {
                if(ch=='/')                       /* checking single line comments */   
                    while((ch=fgetc(source_file))!='\n');
                else {
                    while((ch = fgetc(source_file))!=EOF) {    /* checking multiple line comments */
                        ch2= fgetc(source_file);
                        if( ch == '*' && ch2 == '/')
                            break;
                        fseek(source_file,-1,SEEK_CUR);
                    }ch=fgetc(source_file);
                }
            }
            else
            fputc(ch,opfile);
        }
        else
        fputc(ch,opfile);
        }
        else {
            fputc(ch,opfile);
            while((ch = fgetc(source_file)) != '"')
                fputc(ch,opfile);
            fputc(ch,opfile);
        }

    }

    return 0;
}


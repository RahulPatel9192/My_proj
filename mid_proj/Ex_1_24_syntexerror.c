/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_1_24_syntexerror.c   
 * @This program is check a C program for rudimentary syntax errors like unmatched parentheses,
 * brackets and braces and commnets.
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

int check_escap_sequance(char );    /* check escapsequance is valid or not */ 

int main(int argc, char** argv)
{
    FILE *source_file;              /* Source file pointers */
    char ch,ch2;                        /* storing characters */
    int s[20] = {0};                /* store counts */
    int flag;                       /* flag for escap sequance */
    int flag_comment = 1;               /* flag for comments */

    if( argc != 2) {                         /* check proper vriable argument */
        printf("usage: enter filename\n");
        return 0;
    }

    source_file = fopen(argv[1],"r");       /* Open .c file for reading */

    while((ch = fgetc(source_file)) != EOF) {

        switch (ch) {
            case '<':
                s[0]=s[0]+1;
                break;
            case '>':
                s[1]=s[1]+1;
                break;
            case '{':
                s[2]=s[2]+1;
                break;
            case '}':
                s[3]=s[3]+1;
                break;
            case '[':
                s[4]=s[4]+1;
                break;
            case ']':
                s[5]=s[5]+1;
                break;
            case '(':
                s[6]=s[6]+1;
                break;
            case ')':
                s[7]=s[7]+1;
                break;
            case '"':
                s[8]=s[8]+1;
                break;
            case '\\':
                ch = fgetc(source_file);
                flag = check_escap_sequance(ch);
                if( flag == 0)
                    printf("Error: Unknown Escap sequance\n");
                break;
            case '/':
                
                ch = fgetc(source_file);
                    if (ch == '/' ) 
                        ch = fgetc(source_file);
                    else {
                        if( ch != '*')
                        flag_comment = 0;
                    }
                    if ( ch == '*') {
                        while((ch = fgetc(source_file)) != EOF) {
                        ch2 = fgetc(source_file);
                        if(ch == EOF || ch2 == EOF) {
                            flag_comment = 0;
                            break;
                        }
                            if( ch == '*' && ch2 == '/')
                            break;
                        fseek(source_file,-1,SEEK_CUR);
                    }
                    
                    }
                
                if(flag_comment == 0) {
                printf("Error: comments\n");
                flag_comment = 1;
                }
                break;
        }
    }

    if( s[0] != s[1])
        printf("Error: missing '<' '>'\n");
    if( s[2] != s[3])
        printf("Error: missing '{' '}'\n");
    if( s[4] != s[5])
        printf("Error: missing '[' ']'\n");
    if( s[6] != s[7])
        printf("Error: missing '(' ')'\n");
    if( (s[8]%2) != 0)
        printf("Error: missing '\"' \n");
    

    return 0;
}

/* function find any error occur in escap sequance or not */
int check_escap_sequance(char ch)
{

    char escap_sequances[] = { 'a', 'b', 'f', 'n', 'r', 't', 'v', '/', '\'', '\"', '?', 'x'};
    int ele;
    int i;

    ele = sizeof(escap_sequances)/sizeof(escap_sequances[0]);
    
    for( i = 0; i<ele; i++) {
        if ( ch == escap_sequances[i] )
            return 1;
    }
    return 0;
}


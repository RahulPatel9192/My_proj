/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_8_1_readline.c   
 *@Rewrite readlines to store lines in an array supplied by main, 
 * rather than calling alloc to maintain storage. How much faster is the program?
 *
 *
 *Author       - Rahul Patel 
 *   
 ******************************************************************************* 
 *           
 *History 
 *             
 *Aug/16/2016, Rahul P  
 *                                    
 *Aug/16/2016, Rahul P, Created
 * 
 *******************************************************************************/ 

#include <stdio.h>
#include <string.h>

#define MAXLINES 1000 /* max #lines to be sorted */
#define MAXLEN 100

int readlines(char lines[][MAXLEN], int nlines);  /*readlines from input */

int mygetline(char *, int);  /* geeting line from stdin */

void writelines(char lines[][MAXLEN], int nlines);   /* write lines on stdout*/


char lines[MAXLINES][MAXLEN];   /* 2D array which store lines */


int main(void)
{
    int nlines;   /* number of ip lines read*/

    if ((nlines = readlines(lines, MAXLINES)) >= 0) {
        writelines(lines, nlines);
        return 0;
    } 
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


/* readlines: read input lines */

int readlines(char lines[][MAXLEN], int maxlines)
{
    int len, nlines;
    nlines = 0;

    nlines = 0;
    while ((len = mygetline(lines[nlines], MAXLEN)) > 0)
        if (nlines >= maxlines)                         
            return -1;           
        else {
            /* change here */
            lines[nlines][len - 1] = '\0';  /* put null char */
            nlines++; /* increment n*/
        }
    return nlines;
}

/* writelines: write output lines */

void writelines(char lines[][MAXLEN], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lines[i]);
}

/* Geting character from stdin and store into array */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

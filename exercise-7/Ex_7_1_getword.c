/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_7_1_getword.c   
 *@In this program gteword function handle underscore,string constant,comments,
 * preprocessor control lines.
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

#include<stdio.h>
#include<string.h>
#include<ctype.h>


struct key {
    char* word;
    int count;
}keytab[]= { "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "double", 0,
    "else", 0,
    "float", 0,
    "for", 0,
    "if", 0,
    "int", 0,
    "register", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "unsigned", 0,
    "while", 0};

#define MAXWORD 100 
#define BUFSIZE 100                             /* buffer size for ungetch array */
#define NKEYS sizeof(keytab)/sizeof(keytab[0])  /* number of element in structure of array */

/* global varible for getch and ungetch function*/

/******************************************************/
char buf[BUFSIZE];
int bufp = 0;
/*****************************************************/

int getch(void);   /*getting character from stdin */

void ungetch(int); /* store char in buffer */

int getword(char *, int);      /* getword from stdin */

int binsearch(char *, struct key *, int);   /* serching word */


    char word[MAXWORD];
int main(void)
{

    int n;    
    //char word[MAXWORD];

    while((getword(word, MAXWORD) != EOF))  
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) 
                keytab[n].count++;
    
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",keytab[n].count, keytab[n].word);

    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* getword: get next word or character from input */
/* changes here in getword function */
int getword(char *word, int lim)
{
    int c,t;   /* store getch return value */
    char *w = word;

    while (isspace(c = getch()));

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        if( c == '#') {
            for( c = getch(); c!= '\n'; c = getch());
                ungetch(c);
        }

        else if(c == '/') {
            if( (c = getch()) == '/'){
                for(c = getch(); c!='\n'; c = getch());
            }
            else if ( c == '*') {
                for(c = getch(), t = getch(); c != '*' && t != '/';
                        c = getch(),t = getch())
                    ungetch(t);
            }
            else if(c == '_' ) {
                for ( c= getch(); c!='\n'; c =getch());
                ungetch(c);
            }
            else
                ungetch(c);

        }       
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';

    return word[0];
}

/* getch: geting char from stdin */

int getch(void)
{
    return (bufp>0) ? buf[--bufp] :getchar();
}

/* ungetch: ungeting character from buffer */

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    
    else 
        buf[bufp++] = c;

}

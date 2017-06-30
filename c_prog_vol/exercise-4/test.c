#include<stdio.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int c);

int buf[BUFSIZE]; 
int bufp = 0;     

int main(void)
{
    int c;

//    c = EOF;

    ungetch(EOF);

    while((c=getch())!=EOF)
        putchar(c);
    
    printf("c- %d\n",c);
    return 0;
}

/* getch: get a (possibly pushed back) character */

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push a character back onto the input */

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
//        if(c!=EOF)
        buf[bufp++] = c;
}


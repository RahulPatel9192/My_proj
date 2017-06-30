/*Copyright(c) <2016>, Volansys Technologies 
*  * 
* Description: 
* @Ex_8_8_sort_r.c   
* @Modify the sort program to handle a -r flag, which indicates sorting in reverse 
*  (decreasing) order. Be sure that -r works with -n.
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
#include <stdio.h>
#include <string.h>
#include<alloca.h>
#include<stdlib.h>

#define MAXLINES 1000
#define MAXLEN 100

char *lineptr[MAXLINES];

/* max #lines to be sorted */
/* pointers to text lines */
/* readlines: read input lines */
int readlines(char *linept[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline or '\n' */
            strcpy(p, line);
            linept[nlines++]= p;
        }
    }
    return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n",lineptr[i]);
}

void my_qsort(void *lineptr[], int left, int right,
        int (*comp)(void *, void *));

int numcmp(char *, char *);
int stringcmp(char *,char *);
/* sort input lines */

main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)   /* 1 if numeric sort */
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        my_qsort((void**) lineptr, 0, nlines-1,
                (int (*)(void*,void*))(numeric?numcmp:stringcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* my_qsort: sort v[left]...v[right] into increasing order */

void my_qsort(void *v[], int left, int right,
        int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last-1, comp);
    my_qsort(v, last+1, right, comp);

}

/* numcmp: compare s1 and s2 numerically */

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* stringcmp: compare s1 and s2 in ascii*/
int stringcmp(char *s1,char *s2)
{

    if( strcmp(s1,s2) < 0)
        return -1;
    else if( strcmp(s1,s2) > 0)
        return 1;
    else
        return 0;


}
void swap(void *v[],int i, int j)
        {
        void *temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        }
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


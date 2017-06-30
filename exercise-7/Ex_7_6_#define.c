/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Ex_7_6_#define.c   
 * @Implement a simple version of the #define processor (i.e., no arguments) 
 * suitable for use with C programs.
 * 
 * 
 * Author       - Rahul Patel 
 *   
 ******************************************************************************** 
 *            
 * History 
 *              
 * Aug/19/2016, Rahul P  
 *                                    
 * Aug/19/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct nlist {            /* table entry: */
    struct nlist *next;   /* next entry in chain */
    char *name;           /* defined name */
    char *defn;           /* replacement text */
};

#define HASHSIZE 101
#define MAXWORD 100 
#define BUFSIZE 100   /* buffer size for ungetch array */

/* global varible for getch and ungetch function*/

/******************************************************/
char buf[BUFSIZE];
int bufp = 0;
/*****************************************************/

int getch(void);   /*getting character from stdin */

void ungetch(int); /* store char in buffer */

int getword(char *, int);      /* getword from stdin */

struct nlist *install(char *, char *); /* install key and value */

unsigned hash(char *s);          /* give hash value */

struct nlist *lookup(char *);    /* finding if any previous entry in hashtable or not*/

struct nlist *undef(char *);     /* undefine name */  

static struct nlist *hashtab[HASHSIZE];        /* pointer table */

int main(void)
{

    struct nlist* list[5];
    struct nlist* found[5];
    char word[MAXWORD];
    char name[MAXWORD],defn[MAXWORD];
    int len,n,i=0,j=0,k=0;
    char ch;

    while(1) {
        if ( (ch = getch()) == '#') {
            if ((len=getword(word,MAXWORD))!=EOF) { 
                if( (n=strcmp( word,"define"))==0) { /* checking for #define */
                    if( (len=getword(word,MAXWORD))!=EOF)
                        strcpy(name,word); /* collect name */
                    if( (len=getword(word,MAXWORD))!=EOF)
                        strcpy(defn,word); /* colect defination */
                    list[i]=install(name,defn); /* add at hashtable */
                    printf("%s %s\n",list[i]->name,list[i]->defn);
                    i++;
                }
            }
        }

        else {
            if(ch != '\n') {  
                for(k=0;ch != ' ' && ch != '\n';k++) {
                    word[k] = ch;
                    ch =getch();
                }
                word[k]='\0';
                if((found[j] = lookup(word))!=NULL) { /* checking for any name in hashtable */
                    printf("found-%s\n",found[j]->defn); /* if found print */
                    j++;
                }
                else
                    printf("not found\n");
        }
            else
                ch = '\0';
      } 
    }
    return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;       /* found */

    return NULL;   /* not found */
}

/* install: put (name, defn) in hashtab */

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {       /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } 
    else                         /* already there */
        free((void *) np->defn);   /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;

    return np;
}

/* undefine or remove name and defination */

struct nlist *undef(char *name) {  
    struct nlist *found;

    found = lookup(name);

    if (found == NULL) /* not found and nothing to do */
        return NULL;
    else {
        if (found->next != NULL) {
            found->next = found->next->next;
            found = found->next;
        } 
        else {
            hashtab[hash(name)] = NULL;
            free(found);
        }
    }
    return found;
}

/* getword: get next word or character from input */

int getword(char *word, int lim)
{
    int c,t;   /* store getch return value */
    char *w = word;

    while (isspace(c = getch()));

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
       // if( c == '\n') 
        //    for( c = getch(); c!= '\n'; c = getch());

         if(c == '/') {
            if( (c = getch()) == '/'){
                for(c = getch(); c!='\n'; c = getch());
            }   
            else if ( c == '*') {
                for(c = getch(), t = getch(); c != '*' && t != '/';
                        c = getch(),t = getch())
                    ungetch(t);
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
    /*
    char ch;
    if( (ch = getchar()) == '\n')
        ungetch(ch);
    else*/
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


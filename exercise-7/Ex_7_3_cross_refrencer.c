/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Ex_7_3_cross_refrencer.c   
 * @This is a cross-referencer that prints a list of all words in a document, 
 * and for each word, a list of the line numbers on which it occurs.
 * 
 * 
 * Author       - Rahul Patel 
 *   
 ******************************************************************************** 
 *            
 * History 
 *              
 * Aug/17/2016, Rahul P  
 *                                    
 * Aug/17/2016, Rahul P, Created
 * 
 ********************************************************************************/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100   /* size of maxwords */
#define NKEYS sizeof(keytab)/sizeof(keytab[0])
#define LENGTH 100

struct key {         /* structure of keywords */
    char* word;
}keytab[]= {
    {"a"},
    {"an"},
    {"and"},
    {"be"},
    {"but"},
    {"by"},
    {"he"},
    {"I"},
    {"is"},
    {"it"},
    {"off"},
    {"on"},
    {"she"},
    {"so"},
    {"the"},
    {"they"},
    {"you"}
};


struct tnode {     /* struture for tree */
    char *word;
    int line;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int );   /* add variable in  tree */

void treeprint(struct tnode *);   /* printing tree */

int binsearch(char *, struct key tab[], int );   /* binary serch method */

struct tnode *talloc(void);  /* allocate memory */


/* word frequency count */

int main(int argc,char **argv)
{
    struct tnode *root;    /* structure pointer */
    char word[MAXWORD],ch;   /* array for storing words */
    int n,i=0;  /* counting purpose*/
    FILE *src_file;  /* file pointer*/
    char string[LENGTH]; /* for storing string to the file*/
    int line = 1;

    root = NULL;

    if(argc != 2){
        printf("ERROR: Enter filename\n");
        return 0;
    }

/* changes here til main()  end */
    src_file =fopen(argv[1],"r");
    while ( (ch = fgetc(src_file)) != EOF) {
        if(ch != ' ' && ch != '\n') 
            word[i++] = ch;
        
        if(ch == '\n')
        line++;

        if ( ch == '\n' || ch == ' ') {
        
            word[i] = '\0';
            
            i = 0;
            if( (n = binsearch(word, keytab, NKEYS)) != -1)
                root = addtree(root,word,line);
        }
        
    }
    treeprint(root);
    return 0;
}

/* addtree: add a node with w, at or below p */

struct tnode *addtree(struct tnode *p, char *w, int line)
{
    int cond;
    if (p == NULL) {      /* a new word has arrived */
        p = talloc();             /* make a new node */
        p->word = strdup(w);
        p->line = line;
        p->left = p->right = NULL;
    } 
    else if ((cond = strcmp(w, p->word)) == 0);
    
    else if (cond < 0)         /* less than into left subtree */
        p->left = addtree(p->left, w, line);
    else                   /* greater than into right subtree */
        p->right = addtree(p->right, w,line);
    return p;
}
/* treeprint: in-order print of tree p */

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%s: %d\n", p->word,p->line);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* binsearch: find word in tab[0]...tab[n-1] */

int binsearch(char *word, struct key keytab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, keytab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else {
            return -1;
        }
    }
    return 1;
}


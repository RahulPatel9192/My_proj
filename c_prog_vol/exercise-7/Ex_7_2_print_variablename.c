/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Ex_7_2_print_variables.c   
 * @This program reads a C program and prints in alphabetical order each 
 * group of variable names that are identical in the first 6 characters, 
 * but different somewhere thereafter.Don't count words within strings and comments. 
 * Make 6 a parameter that can be set from the command line.
 * 
 * 
 * 
 * Author       - Rahul Patel 
 *   
 ******************************************************************************** 
 *            
 * History 
 *              
 * Aug/16/2016, Rahul P  
 *                                    
 * Aug/16/2016, Rahul P, Created
 * 
 ********************************************************************************/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include<alloca.h>

#define MAXWORD 100   /* size of maxwords */
#define NKEYS sizeof(keytab)/sizeof(keytab[0])

struct key {         /* structure of keywords */
    char* word;
}keytab[ ] = {
    {"char"},
    {"const"},
    {"double"},
    {"float"},
    {"int"},
    {"register"},
    {"short"},
    {"unsigned"}
};


struct tnode {     /* struture for tree */
    char *word;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);   /* add variable in  tree */

void treeprint(struct tnode *);   /* printing tree */

int binsearch(char *, struct key tab[], int );   /* binary serch method */

struct tnode *talloc(void);  /* allocate memory */

/* word frequency count */
int main(int argc,char **argv)
{
    struct tnode *root;    /* structure pointer */
    char word[MAXWORD],ch,ch2;   /* array for storing words */
    char *var[20]={0};    /* array of pointer */
    int n,i,j=0,k=0;  /* counting purpose*/
    FILE *src_file;  /* file pointer*/
    FILE *source_file;
    
    root = NULL;

    if(argc != 3){
        printf("Error: Enter File_name char_len\n");
        return 0;

    }

/* changes here till end of the  main() function */
    source_file=fopen(argv[1],"r");
    src_file =fopen("data1","w");

    while ( (ch=fgetc(source_file))!= EOF) {
        if( ch != '"') {
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
                    fputc(ch,src_file);
            }
            else
                fputc(ch,src_file);
        }
        else {
            while((ch = fgetc(source_file)) != '"');
        }   

    }       

    rewind(src_file);
    src_file = fopen("data1","r");


    while (fscanf(src_file,"%s",word) != EOF) {        /* find keyword */
        if((n = binsearch(word,keytab,NKEYS)) ==1) {
            i = 0;
            ch = fgetc(src_file);
            do{                                 /* find variables */
                ch = fgetc(src_file);
                if(ch ==','){
                    word[i]='\0';
                    i = 0;
                    ch = fgetc(src_file);
                    var[j] = strdup(word);
                    j++;
                    k++;
                }
                word[i++] = ch;

            }while(ch != ';');
            word[--i] = '\0';
            var[j] = strdup(word);
            j++;
            k++;
        }
    }
    for( j = 0; j < k; j++) {
        for(i = j + 1; i < k; i++) { /* find matching variables */
            if((n = strncmp(var[j], var[i], atoi(argv[2]) ) ) == 0) {  
                root = addtree(root,var[j]);
                root = addtree(root,var[i]);
            }
        }
        

    }
    treeprint(root);
    return 0;
}

/* addtree: add a node with w, at or below p */

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL) {      /* a new word has arrived */
        p = talloc();             /* make a new node */
        p->word = strdup(w);
        p->left = p->right = NULL;
    } else if 
        ((cond = strcmp(w, p->word)) == 0);
    else if (cond < 0)         /* less than into left subtree */
        p->left = addtree(p->left, w);
    else                   /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}
/* treeprint: in-order print of tree p */

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%s\n", p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
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
            return 1;
    }
    return -1;
}


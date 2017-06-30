/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Ex_7_3_wordcount.c   
 * @Write a program that prints the distinct words in its input sorted into 
 * decreasing order of frequency of occurrence. Precede each word by its count.
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

struct tnode {     /* struture for tree */
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *array[20];

struct tnode *addtree(struct tnode *, char *);   /* add variable in  tree */

void treeprint(struct tnode *);   /* printing tree */

struct tnode *talloc(void);  /* allocate memory */

void sort (struct tnode *, int); /*sorting */

static int count;

/* word frequency count */

int main(int argc,char **argv)
{
    struct tnode *root;    /* structure pointer */
    char word[MAXWORD],ch;   /* array for storing words */
    int i=0;  /* counting purpose*/
    FILE *src_file;  /* file pointer*/
    
    root = NULL;

    if(argc != 2){
        printf("ERROR: Enter filename\n");
        return 0;
    }

/* changes here till main() end */
    src_file =fopen(argv[1],"r");

    while ( (ch = fgetc(src_file)) != EOF) {
        if(ch != ' ' && ch != '\n') 
            word[i++] = ch;
        

        if ( ch == '\n' || ch == ' ') {       
            word[i] = '\0';
            i = 0;
            if(strcmp(word,"\0"))
            root = addtree(root,word);
        }
        
    }
    treeprint(root);
    sort(*array,count);

    return 0;
}

/* addtree: add a node with w, at or below p */

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL) {      /* a new word has arrived */
        p = talloc();             /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } 
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    
    else if (cond < 0)         /* less than into left subtree */
        p->left = addtree(p->left, w);
    else                   /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}
/* treepriint: in-order print of tree p */

void treeprint(struct tnode *p)
{
  // static int i=0,k;
    if (p != NULL) {
        treeprint(p->left);
        treeprint(p->right);
        array[count++] = p;

    }

}

void sort(struct tnode* p,int count)
{
    int i,j;
    struct tnode* temp;
printf("count-%d\n",count);
    for(i=0;i<count;i++) {
    
        for(j=i+1;j<count;j++) {
        
            if( array[i]->count < array[j]->count) {
            
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            
            }
        }
    }

for(i=0; i<count;i++)
    printf("%4d: %s\n",array[i]->count,array[i]->word);

}
 

/* talloc: make a tnode */

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

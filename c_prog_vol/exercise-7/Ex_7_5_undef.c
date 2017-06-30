/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Ex_7_5_undef.c   
 * @undef() function will remove a name and definition from the table maintained
 * by lookup and install.
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

struct nlist {            /* table entry: */
    struct nlist *next;   /* next entry in chain */
    char *name;           /* defined name */
    char *defn;           /* replacement text */
};

#define HASHSIZE 101

struct nlist *lookup(char *);    /* finding if any previous entry in hashtable or not*/

static struct nlist *hashtab[HASHSIZE];        /* pointer table */

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

/* changes here */
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


int main(void)
{

    struct nlist *table[4] = {     /* install a keys */
        (install("key", "value")),
        (install("key1", "value1")),
        (install("key2", "value2")),
        (install("key3", "value3"))
    };

    int i;

    for (i=0; i < 4; i++) {
        printf("%s->%s\n", table[i]->name, table[i]->defn);
    }
    
    printf("................................................\n");

    undef("key");   /* undefine keys */
    undef("key3");

    struct nlist *result;

    char *keys[4] = {
        "key",
        "key1",
        "key2",
        "key3"
    };

         /*changes here*/
    for (i = 0; i < 4; i++) {
        if ((result = lookup(keys[i])) == NULL) {  /* check key is present or not */
            printf("key not found\n");
        } else {
            printf("%s->%s\n", result->name, result->defn);
        }
    }

    return 0;
}





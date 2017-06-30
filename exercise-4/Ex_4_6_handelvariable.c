/*Copyright(c) <2016>, Volansys Technologies 
 *  
 * Description: 
 * @Ex_4_6_handelvariable.c   
 * @Add key and variable in structure and use it whene ever required
 *   
 * Author       - Rahul Patel 
 *    
 ******************************************************************************* 
 *           
 * History 
 *              
 * Aug/08/2016, Rahul P  
 *                                   
 * Aug/08/2016, Rahul P, Created
 * 
 ********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAXOP 100      /* max size of operand or operator */
#define MAXVAL 100    /* max value of depth stack */
#define NUMBER '0'    /* signal that a number was found */
#define BUFSIZE 100

/* Global variable for getch() Function */
/****************************************************************/
    char buf[BUFSIZE];    /* buffer for ungetch */
    int bufp = 0;         /* next free position in buf */
/****************************************************************/

/*global variable forr pop and push functions  */
/****************************************************************/
    int sp = 0;  /*next free stack position*/
    double val[MAXVAL];  /* value stack*/
/****************************************************************/

/***************************************************************/
    extern int last_value; /* store last value of the stack */
/***************************************************************/

    struct key_value {
        char key[10];    /* store variable name */
        double value;    /* store value */
    }obj[26];
    

int getop(char []);   /*getop() used to getting operand */
void push(double);    /* push operand to the stack  */
double pop(void);     /* Poping the operand to the stack */
double store(char s[]); /* Store key and value */

/* reverse Polish calculator */

int main(void)
{
    int type;              /*Which type of data is present numeric or sign*/
    double op2,op1=0;        /* operands store*/
    char s[MAXOP];         /* operand store in ascii format */
    char ch;               /* store chararacter */
  //  struct key_value obj[26];  /* Structure of array */
    double recent_value = 0;          /* most recently printed value */

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:                /* check number is present or not */                        
                push(atof(s));
                break;
            case '+':                   /* addition */
                push(pop() + pop());
                break;
            case '*':                   /* Multiplication */
                push(pop() * pop());
                break;
            case '-':                   /* Subtratction */
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':                  /* Division */
                op2 = pop();
                if (op2 != 0.0)
                    push( pop() / op2 );
                else
                    printf("error: zero divisor\n");
                break;
            case 'a'...'z':
                push(store(s));
                recent_value = val[sp-1];
                break;
            case '\n':          /* enter detect  */
                printf("ans-%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

    }

    return 0;
}



/* push: push f onto value stack */

void push(double f)
{
    if (sp < MAXVAL) 
        val[sp++] = f;
    
    else
        printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0) 
        return val[--sp];
    
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void)       /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)    /* Push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')    /*If not a number*/
        return c;

    i = 0;

    if (isdigit(c))        /* Collect integer part */
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')    /*collecting fractional part */
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


/* Store key and value */

double store(char s[])
{
    
    double last_value = 0;
    int i=0;  
    static int j;

    for(  ; i < 26; i++ ) {
        if(strcmp(s,obj[i].key) == 0 ) {
           // obj[i].value = val[sp-1];
            return obj[i].value;
        }
    }

            strcpy(obj[j].key, s);
            obj[j].value = pop();
            return obj[j++].value;
}


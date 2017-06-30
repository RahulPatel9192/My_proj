/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_6_4_scanf.c   
 *@This program is worked as a scanf() function.
 * 
 *  
 *Author       - Rahul Patel 
 *   
 ******************************************************************************* 
 *           
 *History 
 *             
 *Aug/12/2016, Rahul P  
 *                                    
 *Aug/12/2016, Rahul P, Created
 * 
 *******************************************************************************/ 

#include<stdio.h>
#include<stdarg.h>

void minscanf(char *,...);    /* take string and return nothing*/
float f;
int main(void)
{
    int number;   /*  store integer */

    printf("Enter integrer and Flot\n");
    minscanf("%d  %f",&number,&f);

    printf("%f\n",f);

    return 0;
}

/* minscanff: minimal scanf with variable argument list */

void minscanf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;   /* store format specifier */
    int ival;         /* store integer value */  
    double dval;      /* store floa or double value */  
    int oct;          /* store octal fomat */
    char s[100],ch;
    int i;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
            case 'd':                       /* checkin for integer format specifier */
                ival = va_arg(ap, int);
                scanf("%d", &ival);
                printf("%d\n",ival);
                break;                      /* checking for float format specifier */
            case 'f':
                f = va_arg(ap, double );
                scanf("%f", &f);
                break;
            case 'o':                       /* checking for octal format */
                ival = va_arg(ap,int);
                scanf("%o",&ival);
                break;
            case 'x':                       /* check for hex value */
                ival = va_arg(ap,int);
                scanf("%x",&ival);
                break;
            case 's':
                i =0;              /* checking for string format specifier */
                while( (s[i] = getchar())!= EOF && (s[i] = getchar())!= '\n') 
                    i++;
                s[i] = '\0';
                break;
            case 'c':
                ch = va_arg(ap, int);
                scanf("%c",&ch);
                printf("%c\n",ch);
            default:
                break;
        }
    }
    va_end(ap); /* clean up when done */
}

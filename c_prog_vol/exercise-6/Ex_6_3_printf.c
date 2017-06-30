/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_6_3_printf.c   
 *@This program is worked same as a printf() function.
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

void minprintf(char *,...);      /* minprintf() function take string and return nothing */

int main(void)
{
    minprintf("%d %s %f %o %e\n",1,"hi",22.3,32,0.00002);

    return 0;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;   /* store format specifier */
    int ival;         /* store integer value */  
    double dval;      /* store floa or double value */  
//    int oct;          /* store octal fomat */

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
            case 'd':                        /* checkin for integer format specifier */
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;                      /* checking for float format specifier */
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;

                /* changes here : add more cases */
            case 'i':                        /* checkin for integer format specifier */
                ival = va_arg(ap, int);
                printf("%i", ival);
                break;                      /* checking for float format specifier */
            case 'o':                       /* checking for octal format */
                ival = va_arg(ap,int);
                printf("%o",ival);
                break;
            case 'x':                       /* check for hex value */
                ival = va_arg(ap,int);
                printf("%x",ival);
                break;
            case 'X':                       /* check for hex value */
                ival = va_arg(ap,int);
                printf("%X",ival);
                break;
            case 'u':                       /* check for hex value */
                dval = va_arg(ap,double);
                printf("%d",dval);
                break;
            case 'e':                       /* check for exponen form */  
                dval = va_arg(ap,double);
                printf("%e",dval);
                break;
            case 's':                       /* checking for string format specifier */
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}

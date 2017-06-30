#include<string.h>
#include<stdio.h>

enum tag{A=0,B,C,D,E,F,G,H,I,J};

main()
{
    enum tag var=B;
    int ch= 1;
    if(var == ch)
    printf("tag-%d\n",var);



}

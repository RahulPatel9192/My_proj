#include<stdio.h>
#include<string.h>
main()
{
    int i,j,wc=0;
    char s[100];

    printf("Enter string\n");
    scanf("%[^\n]",s);

    for( i=0 ;i <strlen(s)+1; i++) {
        wc++;
        if (s[i] == ' ' || s[i] == '\0') {
            printf("%3d|",i);
            for( j=0; j<wc-1; j++)
                printf("* ");
            wc=0;
            printf("\n");
        }
    }



}

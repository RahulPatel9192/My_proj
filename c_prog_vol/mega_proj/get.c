/* getting data to the .csv file*/

#include<stdio.h>
#include<string.h>

main()
{

    char ch=',';
    char ch1;
    char str[20];
    int i=0;
    
    FILE *fp;
    fp=fopen("test1.csv","r+");
    
    while( (ch1=fgetc(fp)) != EOF) {
        if(ch1 != ch && ch != '\n')
            str[i++] = ch1;
        
      //  printf("%c",str[i]);
            if( ch1 == ch || ch1 == '\n') {
       //     printf("1\n");
                str[i] = '\0';
                printf("%s ",str);
                i=0;
            }
    }



}

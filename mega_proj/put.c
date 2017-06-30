/* putting data to the .csv file*/

#include<stdio.h>
#include<string.h>

main()
{

    char ch=',';
    char ch1;
    char str[20]="name";
    int a=10,b=20,c=30,d=40;
    char i[3]="a",j[3]="b",k[3]="c";
    
    FILE *fp;
    fp=fopen("test1.csv","r+");

    fprintf(fp,"%d%c%s\n",a,ch,i);
    fprintf(fp,"%d%c%s\n",b,ch,j);
    fprintf(fp,"%d%c%s\n",c,ch,k);
    fprintf(fp,"%d%c%s\n",d,ch,str);



}

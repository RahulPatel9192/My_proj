#include<stdio.h>
#include<string.h>

void add()
{

    int nu;
    char name[20];
    char mail[50];
    char ch=',';
    FILE *fp;

    fp=fopen("test.csv","a");

    printf("enter name: ");
    scanf("%[^\n]",name);
    //printf("\n");

    printf("enter number: ");
    scanf("%d",&nu);
    //printf("\n");

    printf("Enter mail-id: ");
    scanf("%s",mail);

    fprintf(fp,"%s%c%d%c%s\n",name,ch,nu,ch,mail);
    fclose(fp);


}


int main(void)
{

add();
return 0;



}

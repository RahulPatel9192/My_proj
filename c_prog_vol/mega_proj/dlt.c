#include<stdio.h>
#include<string.h>

void get(int nu)
{

char str[100],buff[10],buff1[10];
int i=0,j=0;

FILE *fp,*fp1;

fp=fopen("test.csv","r");
fp1=fopen("new.csv","w");

sprintf(buff1,"%d",nu);

buff[j++]=',';
for(i=0;buff1[i];i++)
    buff[j++]=buff1[i];

buff[j++]=',';
buff[j]='\0';

//printf("%s",buff);

while(fgets(str,100,fp)!=NULL) {
    if(strstr(str,buff) == NULL){
       // printf("%s",str);
        fputs(str,fp1);
    }
}

rewind(fp1);
rewind(fp);
fp=fopen("test.csv","w");
fp1=fopen("new.csv","r");

while(fgets(str,100,fp1)!=NULL) { 
        fputs(str,fp);
}
remove("new.csv");

}

int main(void)
{

int i;
printf("Enter number: ");
scanf("%d",&i);

get(i);
return 0;

}

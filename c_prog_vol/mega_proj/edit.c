#include<stdio.h>
#include<string.h>

struct st {

    char name[20];
    char nu[5];
    char mail[50];
};

void edit(int num)
{

    struct st v;
    int c;
    char ch=',';
    char ch1;
    char str[200],buff1[50],buff[50];
    int i=0,j=0,nu,k,cnt=0;
    int check=0;
    FILE *fp,*fp1;


    fp=fopen("test.csv","r");
    fp1=fopen("new.csv","w");

    sprintf(buff1,"%d",num);


    buff[j++]=',';
    for(i=0;buff1[i];i++)
        buff[j++]=buff1[i];

    buff[j++]=',';
    buff[j]='\0';
    j=0;
    i=0;
    while(fgets(str,200,fp)!=NULL) {
        if(strstr(str,buff)) 
            check = 1;
        else
            check = 0;

        if( check == 1) {
            check =0;
            printf("match\n");

            for(i=0;str[i];i++) {

                if(str[i] != ch && str[i] != '\n') { 
                    buff1[j++]=str[i];
                }

                else{
                    buff1[j]='\0';
                    j=0;
                    cnt++;
                    switch(cnt) {

                        case 1:
                            strcpy(v.name,buff1);
                            break;
                        case 2:
                            strcpy(v.nu,buff1);
                            break;
                        case 3:
                            strcpy(v.mail,buff1);
                            break;
                    }
                }
            }

            printf("Edit details\n");
            printf("1) name\n2) number\n3)mail\n");
            scanf("%d",&c);
            switch(c) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s",v.name);
                    break;
                case 2:
                    printf("Enter new number: ");
                    scanf("%s",v.nu);
                    break;
                case 3:
                    printf("Enter new mail: ");
                    scanf("%s",v.mail);
                    break;
            }
            fprintf(fp1,"%s%c%s%c%s\n",v.name,ch,v.nu,ch,v.mail);
        }
        else 
            fputs(str,fp1);
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
    int num;

    printf("enter number: ");
    scanf("%d",&num);

    edit(num);

    return 0;




}

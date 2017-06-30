#include<stdio.h>

int main(int argc,char **argv)
{
int i= 0;

for( ; argc-1 != 0; argc--)
{
printf("%d \n",argc);
printf("%s ",argv[i]);
i++;
}

printf("1\n");
}

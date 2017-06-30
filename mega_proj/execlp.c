#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main (void)
{

char cmd[20];
char *ptr;
int status;

while(1) {
    ptr = fgets(cmd,sizeof(cmd),stdin);
    if(ptr == NULL)
        exit (0);
cmd[strlen(cmd)-1] = 0;
    if(!strncmp(cmd,"bye",3))
        exit(0);

    if(fork() == 0 ) {
    execlp(cmd,cmd,NULL);

    }
    else
    {
    wait(&status);
    
    }



}


    return 0;
}

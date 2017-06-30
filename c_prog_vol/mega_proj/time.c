#include<stdio.h>
#include<stdlib.h>
main()
{
char t[8];
int m = 1440;
float hr,min;
char buff[5],buff1[5];
int i,j,k;
float time;
printf("time: ");
scanf("%s",t);

for(i=0,j=0;t[i];i++) {
 if( t[i] != ':')
     buff[j++]= t[i];
 else
     break;
}
buff[j] = '\0';
for(j=0,i++;t[i];i++) {
    buff1[j++] = t[i];
}
buff1[j]='\0';
printf("buff-%s buff1-%s\n",buff,buff1);
hr= atoi(buff);
printf("hr-%lf\n",hr);
min=atoi(buff1);
printf("min-%lf\n",min);

min = min +(hr*60);

printf("min-%lf\n",min);
time = (1000/25);
printf("time-%lf\n",time);
min = min +(time*60);
printf("total-%lf\n",min);
i = min/60;

j=i*60;
j =min-j;

printf("hr-%d\n",i);
for(k=1 ;i>24;) {
    k++;
i=i-24;
}

//printf("i-%d k-%d\n",i,k);
printf("%d:%d  day-%d\n",i,j,k);


}

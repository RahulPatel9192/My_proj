#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
void reverse(char *st)
{
	int i,j;
	char c;
	j=strlen(st)-1;
	for(i=0;j>=i;i++,j-- )
	{	c=st[i];
		st[i]=st[j];
		st[j]=c;
	}
	
	printf("string- %s\n",st);

}

void itoa(char n,char s[])
{
	int i,sign,j;

	sign=n;
//	n=abs(n/(-1));

        printf("n=%d\n",n);
		
	i=0;

	do {
	j=abs(n%10);
	printf("j %d\n",j);	
		s[i++] = j+48;
	}while((n/=10));

	if(sign < 0)
		s[i++]='-';
	s[i]='\0';

	reverse(s);


}



int main(void)
{
	int b,num;
        
	char s[20];

/*	printf("Enter integer\n");
	scanf("%d",&num);
*/

	itoa(-128,s);
	return 0;
}

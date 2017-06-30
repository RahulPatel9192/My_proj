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
}

void itoa(int n,char s[])
{
	static int i,sign,j;
    static count;

	if(n < 0) {
        sign=n;
    }
    

	if(n != 0) {
        j = abs ( n % 10 );

		s[i++] = j + 48;
        itoa( n /= 10, s );
    }

	if( sign < 0 && count == 0 ) {
		s[i++] = '-';
        count++;
    }
	s[i] ='\0';
}



int main(void)
{
	int b,num;
        
	char s[20];
    
	printf("Enter integer\n");
	scanf("%d",&num);

    itoa(num,s);

    reverse(s);

    printf("%s\n",s);
	return 0;
}

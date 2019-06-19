#include<stdio.h>
#include<stdlib.h>
int hextodec(char*s,char*t,int limit);
int main(void)
{
	char s[10],t[10];
	int limit;
	printf("Inserisci un numero esadecimale: ");
	scanf("%s",s);
	printf("Inserisci il limite di cifre: ");
	scanf("%d",&limit);
	if(hextodec(s,t,limit))
		printf("%s",t);
	return 0;
}

int hextodec(char*s,char*t,int limit)
{
	int exp=1;
	char *p,*q;
	for(p=s;*p;p++);
	for(q=t,p=p-1;p!=s;p--,q++)
	{
		*q=(*p)*exp;
		exp*=16;
	}
	*q=(*p)*exp;
	q++;
	*q='\0';
	return 1;
}

#include<stdio.h>
void sub_reverse(char*,char*);
int main(int argc,char*argv[])
{
	if(argc!=3)
		fprintf(stderr,"Numero di parametri errato, prego inserire 2 parole\n");
	else
	{
		sub_reverse(argv[1],argv[2]);
		printf("%s\n",argv[1]);
	}	
	return 0;
}
void sub_reverse(char* s1,char* s2)
{
	char* p=s1,temp;
	while(*p==*s2)
	{
		p++;
		s2++;
	}
	p--;
	while(s1<p)
	{
		temp=*s1;
		*s1=*p;
		*p=temp;
		s1++;
		p--;
	}
}

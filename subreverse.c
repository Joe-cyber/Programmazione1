#include<stdio.h>
void acquisisci_parola(char*,int*);
void stampa_parola(char*,int);
void subreverse(char*,int,char*,int);
int main(void)
{
	int dim=100,n1,n2;
	char s1[dim],s2[dim];
	printf("Inserisci la prima parola: ");
	acquisisci_parola(s1,&n1);
	printf("Inserisci la seconda parola: ");
	acquisisci_parola(s2,&n2);
	subreverse(s1,n1,s2,n2);
	printf("La parola e': ");
	stampa_parola(s1,n1);
	printf("\n");
	return 0;
}

void acquisisci_parola(char* p,int* l)
{
	char ch;
	*l=0;
	while((ch=getchar())!='\n')
	{
		*(p+*l)=ch;
		(*l)++;
	}
}

void stampa_parola(char* p,int l)
{
	char* q;
	for(q=p;q<(p+l);q++)
		putchar(*q);
}

void subreverse(char* s1,int n1, char* s2,int n2)
{
	char *q=s1, *p=s2, temp;
	while(*q==*p)
	{
		q++;
		p++;
	}
	q--;
	while(s1<q)
	{
		temp=*s1;
		*s1=*q;
		*q=temp;
		s1++;
		q--;
	}
}

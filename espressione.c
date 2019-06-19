#include<stdio.h>
#define plus '+'
#define minus '-'
int is_expression(char);
int is_number(char);
void acquisisci_espressione(char*,int);
void stampa_espressione(char*);
int main(void)
{
	char e[21];
	printf("Inserisci l'espressione: ");
	acquisisci_espressione(e,21);
	stampa_espressione(e);
}

void acquisisci_espressione(char* e,int l)
{
	char *p=e,ch;
	while(((ch=getchar())!='\n')&&(p<&e[l-1]))
		if((is_number(*p))||(is_expression(*p)))
		{
			*p=ch;
			p++;
		}
	*p='=';
}

int is_number(char c)
{
	return ((c>'0')&&(c<'9'));
}

int is_expression(char c)
{
	return ((c==plus)||(c==minus));
}

void stampa_espressione(char* e)
{
	char *p;
	/*for(p=e;*p!='=';p++)*/
		printf("%c",*p);
	putchar(*p);
}

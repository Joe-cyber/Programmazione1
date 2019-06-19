/*Scrivere un programma che data una frase, stampa se è palindroma.*/
#include <stdio.h>
char to_lower(char);
void inserimento(char*,int);
void salto(char*, char*,int);
int is_alpha(char); //controlla che il carattere sia alfabetico
int str_len(char*, int); //restituisce la lunghezza della frase 
int palindroma(char*, int);
int main(void)
{
	int n=50;
	char a[n],b[n],scelta;
	printf("Inserisci una frase: ");
	inserimento(a,n);
	salto(a,b,n);
	if(palindroma(b,n))
		printf("La frase e' palindroma\n");
	else
		printf("La frase non e' palindroma\n");
	return 0;
}

char to_lower(char c)
{
	if((c>='A')&&(c<='Z'))
		return (c+32);
	else
		return c;
}

void inserimento(char *a,int n)
{
	int i=0;	
	while((*(a+i)=getchar()) != '\n')
		i++;
}

void salto(char *a,char *b,int n)
{
	
	int l=str_len(a,n),i,k=0;
	for(i=0;i<l;i++)
		if(is_alpha(*(a+i)))
		{	
			*(b+k)=to_lower(*(a+i));
			k++;
		}
	*(b+k)='\n';
}

int is_alpha(char c)
{
	if((c>='a') && (c<='z'))
		return 1;
	else if((c>='A') && (c<='Z'))
		return 1;
	else 
		return 0;
}

int str_len(char*a, int n)
{
	int i;
	for(i=0;i<n;i++)
		if(*(a+i)=='\n')
			return i;	
	return -1; //significa che non contiene \n e non si può usare
}

int palindroma(char*b,int n)
{
	int i,k=str_len(b,n)-1;
	for(i=0;i<k;i++, k--)	
		if(*(b+i)!=*(b+k))
			return 0;
	return 1;
}

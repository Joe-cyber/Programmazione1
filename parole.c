/*Scrivere un programma che prende in ingresso una serie di parole le concatena in un altro array.*/
#include <stdio.h>
void inserimento(char*,int);
void stampa(char*,int);
int copia_array(char*,char*,int,int);
int main(void)
{
	int n=50,k=0,scelta;
	char c[n],d[n];
	do
	{
		inserimento(c,n);
		
		k=copia_array(c,d,n,k);
		
		printf("\nVuoi inserire un'altra parola?\nInserire:\n 1. se e' si, 0. se e' no:");
		
		scanf("%d",&scelta);
		getchar();
	}while(scelta!=0);
	stampa(c,n);	
return 0;
}

void inserimento(char*c,int n)
{
	printf("Inserisci una parola: ");
	while((*c=getchar()) != '\n')
	c++;	
}

void stampa(char *c, int n)
{
	int i;

	for(i=0;i<n && *(c+i)!=' ';i++)
	{
		printf("%c\t",*(c+i));	
	}	
}

int copia_array(char *c, char *d, int n, int k)
{
	int i=0;
	for(;k<n && c[i]!='\n';k++,i++)
	{
		*(d+k)=*(c+i);
	}
	*(d+k)=' ';

	return k+1;
}

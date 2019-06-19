/*Scrivere un programma che preso un array di n elementi, genera il reverse utilizzando i puntatori.*/
#include <stdio.h>
void inserimento(int[],int);
void stampa(int[],int);
void reverse(int[],int);
int main(void)
{
	int n=6;
	int a[n];

	printf("\nInserisci %d numeri: ",n);
	printf("\n");
	inserimento(a,n);
	printf("Vettore:");
	stampa(a,n);
	reverse(a,n);
	printf("\nReverse: ");
	stampa(a,n);

return 0;
}

void inserimento(int a[], int n)
{
	int *p,i=0;
	for(p=a;p<&a[n];p++)
	{
		printf("Inserisci un numero nella posizione [%d]: ",i+1);
		scanf("%d",&*p);	
		i++;
	}
}

void stampa(int a[],int n)
{
	int *p;
	for(p=a;p<&a[n];p++)
		printf("%d\t",*p);
}

void reverse(int a[],int n)
{
	int *p,*q,temp,i;
	p=a;
	q=a+(n-1);
	for(i=0;i<n/2;i++)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
	}
	
}

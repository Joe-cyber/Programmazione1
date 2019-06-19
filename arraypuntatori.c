/*Acquisire un array e con l'aritmetica dei puntatori:
-calcolare e stampare la somma;
-calcolare e stampare il massimo e il minimo;
-calcolare e stampare la media.*/
#include <stdio.h>
void inserimento_dati(int, int*);
void stampa(int,int*);
void somma_array(int*,int*,int);
void massimo(int*,int*,int);
void minimo(int*,int*,int);
float calcolo_media(int*, int);
int main(void)
{
	int n=5;
	int a[n],somma,max,min;
	printf("\n");
	printf("Inserisci %d numeri: ",n);
	inserimento_dati(n,a);
	stampa(n,a);
	somma_array(a,&somma,n);
	printf("Somma: %d",somma);
	massimo(a,&max,n);
	printf("\nMassimo: %d",max);
	minimo(a,&min,n);
	printf("\nMinimo: %d",min);
	printf("\nMedia: %.2f",calcolo_media(a,n));


return 0;
}

void inserimento_dati(int n, int *a)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Inserisci un numero nella posizione [%d]: ",i+1);	
		scanf("%d",&*(a+i));
	}
}

void stampa(int n, int*a)
{
	int i;
	printf("\nVettore: ");
	for(i=0;i<n;i++)
		printf("%d\t",*(a+i));

	printf("\n");
}

void somma_array(int*a,int *somma, int n)
{
	int *p;
	*somma=0;
	for(p=a;p<&a[n];p++)
		*somma=*somma+*p;	
}

void massimo(int *a, int *max, int n)
{
	int *p;
	*max=*a;
	for(p=&a[1];p<&a[n-1];p++)
		if(*p>*max)
			*max=*p;	
}

void minimo(int *a,int *min, int n)
{
	int *p;
	*min=*a;
	for(p=&a[1];p<&a[n-1];p++)
		if(*p<*min)
			*min=*p;	
}

float calcolo_media(int *a, int n)
{
	int somma;
	somma_array(a,&somma,n);
	return (float)somma/n;
}


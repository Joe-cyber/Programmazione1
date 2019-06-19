/*Scrivere un programma che prende in ingresso un array e lo riordina dal più piccolo al più grande o dal più grande al più piccolo.*/
#include <stdio.h>
void inserimento(int[],int);
void stampa(int[],int);
int minimo(int*,int*,int, int);
void ordinamento(int*,int);
int main(void)
{
	int n=6;
	int a[n];
	printf("\nInserisci %d numeri",n);
	printf("\n");
	inserimento(a,n);
	printf("\nVettore: ");
	stampa(a,n);
	ordinamento(a,n);
	printf("\nVettore ordinato:");
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

void ordinamento(int *a,int n)
{
	int i,min,k,temp;
	for(i=0;i<n;i++)
	{
		k=minimo(a,&min,n,i);
		temp=*(a+i);
		*(a+i)=*(a+k);
		*(a+k)=temp;
	}
	
}

int minimo(int *a,int *min, int n,int i)
{
	int *p,k=i;
	*min=*(a+i);
	for(p=&a[i+1];p<&a[n];p++)
		if(*p<*min)
		{
			*min=*p;
			k=p-a; //con questa operazione si ottiene l'indice della funzione
		}
	return k;	
}

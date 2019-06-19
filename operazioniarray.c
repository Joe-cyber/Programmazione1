#include <stdio.h>

typedef int bool;
#define false 0
#define true 1

#define l 5

void ordinamento(int[],int);
void inserimento(int[],int);
int minimo(int[],int);
int massimo(int[],int);
int som(int[],int);
float med(int[],int);
void stampa(int[],int);
void pulire();
bool ricerca(int[],int, int);

int main(void)
{
	int scelta,num,a[l],i;
	bool ordinato=false;

	inserimento(a,l);
	do
	{	
		printf("1. per ordinare l'array\n2. per ricercare un elemento nell'array\n 3. per trovare il minimo\n4. per trovare il massimo\n5. per calcolare la somma");
		printf("\n6. per calcolare la media\n7. per stampare l'array\n8. per reinserire array\n 9. per pulire lo schermo\n0. per uscire: ");
		scanf("%d", &scelta);
		switch(scelta)
		{
			case 1:
				ordinamento(a,l);
			break;
			case 2:
			{
				printf("\n Inserisci il numero che vuoi ricercare: ");
				scanf("%d",&num);
				
				if(ricerca(a,l,num))
				printf("\nSi, il numero compare nell'array.");
				else
				printf("\nNo, il numero non compare nell'array.");
			}
			break;
			case 3:
				printf("Minimo: %d",minimo(a,l));
			break;
			case 4:
				printf("Massimo: %d",massimo(a,l));
			break;
			case 5: 
				printf("Somma: %d",som(a,l));		
			break;
			case 6:
				printf("Media: %.2f",med(a,l));
			break;
			case 7:
				stampa(a,l);
			break;
			case 8:
				inserimento(a,l);
			break;
			case 9:
				pulire();
			break;
			case 0:
			break;
			default:
				printf("\n ERRORE");
			break;
		}
	}while(scelta!=0);


return 0;
}

void ordinamento(int a[], int n)
{
	int temp,i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}




void inserimento(int a[], int n) //naturalmente questo vale tenendo presente la lunghezza del 						primo array inserito 
{	
	int i;
	printf("\n Inserisci %d numeri: ",n);
	for(i=0;i<n;i++)
	{
		printf("\n Inserisci il numero nella posizione [%d]",i);
		scanf("%d",&a[i]);
	}
	
	

	
}

int minimo(int a[], int n)
{
	int min,i;
	min=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	return min;
}


int massimo(int a[], int n)
{
	int max,i;
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}


int som(int a[],int n)
{
	int somma=0,i;
	for(i=0;i<n;i++)
	{
		somma=somma+a[i];
	}
return somma;
}

float med(int a[],int n)
{
return (som(a,n)/n);
}

void stampa(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

}

void pulire()
{
	int i;
	for(i=0;i<50;i++) //stampo in modo artificiale delle righe bianche per pulire lo schermo
	printf("\n");
}

bool ricerca(int a[],int n,int num)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(num==a[i])
		return true;
	}
return false;
}



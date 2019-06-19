/*Scrivere un programma che chiede all'utente di inserire dei numeri all'interno di un array, trovare il massimo e restituire sia l'indice che l'indirizzo in cui si trova.*/
#include <stdio.h>
void inserimento(int[]); 
int massimo(int[],int*);
int n=10;
int main(void)
{
	int a[n],mass,indice_max;

	inserimento(a);
	indice_max=massimo(a,&mass);	//con questo assegnamento k viene messo in indice_max
	printf("\n Massimo: %d",mass);
	printf("\n Indice del massimo: %d\n",indice_max);

return 0;
}

void inserimento(int a[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nInserisci un numero nella posizione [%d]: ",i);
		scanf("%d",&a[i]);
	}
}


int massimo(int a[],int *p)
{
	int i,k=0;
	*p=*a;
	for(i=1;i<n;i++)
		if(*(a+i)>*p)
		{
			k=i;
			*p=*(a+i); //in questo modo restituisco l'indirizzo
		}
	return k;	//restituisco l'indice del massimo 

}

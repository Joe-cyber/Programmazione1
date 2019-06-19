#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define G 10
void inizializzazione(char[][G]);
void stampa(char[][G]);
void direzione(int*,int*);
void generazione(char[][G]);
int main(void)
{
	char matrice[G][G];
	srand(time(NULL)); //stabilisco il seme di partenza che è il primo generato
	inizializzazione(matrice);
	generazione(matrice);
	stampa(matrice);
	return 0;
}

void inizializzazione(char matrice[][G]) //questa funzione inizializza una matrice con i soli asterischi 
{
	int r,c;
	for(r=0;r<G;r++)
		for(c=0;c<G;c++)
			matrice[r][c]='*';
}

void stampa(char matrice[][G]) 
{
	int r,c;
	for(r=0;r<G;r++)
	{
		for(c=0;c<G;c++)
			printf("%c",matrice[r][c]);
		printf("\n");
	}
}

void direzione(int *i, int *j) 
{
	
	int i2,j2; //nel caso di valori non validi rigenero i valori partendo da quelli precedenti
	do
	{
		i2=*i;
		j2=*j;
		if(rand()%2)
		{
			if(rand()%2)
				j2++; 
			else
				j2--;	
		}
		else
		{
			if(rand()%2)
				i2++;
			else
				i2--;
		}
	}
	while((i2<0) || (i2>9) || (j2<0) || (j2>9));
	*i=i2; 
	*j=j2;
}

void generazione(char matrice[][G])
{
	char cont='A';
	int i,j,i2,j2;
	
	i=rand()%10; //parto da una posizione casuale per i che va da 0 a 9
	j=rand()%10; //parto da una posizione casuale per j che va da 0 a 9
	do
	{	
		i2=i;
		j2=j;
		matrice[i][j]=cont; //qui si sa con certezza qual è la posizione di partenza
		
		direzione(&i,&j);
		if(matrice[i][j]!='*')
		{
			i=i2;
			j=j2;
			continue; //si dirige all'iterazione successiva, saltando in questo caso cont++
		}
		cont++;
	}while(cont<='Z');

}

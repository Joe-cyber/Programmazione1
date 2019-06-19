/*Scrivere un programma che prende in ingresso una matrice e ne stampa la trasposta.*/
#include <stdio.h>
void inserimento_dati(int r, int c, int[][c]);
void stampa(int r, int c, int[][c]);
void trasposta(int r, int c, int [][c]);
int main(void)
{
	int r=2,c=4;
	int m[r][c];
	inserimento_dati(r,c,m);
	stampa(r,c,m);
	trasposta(r,c,m);

return 0;
}

void inserimento_dati(int r,int c, int m[][c])
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nInserisci un numero: ");
			scanf("%d",&m[i][j]);
		}	
	}

}

void stampa(int r, int c, int m[][c])
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d",m[i][j]);
		}
	printf("\n");
	}
}


void trasposta(int r, int c, int m[][c])
{
	int i,j;
	for(j=0;j<c;j++)
	{
		for(i=0;i<r;i++)
		{
			printf("%d",m[i][j]);
		}
	printf("\n");
	}

}

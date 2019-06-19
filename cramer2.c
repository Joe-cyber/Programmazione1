/*Scrivere un programma che risolve un sistema di equazioni a due incognite utilizzando il metodo
di Cramer.*/
#include <stdio.h>
void acquisizione_sistema(int[][3]);
void stampa(int[][3]);
int cramer(int[][3],int, int);
int main(void)
{
	int m[2][3],x,y,determinante;
	acquisizione_sistema(m);
	stampa(m);
	determinante=cramer(m,0,1);
	printf("X: %d/%d\n",cramer(m,2,1),determinante);
	printf("Y: %d/%d",cramer(m,0,2),determinante);


return 0;
}

int cramer(int m[][3],int i, int j)
{
	return ((m[0][i]*m[1][j])-(m[1][i]*m[0][j]));
}

void acquisizione_sistema(int m[][3])
{
	int r,c,cont=1;
	for(r=0;r<2;r++)
	{
		for(c=0;c<3;c++)
		{
			printf("\nInserisci il [%d] valore: ",cont);
			scanf("%d",&m[r][c]);
			cont++;
		}
	}
}


void stampa(int m[][3])
{
	printf("%dx + %dy = %d",m[0][0],m[0][1],m[0][2]);
	printf("\n");
	printf("%dx + %dy = %d",m[1][0],m[1][1],m[1][2]);
	printf("\n");
}

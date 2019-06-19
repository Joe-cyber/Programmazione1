/*Scrivere un programma che risolve un sistema di equazioni a due incognite utilizzando il metodo
di Cramer.*/
#include <stdio.h>
void acquisizione_sistema(int[][3]);
void stampa(int[][3]);
int calcolo_determinante(int[][3]);
int calcolo_x(int[][3]);
int calcolo_y(int[][3]);
int main(void)
{
	int m[2][3],x,y,determinante;
	acquisizione_sistema(m);
	stampa(m);
	determinante=calcolo_determinante(m);
	printf("X: %d/%d\n",calcolo_x(m),determinante);
	printf("Y: %d/%d",calcolo_y(m),determinante);


return 0;
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

int calcolo_determinante(int m[][3])
{
	return (m[0][0]*m[1][1])-(m[0][1]*m[1][0]);
}

int calcolo_x(int m[][3])
{
	return (m[0][2]*m[1][1])-(m[1][2]*m[0][1]);
}

int calcolo_y(int m[][3])
{
	return (m[0][0]*m[1][2])-(m[0][2]*m[1][0]);
}

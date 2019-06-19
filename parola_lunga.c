#include<stdio.h>
#define l 50

void acquisisci_frase(char[]);
int trova_parola(char[]);
void stampa_parola(char[], int);

int main(void)
{
	char frase[l];
	printf("Inserisci una frase: ");
	acquisisci_frase(frase);
	stampa_parola(frase,trova_parola(frase));
	printf("\n");
	return 0;
}

void acquisisci_frase(char v[])
{
	int i;
	v[0]='*';
	for(i=0;(i<l)&&(v[i-1]!='\n');i++)
		v[i]=getchar();
}

int trova_parola(char v[])
{
	int i,j,l_parola=0,inizio;
	for(i=0;(i<l)&&(v[i-1]!='\n');i=j+1)
	{
		for(j=i+1;(j<l)&&(v[j]!='\n')&&(v[j]!=' ');j++);
		if((j-i)>l_parola)
		{
			l_parola=j-i;
			inizio=i;
		}
	}
	return inizio;
}

void stampa_parola(char v[], int i)
{
	for(;(i<l)&&(v[i]!='\n')&&(v[i]!=' ');i++)
		printf("%c", v[i]);
}


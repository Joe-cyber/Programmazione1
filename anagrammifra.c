#include <stdio.h>
int main(void)
{
	char a[10]={'*','*','*','*','*','*','*','*','*','*'}, b[10]={'*','*','*','*','*','*','*','*','*','*'};
	int i=0,k;

	printf("\nInserisci la prima parola: ");
	while((a[i]=getchar()) != '\n')
	{
		i++;	
	}
	
	i=0;

	printf("\n Inserisci la seconda parola: ");
	while((b[i]=getchar()) != '\n')
	{
		i++;
	}

	for(i=0;i<10;i++)
	{
		for(k=0;k<10;k++)
		{
			if(b[i]==a[k])
			{
				a[k]='*'; //si controlla lettera per lettera e se sono uguali si mette l'asterisco
				break;
			}
		}
	}
	
	for(i=0;i<10;i++)
		if(a[i]!='*')
			break; //appena trova qualcosa di diverso dall'asterisco esco dal ciclo

	if(i==10)
		printf("\nLe parole sono anagrammi\n");
	else
		printf("\nLe parole non sono anagrammi\n");






	return 0;
}

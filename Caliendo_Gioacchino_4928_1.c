#include<stdio.h>
void itoa(int n, char *s);
int main(void)
{
	int n;
	char str[33];
	printf("Inserire un numero: ");
	scanf("%d",&n);
	itoa(n,str);
	printf("%s\n",str);
	return 0;
}
void itoa(int n, char *s)
{
	char* p=s,*q,*fine=s;//p funzionerà come indice dell'array, q verrà usato per eseguire lo shift, fine indicherà la fine della stringa
	if(n==0)
	{
		*p='0';
		fine++;
	}
	if(n<0)//converti in positivo e colloco il carattere - all'interno della stringa se il numero passato alla funzione è negativo
	{
		n*=-1;
		*p++='-';
		fine++;
	}
	while(n)//divido a cascata prendendo di volta in volta il resto e posizionandolo nella prima cella dell'array
	{
		*p=n%10+'0';
		n/=10;
		fine++;
		if(!n)
			break;
		else	//eseguo lo shift a destra dei caratteri numerici precedentemente inseriti all'interno dell'array solo se alla prossima iterazione il controllo risultasse positivo
			for(q=fine;q!=p;q--)
				*q=*(q-1);
	}
	*fine='\0';//chiudo la stringa col carattere di controllo '\0'
}

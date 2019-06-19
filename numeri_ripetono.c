#include<stdio.h>
typedef int BOOL;
#define true 1;
#define false 0;
int main(void)
{
	int i, v[10]={0};
	char n;
	BOOL ripete=false;
	printf("Inserisci un numero: ");
	do{
		n=getchar();
		if((n>='0')&&(n>='9'))
			v[(int)n-'0']++;
		printf("%d",(int)n-'0');
	}while(n!='\n');
	for(i=0;i<10;i++)
	{
		printf("%d",v[i]);
		if(v[i]>1)
			ripete=true;
	}
	if(ripete)
		printf("Ci sono numeri che si ripetono\n");
	else
		printf("Non ci sono numeri che si ripetono\n");
	return 0;
}

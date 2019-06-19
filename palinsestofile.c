/*Scrivere un programma palinsesto che permetta di esaminare la programmazione giornaliera di un canale tv memorizzata in un database palinsesto.db. 
Il programma può essere usato in due modi.
Con 1 parametro: prende in input da linea di comando un orario nel formato hh:mm.
Esaminando il database, stamperà il programma tv che risulta essere in onda all’orario indicato.
Con 2 parametri: prende in input da linea di comando un orario nel formato hh:mm e un programma tv. 
Esaminando il database, stamperà il numero di minuti che mancano alla prossima messa in onda del programma tv indicato, a partire dall’ora specificata. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //serve per fare la funzione exit
#include <ctype.h>
void termina();
int main(int argc, char* argv[])
{
	FILE *fp;
	char ora1[6],ora2[6];
	char s1[200],programma[20];
	if((argc<2) || (argc>3))
		termina();	
	if((fp=fopen("palinsesto.txt","r")) == NULL)
	{
		fprintf(stderr,"Il file non puo essere letto.\n");
		return 0;
	
	}
	while(fgets(s1,200,fp))
	{
		sscanf(s1,"%[:0123456789] - %[:0123456789] %[^'\n']",ora1,ora2,programma);	
		if((argc==2) && (strcmp(ora1,argv[1])<=0) && ((strcmp(ora2,argv[1])>0)))
			printf("%s\n",programma);	
		if((argc==3) && (strcmp(ora1,argv[1])>=0) && (strncmp(programma,argv[2],strlen(argv[2]))==0))
		{	printf("%d\n",((atoi(ora1)*60)+atoi(ora1+3))-((atoi(argv[1])*60)+atoi(argv[1]+3)));	
			break;
		}				
	}


fclose(fp);
return 0;
}


void termina()
{
	fprintf(stderr,"Uso: <hh:mm>\nUso: <hh:mm> <programma tv>\n");
	exit(EXIT_FAILURE); //può essere usata anche con una condizione dentro

}

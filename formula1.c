#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void termina(void);
int main(int argc,char* argv[])
{
	FILE* fp;
	char line[128],nome[16],cognome[16],scuderia[32],scuderia_parziale[16];
	int punti,somma_punti=0,posizione=0,posizione_pilota,punti_posizione,punti_pilota,stampa=0;
	if((argc<2)||(argc>3))
		termina();
	if((fp=fopen("classifica.txt","r"))==NULL)
	{
		fprintf(stderr,"Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(line,128,fp))
	{
		sscanf(line,"%[^ ] %[^ ] %*[^ ] %[^0123456789] %d",nome, cognome, scuderia, &punti);
		//punto 3
		sscanf(scuderia,"%[^ ]",scuderia_parziale);
		if((strlen(scuderia_parziale)<strlen(argv[1]))&&(strncmp(scuderia,argv[1],strlen(argv[1]))==0))
		{
			somma_punti+=punti;
			stampa=3;
		}
		//punto 1
		posizione++;
		if((((argc==2)&&(strcmp(cognome,argv[1]))==0))||((argc==3)&&((strcmp(nome,argv[1]))==0)&&((strcmp(cognome,argv[2]))==0)))
		{
			posizione_pilota=posizione;
			punti_pilota=punti;
			stampa=1;
		}
		//punto 2
		if((argc==3)&&(atoi(argv[2])==posizione))
		{
			punti_posizione=punti;
			stampa=2;
		}
		if((argc==3)&&((strcmp(cognome,argv[1]))==0))
			punti_pilota=punti;
	}
	if(!stampa)
		termina();
	else if(stampa==1)
		printf("%d. %d\n",posizione_pilota, punti_pilota);
	else if(stampa==2)
		printf("%d\n",punti_pilota-punti_posizione);
	else if(stampa==3)
		printf("%d\n",somma_punti);
	fclose(fp);
	return 0;
}

void termina()
{
	fprintf(stderr,"Uso: formula1 <scuderia>\nUso: formula1 <nome pilota>\nUso: formula1 <nome pilota> <intero>\n");
	exit(EXIT_FAILURE);
}

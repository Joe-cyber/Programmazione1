#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void concatena(char*, char*,int);
void sostituisci(int*,int,char*,char*,int);
char* itoa(int n, char *s);
int main(int argc,char*argv[])
{
	FILE* fp;
	char line[128],nome_squadra[16],primo_classificato[16]="",vittorie[128]="",pareggi[128]="",sconfitte[128]="";
	int punti_primoc=0,morev=0,morep=0,mores=0,punti,v,p,s;
	if(argc!=2)//termino il programma se è stato inserito un numero errato di parametri o se non è possibile aprire il file
	{
		fprintf(stderr,"Uso: Classifica {s,v,n,p}\n");
		exit(EXIT_FAILURE);
	}
	if((fp=fopen("classifica.txt","r"))==0)
	{
		fprintf(stderr,"Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(line,128,fp))//leggo dal file riga per riga
	{
		if(strlen(line)==0)//ignoro tutte le eventuali righe bianche
			continue;
		sscanf(line,"%[^,], %d %*d %d %d %d",nome_squadra,&punti,&v,&p,&s); //leggo la riga memorizzando il nome della squadra e il suo storico partite
		//calcolo il primo classificato
		if(punti>punti_primoc)
		{
			strcpy(primo_classificato,nome_squadra);
			punti_primoc=punti;
		}
		//calcolo le squadre con più vittorie
		if(v>morev)
			sostituisci(&morev,v,vittorie,nome_squadra,v);
		else if(v==morev)
			concatena(vittorie,nome_squadra,v);
		//calcolo le squadre con più pareggi
		if(p>morep)
			sostituisci(&morep,p,pareggi,nome_squadra,p);
		else if(p==morep)
			concatena(pareggi,nome_squadra,p);
		//calcolo le squadre con più sconfitte
		if(s>mores)
			sostituisci(&mores,s,sconfitte,nome_squadra,s);
		else if(s==mores)
			concatena(sconfitte,nome_squadra,s);
	}
	//eseguo una sola stampa in base alla richiesta dell'utente
	if(strcmp("s",argv[1])==0)
		printf("%s %d\n",primo_classificato,punti_primoc);
	else if(strcmp("v",argv[1])==0)
		printf("%s",vittorie);
	else if(strcmp("n",argv[1])==0)
		printf("%s",pareggi);
	else if(strcmp("p",argv[1])==0)
		printf("%s",sconfitte);
	fclose(fp);
	return 0;
}
//utilizzo la itoa precedentemente scritta e opportunamente modificata per scrivere come stringa i numeri interi letti da file
char *itoa(int n, char *s)
{
	char* p=s,*q,*fine=s;
	if(n==0)
	{
		*p='0';
		fine++;
	}
	if(n<0)
	{
		n*=-1;
		*p++='-';
		fine++;
	}
	while(n)
	{
		*p=n%10+'0';
		n/=10;
		fine++;
		if(!n)
			break;
		else
			for(q=fine;q!=p;q--)
				*q=*(q-1);
	}
	*fine='\0';
	return s;
}
void sostituisci(int *max,int n,char* dest,char* prov,int p)
{
	char app[4];
	*max=n;
	strcpy(dest,prov);
	strcat(dest," ");
	strcat(dest,itoa(p,app));
	strcat(dest,"\n");
}
void concatena(char* dest, char* prov,int p)
{
	char app[4];
	strcat(dest,prov);
	strcat(dest," ");
	strcat(dest,itoa(p,app));
	strcat(dest,"\n");
}

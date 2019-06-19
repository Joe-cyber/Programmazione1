#include<stdio.h>
#include<string.h>
#define p1 "PROGRAMMA1"
#define p2 "PROGRAMMA2"
#define p3 "PROGRAMMA3"
int somma(void);
int media(void);
int fattoriale(void);
int main(int argc,char*argv[])
{

	if((argc==2)&&(strcmp(argv[1],"ls")==0))
		fprintf(stdout,"PROGRAMMA1\nPROGRAMMA1 PROGRAMMA2\nPROGRAMMA1 PROGRAMMA2 PROGRAMMA3\n");
	else if(argc==2)
	{
		if(strcmp(argv[1],p1)==0)
			fprintf(stdout,"%d\n",somma());
		else if(strcmp(argv[1],p2)==0)
			fprintf(stdout,"%d\n",media());
		else if(strcmp(argv[1],p3)==0)
			fprintf(stdout,"%d\n",fattoriale());
	}
	else if(argc==3)
	{
		if((strcmp(argv[1],p1)==0)||(strcmp(argv[2],p1)==0))
			fprintf(stdout,"%d\n",somma());
		if((strcmp(argv[1],p2)==0)||(strcmp(argv[2],p2)==0))
			fprintf(stdout,"%d\n",media());
		if((strcmp(argv[1],p3)==0)||(strcmp(argv[2],p3)==0))
			fprintf(stdout,"%d\n",fattoriale());
	}
	else if(argc==4)
	{
		if((strcmp(argv[1],p1)==0)||(strcmp(argv[2],p1)==0)||(strcmp(argv[3],p1)==0))
			fprintf(stdout,"%d\n",somma());
		if((strcmp(argv[1],p2)==0)||(strcmp(argv[2],p2)==0)||(strcmp(argv[3],p2)==0))
			fprintf(stdout,"%d\n",media());
		if((strcmp(argv[1],p3)==0)||(strcmp(argv[2],p3)==0)||(strcmp(argv[3],p3)==0))
			fprintf(stdout,"%d\n",fattoriale());
	}
	else
		fprintf(stderr,"Errore, numero di parametri sbagliato\n");
}

int somma(void)
{
	int n1,n2;
	fprintf(stdout,"Inserisci un numero: ");
	fscanf(stdin,"%d",&n1);
	fprintf(stdout,"Inserisci un numero: ");
	fscanf(stdin,"%d",&n2);
	return (n1+n2);
}
int media(void)
{
	int n1,n2;
	fprintf(stdout,"Inserisci un numero: ");
	fscanf(stdin,"%d",&n1);
	fprintf(stdout,"Inserisci un numero: ");
	fscanf(stdin,"%d",&n2);
	return ((n1+n2)/2);
}
int fattoriale(void)
{
	int n1,i,fatt=1;
	fprintf(stdout,"Inserisci un numero: ");
	fscanf(stdin,"%d",&n1);
	for(i=n1;i>0;i--)
		fatt*=i;
	return fatt;
}

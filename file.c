#include<stdio.h>
int main(int argc,char*argv[])
{
	FILE* fp;
	int n1,n2;
	if(argc!=2)
		fprintf(stderr,"Numero di parametri sbagliato\n");
	else
	{
		if((fp=fopen(argv[1],"r"))==NULL)
			fprintf(stderr,"File non trovato\n");
		else
		{
			fscanf(fp,"%d %d",&n1,&n2);
			fclose(fp);
			if((fp=fopen("fout.txt","w"))==NULL)
				fprintf(stderr,"Impossibile creare il file\n");
			else
			{
				fprintf(fp,"La somma e': %d",n1+n2);
				fclose(fp);
				fprintf(stdout,"Risultato scritto all'interno del file fout.txt\n");
			}
		}
	}
	return 0;
}

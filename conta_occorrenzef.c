#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[])
{
	FILE* fp;
	char str[50];
	int cont=0;
	if(argc!=3)
		fprintf(stderr,"Numero di parametri sbagliato\n");
	else
	{
		if((fp=fopen(argv[1],"r"))==NULL)
			fprintf(stderr,"Impossibile aprire il file %s\n",argv[1]);
		else
		{
			while((fscanf(fp,"%s",str))&&(!feof(fp)))
				if((strcmp(str,argv[2]))==0)
					cont++;
			printf("La parola %s e' contenuta %d volte all'interno del file %s\n",argv[2],cont,argv[1]);
			fclose(fp);
		}
	}
	return 0;
}

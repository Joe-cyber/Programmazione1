#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[])
{
	FILE* fp;
	char line[128],nome_citta[32],pioggia[5],appoggio[128];
	int max, min, probabilita, minf=100, maxf=0,app;
	if((argc<2)||(argc>4))
	{
		printf("meteo <nome citta'>\nmeteo <temperatura1> <temperatura2> <min/max>\nmeteo <minima>\nmeteo <massimo>\n");
		exit(EXIT_FAILURE);
	}
	if((fp=fopen("temperature.txt","r"))==NULL)
	{
		printf("Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(line,128,fp))
	{
		sscanf(line,"%[^123456789]%d/%d %[^'\n']",nome_citta,&min,&max,pioggia);
		if(strncmp(nome_citta,argv[1],strlen(argv[1]))==0)
			printf("%s minima: %d\tmassima: %d\tpioggia: %d%%\n", nome_citta,min,max,(int)(25*strlen(pioggia)));
		if(minf>min)
			minf=min;
		else if(maxf<max)
			maxf=max;
		if(argc==4)
		{

			if(strcmp(argv[3],"max")==0)			
				if((max>=atoi(argv[1]))&&(max<=atoi(argv[2])))
					printf("%s\n",nome_citta);
			if(strcmp(argv[3],"min")==0)			
				if((min>=atoi(argv[1]))&&(min<=atoi(argv[2])))
					printf("%s\n",nome_citta);

		}
		
	}
	rewind(fp);
	if(strcmp(argv[1],"massima")==0)
		while(fgets(line,128,fp))
		{
			sscanf(line,"%[^123456789]%*d/%d",nome_citta,&max);
			if(max==maxf)
				printf("%s\n",nome_citta);
		}
	else if(strcmp(argv[1],"minima")==0)
		while(fgets(line,128,fp))
		{
			sscanf(line,"%[^123456789]%d",nome_citta,&min);
			if(min==minf)
				printf("%s\n",nome_citta);
		}
	fclose(fp);
}

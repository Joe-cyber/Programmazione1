/*Scrivere un programma che permette queste operazioni sul file:
-prende in ingresso il nome di una montagna e ne restituisce l'altezza;
-prende in ingresso due altezze e stampa i nomi delle montagne con altezza compresa dalle due inserite;
-preso in ingresso il nome di un Paese, restituisce i nomi delle montagne situate in quel Paese;
-preso in ingresso il comando HIGHEST e il nome di un Paese, restituisce il nome della montagna più alta di quel paese e la sua altezza;
-prevedere anche il comando LS per visualizzare le opzioni.*/
#include <stdio.h>
#include <string.h>
void create_string(char*, int, char*[]);
int main(int argc, char*argv [])
{
	FILE *fp;
	char s1[200]="",s2[200];
	char montagnaf[100], pnome[100], snome[100];
	int altezza1,altezza2,altezzaf,n;
	
	if(argc<2)
	{
		fprintf(stderr,"Numero di parametri errato.\n");
		return 0;
	}
	if(strcmp(argv[1],"ls")==0)
	{
		printf("<nome montagna>\n<altezza1> <altezza2>\n<nome Paese>\nHIGHEST <nome Paese>\n");
	}
	create_string(s1,argc,argv);
	if((fp=fopen("dbmontagne.txt","r")) == NULL)
	{	
		fprintf(stderr,"Errore, il file non puo essere letto.\n");
		return 0;
	}

	if(sscanf(s1,"%d %d",&altezza1,&altezza2)==2)
	{
		while(fgets(s2,200,fp))
		{
			sscanf(s2,"%*d %[^:]: %d",montagnaf,&altezzaf);
			if((altezza1>=altezzaf) && (altezza2<=altezzaf))
				printf("%s\n",montagnaf);
		}
	}
	
	else if(strcmp(argv[1],"HIGHEST")==0)
	{
		while(fgets(s2,200,fp))
		{
			if((sscanf(s2,"%*d %[^:]: %d m %[^,'\n'], %[^'\n']",montagnaf,&altezzaf,pnome,snome)==4))
			{
				if((strcmp(pnome,s1+8)==0) || (strcmp(snome,s1+8)==0))
				{
					printf("Monte piu alto: %s\nAltezza: %d\n",montagnaf,altezzaf);
					break; //perchè il file contiene già le montagne dalla più alta alla più bassa quindi basta trovare la prima
				}
			}
			else
			{ 
				if(strcmp(pnome,s1+8)==0)
				{
					printf("Monte piu alto: %s\nAltezza: %d\n",montagnaf,altezzaf);
					break; //perchè il file contiene già le montagne dalla più alta alla più bassa quindi basta trovare la prima
				}			
			}	
				
					
		}	
	}
	
	else
	{
		while(fgets(s2,200,fp))
		{

			n=sscanf(s2,"%*d %[^:]: %d m %[^,'\n'], %[^'\n']",montagnaf,&altezzaf,pnome,snome);
			if(strcmp(s1, montagnaf)==0)
				printf("Altezza: %d\n",altezzaf);
			if(n==4)
			{
				if((strcmp(s1,pnome)==0) || (strcmp(s1,snome)==0))
					printf("%s\n",montagnaf);
			}
			else
			{
				if(strcmp(s1,pnome)==0)
					printf("%s\n",montagnaf);
			}
		
		}
	}
	
	

fclose(fp);
return 0;
}

void create_string(char *s1, int argc, char* argv[])
{
	int i;
	for(i=1;i<argc;i++)
	{
		strcat(s1,argv[i]);
		if(i<argc-1)
			strcat(s1," ");	
	}
}

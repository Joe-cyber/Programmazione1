#include<stdio.h>
#include<string.h>
int str_to_int(char*);
void create_string(char*,int,char*[]);
int main(int argc,char* argv[])
{
	FILE* fp;
	char str[256]="",str2[256];
	int date,stampa=0;
	if(argc<2)
		fprintf(stderr,"Numero di parametri insufficiente\n");
	else
	{
		if((fp=fopen("albof1.txt","r"))==NULL)
			fprintf(stderr,"Impossibile aprire il file\n");
		else
		{
			if(date=str_to_int(argv[1]))
			{
				while(!feof(fp))
				{
					fgets(str2,256,fp);
					if(date==str_to_int(str2))
					{
						printf("\n");
						puts(str2+5);
						break;
					}
				}
				if(feof(fp))
					printf("\nData non presente all'interno del file\n\n");
			}
			else
			{
				create_string(str,argc,argv);
				while(!feof(fp))
				{
					fgets(str2,256,fp);
					if((strncmp(str,str2+5,strlen(str)))==0)
					{
						printf("%.5s\n",str2);
						stampa=1;
					}
				}
				if(!stampa)
					printf("Non ci sono piloti con quel nome nell'albo\n");
			}
			fclose(fp);
		}
	}	
	return 0;
}
int str_to_int(char* s)
{
	int acc=0;
	while((*s>='0')&&(*s<='9'))
	{	
		acc=acc*10+(*s-'0');
		s++;
	}
	return acc;
}

void create_string(char* s,int n,char* v[])
{
	int i=0;
	for(i=1;i<n;i++)
	{
		strcat(s,v[i]);
		if(i<n-1)
			strcat(s," ");
	}
}




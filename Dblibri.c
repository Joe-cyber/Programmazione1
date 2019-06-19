#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FILE_NAME "dblibri.txt"
void create_string(char*,int,char*[]);
int main(int argc,char* argv[])
{
	FILE* fp;
	int data1,data2;
	char str[256]="";
	if(argc<2)
	{
		fprintf(stderr,"Numero di parametri errato:\nDblibri <autore>\nDblibri <data> <data>\nDblibri <titolo libro>\n");
		exit(EXIT_FAILURE);
	}
	if((fp=fopen(FILE_NAME,"r"))==NULL)
	{
		fprintf(stderr,"Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}
	if((sscanf(argv[1],"%d",&data1))&&(sscanf(argv[2],"%d",&data2)))
	{
	}
	else
	{
		create_string(str,argc,argv);
		puts(str);
	}
}

void create_string(char* s,int n,char* v[])
{
	int i;
	for(i=1;i<n;i++)
	{
		strcat(s,v[i]);
		if(i<n-1)
			strcat(s," ");
	}
}

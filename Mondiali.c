#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILE_NAME "albo.txt"
int calcolo_totale(char,char,char);
int main(int argc,char* argv[])
{
	FILE* fp;
	char command[64], str[256], nazione[32], maxoro[32], maxargento[32], maxbronzo[32], maxtot[32], first, second, third, fourth, maxo=0, maxa=0, maxb=0, maxp=0;
	int tot=0,app;
	if((argc!=2)&&(argc!=3))
	{
		printf("Mondiali <Nazione>\nMondiali <max> {<oro><argento><bronzo>totale>}\n");
		exit(EXIT_FAILURE);
	}
	strcpy(command,argv[1]);
	if((fp=fopen(FILE_NAME,"r"))==NULL)
	{
		fprintf(stderr,"Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(str,256,fp))
	{
		sscanf(str,"%[^123456789-]%c %c %c %c",nazione,&first,&second,&third,&fourth);
		if(strncmp(argv[1],nazione,strlen(argv[1]))==0)
		{
			tot=calcolo_totale(first,second,third);
			printf("%s %c    %c    %c    %c    (%d)\n",nazione,first,second,third,fourth,tot);
		}
		if(first>maxo)
		{
			strcpy(maxoro,nazione);
			maxo=first;
		}
		if(second>maxa)
		{
			strcpy(maxargento,nazione);
			maxa=second;
		}
		if(third>maxb)
		{	
			strcpy(maxbronzo,nazione);
			maxb=third;
		}
		if((app=calcolo_totale(first,second,third))>maxp)
		{
			strcpy(maxtot,nazione);
			maxp=app;
		}
	}
	if(argc==3)
	{
		if(strcmp("oro",argv[2])==0)
			printf("%s%c\n",maxoro,maxo);
		else if(strcmp("argento",argv[2])==0)
			printf("%s%c\n",maxargento,maxa);
		else if(strcmp("bronzo",argv[2])==0)
			printf("%s%c\n",maxbronzo,maxb);
		else if(strcmp("totale",argv[2])==0)
			printf("%s%d\n",maxtot,maxp);
	}
	fclose(fp);
	return 0;
}
int calcolo_totale(char first,char second,char third)
{
	int tot=0;
	if(first!='-')
		tot+=(first-'0');
	if(second!='-')
		tot+=(second-'0');
	if(third!='-')		
		tot+=(third-'0');
	return tot;
}


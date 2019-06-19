#include<stdio.h>
int main(int argc,char* argv[])
{
	FILE* fp;
	int m[5][5],i=0,j,n;
	if(argc!=2)
		fprintf(stderr,"Numero di parametri errato\n");
	else if((fp=fopen(argv[1],"r"))==NULL)
		fprintf(stderr,"Impossibile aprire il file %s\n",argv[1]);	
	else
	{
		while((fscanf(fp,"%d%d%d%d%d",&m[i][0],&m[i][1],&m[i][2],&m[i][3],&m[i][4]))&&(!feof(fp)))
			i++;		
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				printf("%d\t",m[j][i]);
			printf("\n");
		}
		fclose(fp);
	}
	return 0;
}

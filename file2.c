#include<stdio.h>
#include<string.h>
void subreverse(char*);
int main(int argc,char*argv[])
{
	FILE* fp;
	char str[100];
	if(argc!=2)
		fprintf(stderr,"Numero di parametri errato\n");
	else
	{
		if((fp=fopen(argv[1],"r+"))==NULL)
			fprintf(stderr,"Impossibile trovare il file\n");
		else
		{
			fgets(str,100,fp);
			subreverse(str);
			rewind(fp);
			fputs(str,fp);
			fclose(fp);
		}
	}
	return 0;
}

void subreverse(char* s)
{
	char*p=s,*q,*w,temp;
	while(*p)
	{
		while(((*p<'0')||(*p>'9'))&&(*p))
			p++;
		if(*p)
		{
			q=p;
			while((*q>='0')&&(*q<='9'))
				q++;
			w=q-1;
			while(p<w)
			{	
				temp=*p;
				*p=*w;
				*w=temp;
				p++;
				w--;
			}
			p=q;
		}
		p++;
	}
}

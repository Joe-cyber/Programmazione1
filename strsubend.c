#include<stdio.h>
int strsubend(char*,char*,char*);
int str_len(char*);
char* strend(char*);
int main(int argc,char*argv[])
{
	if(argc!=4)
		fprintf(stderr,"Errore numero di parametri errato, inserire 3 parole\n");
	else
	{
		if(strsubend(argv[1],argv[2],argv[3]))
		{
			fputs(argv[1],stdout);
			printf("\n");
		}
		else
			fprintf(stdout,"La sostituzione non è avvenuta\n");
	}
	return 0;
}
int strsubend(char* s,char* t, char* r)
{
	char*p,*q;
	if(str_len(t)!=str_len(r))
		return 0;
	if(str_len(s)>str_len(t))
	{
		for(p=strend(s),q=strend(t);((*p==*q)&&(q>=t));p--,q--);
		q++;
		if(q!=t)
			return 0;
		for(p++;*r;r++,p++)
			*p=*r;
		return 1; 
	}
	return 0;
}
int str_len(char* s)
{
	char*p=s;
	while(*p)
		p++;
	return p-s;
}
char* strend(char* s)
{
	while(*s)
		s++;
	return --s;
}


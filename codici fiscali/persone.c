#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char* calcolo_cognome(char*,char*);
char* calcolo_nome(char*,char*);
char calcolo_mese(int);
void calcolo_carattere16(char*);
int main(int argc,char* argv[])
{
	FILE* fp1,*fp2;
	char line[128], sesso, nome[32], cognome[32], comune_nascita[32], GG[3], MM[3], AAAA[5],*p,codice_fiscale[17]="",caratteri[5];
	if((argc<2)||(argc>3))
	{
		fprintf(stderr,"Numero di parametri errato\n");
		exit(EXIT_FAILURE);
	}
	if(((fp1=fopen("dbpersone.txt","r"))==NULL)||((fp2=fopen("codici_catastali.txt","r"))==NULL))
	{
		fprintf(stderr,"Impossibile aprire uno dei file\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(line,64,fp1))
	{
		sscanf(line,"(%c) %[^ ] %[^0123456789]%[^/]/%[^/]/%[^ ] %[^'\n']",&sesso, nome, cognome, GG, MM, AAAA, comune_nascita);
		if(strncmp(comune_nascita,argv[1],strlen(argv[1]))==0)
			printf("%s %s %s-%s-%s\n",nome, cognome,GG,MM,AAAA);
		if((argc==3)&&(atoi(argv[1])))
			if((strcmp(AAAA,argv[1])>=0)&&(strcmp(AAAA,argv[2])<=0))
				printf("%s %s\n",nome,cognome);
		if((argc==3)&&(strcmp(argv[1],nome)==0)&&((strncmp(argv[2],cognome,strlen(argv[2])))==0))
		{
			strcat(codice_fiscale,calcolo_cognome(cognome,caratteri));
			strcat(codice_fiscale,calcolo_nome(nome,caratteri));
			strcat(codice_fiscale,AAAA+2);
			codice_fiscale[strlen(codice_fiscale)+1]='\0';
			codice_fiscale[strlen(codice_fiscale)]=calcolo_mese(atoi(MM));
			if(sesso=='F')
				*GG+=4;
			strcat(codice_fiscale,GG);
			while(fgets(line,64,fp2))
				if(strncmp(line,comune_nascita,strlen(comune_nascita))==0)
					sscanf(line,"%*[^,], %s",caratteri);
			strcat(codice_fiscale,caratteri);
			calcolo_carattere16(codice_fiscale);
			puts(codice_fiscale);
		}
	}
	rewind(fp2);
	while(fgets(line,64,fp2))
		if(strncmp(line,argv[1],strlen(argv[1]))==0)
		{
			for(p=line;*p!=',';p++);
			p++;
			printf("Codice catastale: %s",p);
		}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
char* calcolo_cognome(char* c,char* s)
{
	char *p;
	int i=0;
	for(p=c;((*p)&&(i<3));p++)
		if((*p!='a')&&(*p!='e')&&(*p!='i')&&(*p!='o')&&(*p!='U')&&(*p!=' '))
		{
			s[i]=toupper(*p);
			i++;
		}
	if(i<3)
		for(p=c;((*p)&&(i<3));p++)
		{
			if((*p=='a')&&(*p=='e')&&(*p=='i')&&(*p=='o')&&(*p=='u'))
			{
				s[i]=toupper(*p);
				i++;
			}
		}
	if(i<3)
		for(;i<4;i++)
			s[i]='X';
	s[3]='\0';
	return s;
}
char* calcolo_nome(char* c,char* s)
{
	char *p;
	int i=0,j;
	for(p=c;((*p)&&(i<4));p++)
		if((*p!='a')&&(*p!='e')&&(*p!='i')&&(*p!='o')&&(*p!='U')&&(*p!=' '))
		{
			s[i]=toupper(*p);
			i++;
		}
	if(i<3)
		for(p=c;((*p)&&(i<3));p++)
			if((*p=='a')&&(*p=='e')&&(*p=='i')&&(*p=='o')&&(*p=='U'))
			{
				s[i]=toupper(*p);
				i++;
			}
	if(i<3)
		for(;i<4;i++)
			s[i]='X';
	if(i==4)
		for(j=1;j<4;j++)
			s[j]=s[j+1];
	s[3]='\0';
	return s;
}

char calcolo_mese(int n)
{
	return " ABCDEHLMPRST"[n];
}

void calcolo_carattere16(char* s)
{
	int c16=0,i;
	for(i=0;i<15;i+=2)
		switch(*(s+i))
		{
			case 'A':
			case '0':
				c16+=1;
			break;
			case '1':
			case 'B':
				c16+=0;
			break;
			case 'C':
			case '2':
				c16+=5;
			break;
			case 'D':
			case '3':
				c16+=7;
			break;
			case 'E':
			case '4':
				c16+=9;
			break;
			case 'F':
			case '5':
				c16+=13;
			break;
			case 'G':
			case '6':
				c16+=15;
			break;
			case 'H':
			case '7':
				c16+=17;
			break;
			case 'I':
			case '8':
				c16+=19;
			break;
			case 'J':
			case '9':
				c16+=21;
			break;
			case 'K':
				c16+=2;
			break;
			case 'L':
				c16+=4;
			break;
			case 'M':
				c16+=18;
			break;
			case 'N':
				c16+=20;
			break;
			case 'O':
				c16+=11;
			break;
			case 'P':
				c16+=3;
			break;
			case 'Q':
				c16+=6;
			break;
			case 'R':
				c16+=8;
			break;
			case 'S':
				c16+=12;
			break;
			case 'T':
				c16+=14;
			break;
			case 'U':
				c16+=16;
			break;
			case 'V':
				c16+=10;
			break;
			case 'W':
				c16+=22;
			break;
			case 'X':
				c16+=25;
			break;
			case 'Y':
				c16+=24;
			break;
			case 'Z':
				c16+=23;
			break;
		}
	for(i=1;i<15;i+=2)
		switch(*(s+i))
		{
			case 'A':
			case '0':
				c16+=0;
			break;
			case '1':
			case 'B':
				c16+=1;
			break;
			case 'C':
			case '2':
				c16+=2;
			break;
			case 'D':
			case '3':
				c16+=3;
			break;
			case 'E':
			case '4':
				c16+=4;
			break;
			case 'F':
			case '5':
				c16+=5;
			break;
			case 'G':
			case '6':
				c16+=6;
			break;
			case 'H':
			case '7':
				c16+=7;
			break;
			case 'I':
			case '8':
				c16+=8;
			break;
			case 'J':
			case '9':
				c16+=9;
			break;
			case 'K':
				c16+=10;
			break;
			case 'L':
				c16+=11;
			break;
			case 'M':
				c16+=12;
			break;
			case 'N':
				c16+=13;
			break;
			case 'O':
				c16+=14;
			break;
			case 'P':
				c16+=15;
			break;
			case 'Q':
				c16+=16;
			break;
			case 'R':
				c16+=17;
			break;
			case 'S':
				c16+=18;
			break;
			case 'T':
				c16+=19;
			break;
			case 'U':
				c16+=20;
			break;
			case 'V':
				c16+=21;
			break;
			case 'W':
				c16+=22;
			break;
			case 'X':
				c16+=23;
			break;
			case 'Y':
				c16+=24;
			break;
			case 'Z':
				c16+=25;
			break;
		}
		s[16]='\0';
		s[15]=c16%26+'A';
}










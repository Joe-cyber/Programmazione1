#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define r 8
#define c 9
char repeted_character(char[][c],int);
void set_rand_array(char[][c]);
void line_print(char[][c],int);
int main(void)
{
	char m[r][c],ch;
	int i;
	set_rand_array(m);
	for(i=0;i<r;i++)
		if((ch=repeted_character(m,i))!=';')
		{
			printf("La lettera %c si ripete a riga %d\n",ch,i);
			break;
		}
	line_print(m,i);
	return 0;
}

void set_rand_array(char m[][c])
{
	int n,i,j;
	srand(time(NULL));
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			m[i][j]=rand()%26+97;
}

char repeted_character(char m[][c], int i)
{
	int j,k;
	for(j=0;j<c-1;j++)
		for(k=j+1;k<c;k++)
			if(m[i][j]==m[i][k])
				return m[i][j];
	return ';';
}

void line_print(char m[][c],int i)
{
	int j;
	for(j=0;j<c;j++)
		printf("%c",m[i][j]);
	printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define FILE_NAME "dblibri.txt"
int main(int argc, char *argv[])
{
	int data1, data2, data_extr;
	FILE* fp;
	char str_nomelibro[50], file_date[20];


	if (argc>3){
		fprintf(stderr, "Uso: %s <data1> <data2>\n <nomeautore>\n <titololibro>", argv[0]);
		exit(EXIT_FAILURE);
	}
	if((fp=fopen(FILE_NAME, "r"))==NULL) {
		fprintf(stderr, "Impossibile aprire il file!");
		exit(EXIT_FAILURE);
	}


	if (argc==3) {
		sscanf(argv[1], "%d", &data1);
		sscanf(argv[2], "%d", &data2);
		while(fgets(file_date, sizeof(file_date), fp)) {
			sscanf(file_date, "%d", &data_extr);
			if(data_extr<=data1 && data_extr>=data2) {
				printf("%s", file_date);
				
			}
		}
	}
	


	

	return 0;
}





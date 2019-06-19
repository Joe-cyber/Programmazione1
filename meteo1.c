#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 256
#define file_name "temperature.txt"

int main(int argc, char *argv[])
{
	int n;
	char BUFF[MAX_LEN], LUOGO[50], ASTERISCO[5], RISULTATO[30]="\0", STRINGTEMP[30]="\0", MAXTEMP_STR[25]="\0";
	int maxx_temp,max_temp,min_temp,temp1=-1,temp2;
	FILE *fp;
	
	if((argc<2)||(argc>3)) {
	fprintf(stderr,"error");
	exit(EXIT_FAILURE);
	}
	 if((fp=fopen(file_name,"r"))==NULL) {
	 fprintf(stderr,"the file could not be opened");
	 exit(EXIT_FAILURE);
	 }
	    while(fgets(BUFF,sizeof(BUFF),fp)) {
	       n=sscanf(BUFF,"%[^123456789] %d/%d %[^'\n']\n",LUOGO,&max_temp,&min_temp,ASTERISCO);
		if(strncmp(argv[1],LUOGO,strlen(argv[1]))==0) {
		if(n==3) 
                  printf("%s %d/%d",LUOGO,max_temp,min_temp);
		else
                    if(n==4)
		        printf("%s %d/%d %s",LUOGO,max_temp,min_temp,ASTERISCO);
                   }

                     if(strncmp(argv[1],"max",strlen(argv[1]))==0) {
			  if(maxx_temp<max_temp) 
			       maxx_temp=max_temp;
			     strcpy(RISULTATO,LUOGO);
		         }
			    else {
			           (maxx_temp==max_temp)
			          strcat(RISULTATO,"\n");	
                                  strcat(RISULTATO,LUOGO);
			         }
		}







    fclose(fp);
 return 0;
}

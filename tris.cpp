#include<iostream>
#include<stdlib.h>
using namespace std;
void inizializza(char[][3]);
void stampa(char[][3],int,int,int);
bool controllo(char[][3],char);
bool righe(char[][3],char);
bool colonne(char[][3],char);
bool diagonale_principale(char[][3],char);
bool diagonale_secondaria(char[][3],char);
bool controllo2(char[][3],int&);
main()
{
	char v[3][3],segno,scelta;
	int giocatore=2,giocatore1=0,giocatore2=0,i,j;
	do{
		inizializza(v);
		do{
			system("cls");
			if(giocatore==2)
			{
				segno='X';
				giocatore=1;
			}
			else
			{
				segno='O';
				giocatore=2;
			}
			stampa(v,giocatore,giocatore1,giocatore2);
			do{
				do{
					cout<<endl<<"   Dammi la posizione della riga: ";
					cin>>i;
				}while((i>3)||(i<1));
				do{
					cout<<endl<<"   Dammi la posizione della colonna: ";
					cin>>j;
				}while((j>3)||(j<1));
				i--;j--;
			}while(v[i][j]!='*');
			v[i][j]=segno;
		}while(controllo(v,segno)&&controllo2(v,giocatore));
	system("cls");
	stampa(v,giocatore,giocatore1,giocatore2);
	if(giocatore!=-1)
	{
		cout<<endl<<"     Vince il giocatore "<<giocatore;
		if(giocatore==1)
			giocatore1++;
		else if(giocatore==2)
			giocatore2++;
	}
	else
		cout<<endl<<"     Non ha vinto nessuno";
	cout<<endl<<endl<<"   Vuoi fare un'altra partita?(S/N): ";
	cin>>scelta;
	}while((scelta=='s')||scelta=='S');
	system("cls");
	cout<<endl<<"     Giocatore 1: "<<giocatore1<<"    Giocatore 2: "<<giocatore2<<endl<<endl;
	system("pause");
}

void stampa(char v[][3],int g,int g1,int g2)
{
	cout<<"               TRIS"<<endl;
	cout<<endl<<"  Giocatore 1: "<<g1<<"    Giocatore 2: "<<g2<<endl<<endl;
	cout<<"       Tocca al giocatore "<<g<<endl<<endl;
	cout<<"            1   2   3"<<endl;
	cout<<"          +---+---+---+"<<endl;
	for(int k=0;k<3;k++)
	{
		cout<<"        "<<k+1<<" | "<<v[k][0]<<" | "<<v[k][1]<<" | "<<v[k][2]<<" |"<<endl;
		cout<<"          +---+---+---+"<<endl;
	}
}

void inizializza(char v[][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			v[i][j]='*';
	}
}

bool controllo(char v[][3],char s)
{
	bool risultato;
	risultato=righe(v,s);
	if(risultato==false)
		return risultato;
	risultato=colonne(v,s);
	if(risultato==false)
		return risultato;
	risultato=diagonale_secondaria(v,s);
	if(risultato==false)
		return risultato;
	risultato=diagonale_principale(v,s);
	return risultato;
}

bool righe(char v[][3],char c)
{
	for(int i=0;i<3;i++)
	{
		if((v[i][0]==v[i][1])&&(v[i][1]==v[i][2]))
		{
			if(v[i][0]==c)
				return false;
		}
	}
	return true;
}

bool colonne(char v[][3],char c)
{
	for(int j=0;j<3;j++)
	{
		if((v[0][j]==v[1][j])&&(v[1][j]==v[2][j]))
		{
			if(v[0][j]==c)
				return false;
		}
	}
	return true;
}

bool diagonale_principale(char v[][3],char c)
{
	if((v[0][0]==v[1][1])&&(v[1][1]==v[2][2]))
	{
		if(v[0][0]==c)
			return false;
	}
	else true;
}

bool diagonale_secondaria(char v[][3],char c)
{
	if((v[0][2]==v[1][1])&&(v[1][1]==v[2][0]))
	{
		if(v[0][2]==c)
			return false;
	}	
	else 
		return true;
}

bool controllo2(char v[][3],int& giocatore)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(v[i][j]=='*')
				return true;
	giocatore=-1;
	return false;
}

#include<stdlib.h>
#include<stdio.h>
#include"conio.h"
#include<time.h>
#include<string.h>
#define p printf
#define s scanf

typedef struct
{
int cod_art;
char nom_art[20];
float pre_art;
int sto_art;
float fact_art;
} regarti;

typedef struct
{
int cod_cli;
char nom_cli[20];
float cuenta;
}regcli ;


void inicio(FILE*,FILE*);
void ingresar(FILE*,FILE*);
void mostrarCli(FILE*);
void mostrarArt(FILE*);
int error(char*);
void linea(int);
void tecla(void);
int main()
{
	FILE *cli,*art;
	char nomarchcli[]="clientes.dat";
	char nomarchart[]="articulos.dat";
	system("cls"); srand(time(NULL)); system("color 9f");
	if((cli=fopen(nomarchcli,"wb+"))==NULL)
		exit(error(nomarchcli));
	p("\nEl archivo %s ha sido cargado!!",nomarchcli);

	if((art=fopen(nomarchart,"wb+"))==NULL)
		exit(error(nomarchart));
	p("\nEl archivo %s ha sido cargado!!",nomarchart);
	fflush(stdin);
	inicio(cli,art);
	system("cls");
	mostrarCli(cli);
    linea(80);
    mostrarArt(art);
	linea(80);
	tecla();
	system("cls");
	fclose(cli);fclose(art);
	return(0);

}
void linea(int x)
{
 int i;
	//p("");
	for(i=1;i<x;i++)
	 p("*");
// p("\n");
}

void inicio(FILE *x,FILE*y)
{
 regcli c;
 regarti a;
 char nomcli[][20]={"LOPEZ","RODRIGUEZ","GARCIA","MARTINEZ","LOLI"};
 char nomart[][20]={"COCA COLA","AGUA TONICA","N.FANTA","SPRITE","POMELO","MANDARINA"};
 float pre[]={200.70,300.75,300.66,200.80,200.89,300.01};
 int sto[]={73,120,76,34,77,98};
 int i;
 for(i=0;i<5;i++)
 {
	 c.cod_cli=i+1;
	 strcpy(c.nom_cli,nomcli[i]);
	 c.cuenta=0.;
	 fseek(x,0L,SEEK_END);
	 fwrite(&c,sizeof(c),1,x);
}
	for(int j=0; j<6; j++ )
 	{
	 	a.cod_art 		= j+1 ;
	 	strcpy(a.nom_art,nomart[j]);
	 	a.pre_art = 	pre[j];
		a.sto_art = 	sto[j];
		a.fact_art = 	pre[j] * sto[j];
	 	fseek(x,0L,SEEK_END);
	 	fwrite(&c,sizeof(c),1,x);
	}



}
void mostrarCli(FILE *x)
{
	regcli c;

	rewind(x);
	system("cls");
	p("\n\n\t\t\tN%cMINA DE CLIENTES\n\n",224);
	linea(80);
	p("\nC%cDIGO\tNOMBRE\t\t\t\t\t\tSALDO\n",224);
	fread(&c,sizeof(c),1,x);
	while(!feof(x))
	{
		p("\n%3d\t%-20s\t\t\t\t%6.2f\n",c.cod_cli,c.nom_cli,c.cuenta);
		fread(&c,sizeof(c),1,x);
	}
}

void mostrarArt(FILE *y)
{

}
int error(char *x)
{
	fprintf(stderr,"no se puede abrir el archivo %s",x);
	return(1);
}
void tecla(void)
{
	p("\nPRESIONE CUALQUIER TECLA PARA CONTINUAR!!!");
}

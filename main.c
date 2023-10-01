#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define p printf
#define s scanf

typedef struct
{ 
  long int cod;
  char desc[25];
  int cant;
  float pre;
} registro;

typedef struct elemento
{ 
  registro datos;
  struct elemento *sig;
} nodo;

int menu( void );
void cargapila( nodo**, registro[], int );
void mostrar( FILE* x );

int main()
{
  int option =      0;
  char* path_file = "./estructura_db/practice_c/tp_estructuras/data.dat";

  registro info[] =
  {
    { 100235, "Nebulizador",          50,   145.20  },
    { 100312, "Tensiometro",          120,  159.35  },
    { 200045, "Caloventor",           35,   46.00   },
    { 200511, "Estufa halogena",      15,   72.58   },
    { 400805, "Afeitadora",           100,  215.40  },
    { 400322, "Cortadora de Cabello", 210,  29.45   }
  };

  registro infocom[] =
  {
    { 500100, "Reproductor de DVD", 24, 200.53  },
    { 100312, "Tensiometro",        50, 159.35  },
    { 500235, "Televisor 21",       30, 565.60  },
    { 200511, "Estufa halogena",    30, 72.58   }
  };

  while( true )
  {
    option = menu();
  }

  return 0;
}

int menu( void )
{
  int op;

  do
  {
    printf("\n\t\t\t\t      MENU DE OPCIONES (PILAS)    \n\n");
    printf("\n\n\t\t\t\t -  CARGAR DATOS INICIALES     <1>\n");
    printf("\n\n\t\t\t\t -  LISTAR DATOS               <2>\n");
    printf("\n\n\t\t\t\t -  ACTUALIZAR Y LISTAR        <3>\n");
    printf("\n\n\t\t\t\t -  LISTAR ORDENADO            <4>\n");
    printf("\n\n\t\t\t\t -  CARGAR EN ARCHIVO BINARIO  <5>\n");
    printf("\n\n\t\t\t\t -  BORRAR Y SALIR             <6>\n");
    printf("\n\n\t\t\t\t -  INGRESE OPCION  [1-6]:        \n");

    scanf( " %d", &op );
  } while( op < 1 || op > 5 );

  return op;
}

void cargapila( nodo** x, registro y[], int z )
{
  int i;
  nodo *q;

  for(i=0;i<z;i++)
  {
    //q = ingresarDato( i,y );
    //apilar( &(*x), q );
  }

  return;
}

void mostrar( FILE* x )
{
  registro r;

  p( "\n\t\t CONTENIDO DE LOS REGISTROS EN EL ARCHIVO \n\n" );
  p( "\n\n Codigo \t\t Nombre \t\t\t Cantidad \t\t Precio \n\n ");

  rewind(x);

  fread( &r, sizeof(r), 1, x );

  while( !feof(x) )
  {
    p( "\n\n %3d \t\t %-20s \t %6d \t\t\t %6.2f", r.cod, r.desc, r.cant, r.pre );

    fread( &r, sizeof(r), 1, x);
  }

  return;
}
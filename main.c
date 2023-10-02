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
void load_data( registro[], registro[] );
void show_lists( registro[], registro[] );
void mostrar( FILE* x );

int main()
{
  int option =                0;
  char* path_file =           "./estructura_db/practice_c/tp_estructuras/data.dat";
  registro list_stock[6];
  registro list_purchases[4];

  while( true )
  {
    option = menu();

    switch( option )
    {
      case 1:
        load_data( list_stock, list_purchases );
      break;
      case 2:
        //show_lists( list_stock, list_purchases );
      break;
      case 3:
        //update_join();
      break;
      case 4:
        //show_order();
      break;
      case 5:
        //write_disk();
      break;
      case 6:
        //exit_erase();
      break;
    }
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

void load_data( registro info[], registro infocom[] )
{
  info[0] =     (registro){ 100235, "Nebulizador",           50,   145.20  };
  info[1] =     (registro){ 100312, "Tensiometro",           120,  159.35  };
  info[2] =     (registro){ 200045, "Caloventor",            35,   46.00   };
  info[3] =     (registro){ 200511, "Estufa halogena",       15,   72.58   };
  info[4] =     (registro){ 400805, "Afeitadora",            100,  215.40  };
  info[5] =     (registro){ 400322, "Cortadora de Cabello",  210,  29.45   };

  infocom[0] =  (registro){ 500100, "Reproductor de DVD",    24,   200.53  };
  infocom[1] =  (registro){ 100312, "Tensiometro",           50,   159.35  };
  infocom[2] =  (registro){ 500235, "Televisor 21",          30,   565.60  };
  infocom[3] =  (registro){ 200511, "Estufa halogena",       30,   72.58   };

  return;
}

void show_lists( registro stock[], registro purchases[] )
{
  printf( "LISTA STOCK:\n" );
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
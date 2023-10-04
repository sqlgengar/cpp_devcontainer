#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
nodo* load_data( registro info[], int n );
void show_lists( nodo*, nodo* );
void show_list( nodo* );
void update_join( nodo**, nodo* );
void show_order( nodo* );
void sort_list_by_price( nodo** );
void write_disk( nodo*, char* );
void exit_erase( nodo**, nodo** );
void free_list( nodo* );

int main()
{
  int option = 0;
  char* path_file = "./data.dat";
  registro info[] =
  {
    {100235, "Nebulizador", 50, 145.20},
    {100312, "Tensiometro", 120, 159.35},
    {200045, "Caloventor", 35, 46.00},
    {200511, "Estufa halogena", 15, 72.58},
    {400805, "Afeitadora", 100, 215.40},
    {400322, "Cortadora de Cabello", 210, 29.45}
  };
  registro infocom[] =
  {
    {500100, "Reproductor de DVD", 24, 200.53},
    {100312, "Tensiometro", 50, 159.35},
    {500235, "Televisor 21", 30, 565.60},
    {200511, "Estufa halogena", 30, 72.58}
  }; 
  nodo* stock = NULL;
  nodo* purchase = NULL;
  int size = 0;

  while( true )
  {
    option = menu();

    switch( option )
    {
      case 1:
        size = sizeof(info) / sizeof(info[0]);
        stock = load_data( info, size );

        size = sizeof(infocom) / sizeof(infocom[0]);
        purchase = load_data( infocom, size );
      break;
      case 2:
        show_lists( stock, purchase );
      break;
      case 3:
        update_join( &stock, purchase );
      break;
      case 4:
        show_order( stock );
      break;
      case 5:
        write_disk( stock, path_file );
      break;
      case 6:
        exit_erase( &stock, &purchase );
        exit( EXIT_SUCCESS );
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
  } while( op < 1 || op > 6 );

  return op;
}

nodo* load_data( registro info[], int n )
{
  nodo* lista = NULL;

  for( int i = 0; i < n; i++ )
  {
    nodo* nuevo_nodo = (nodo*)malloc(sizeof(nodo));

    nuevo_nodo->datos = info[i];
    nuevo_nodo->sig = lista;
    lista = nuevo_nodo;
  }

  return lista;
}

void show_lists( nodo* stock, nodo* purchase )
{
  printf( "\n*** Lista de stock ***\n" );
  show_list( stock );

  printf( "\n*** Lista de compras ***\n" );
  show_list( purchase );

  return;
}

void show_list( nodo* lista )
{
  printf( "Codigo\t Descripcion\t Cantidad\t Precio\n" );

  while( lista != NULL )
  {
    printf( "%ld\t %s\t %d\t %.2f\n", lista->datos.cod, lista->datos.desc, lista->datos.cant, lista->datos.pre );
    lista = lista->sig;
  }
  
  return;
}

void update_join( nodo** stock, nodo* purchase )
{
  nodo* current_purchase = purchase;
  
  while( current_purchase != NULL )
  {
    bool found = false;
    nodo* current_stock = *stock;
    
    while( current_stock != NULL )
    {
      if( strcmp( current_purchase->datos.desc, current_stock->datos.desc ) == 0 )
      {
        current_stock->datos.cant += current_purchase->datos.cant;
        found = true;
        break;
      }
      
      current_stock = current_stock->sig;
    }

    if( !found )
    {
      nodo* new_node = (nodo*)malloc(sizeof(nodo));
      new_node->datos = current_purchase->datos;
      new_node->sig = *stock;
      *stock = new_node;
    }
    
    current_purchase = current_purchase->sig;
  }
  show_list(*stock);
  return;
}

void show_order(nodo* stock)
{
  sort_list_by_price( &stock );

  printf( "\n*** Lista de Stock Ordenada por Precio ***\n" );
  show_list( stock );

  return;
}

void sort_list_by_price( nodo** lista )
{
  nodo* current = *lista;

  while( current != NULL )
  {
    nodo* min = current;
    nodo* temp = current->sig;

    while( temp != NULL )
    {
      if( temp->datos.pre < min->datos.pre ) min = temp;
      temp = temp->sig;
    }

    if( min != current )
    {
      registro temp_data = current->datos;
      current->datos = min->datos;
      min->datos = temp_data;
    }

    current = current->sig;
  }
  return;
}

void write_disk( nodo* stock, char* path )
{
  char* mode = "wb";
  FILE* file = fopen( path, mode );

  while( stock != NULL )
  {
    fwrite( &(stock->datos), sizeof(registro), 1, file );
    stock = stock->sig;
  }

  fclose(file);
  return;
}

void exit_erase( nodo** stock, nodo** purchase )
{
  free_list( *stock );
  free_list( *purchase );
  *stock = NULL;
  *purchase = NULL;
  printf( "Listas borradas y memoria liberada. Saliendo del programa...\n" );

  return;
}

void free_list( nodo* lista )
{
  while( lista != NULL )
  {
    nodo* temp = lista;
    lista = lista->sig;
    free( temp );
  }

  return;
}
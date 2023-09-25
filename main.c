/**
 *
 *  Desarrollar interseccion de 2 listas.
 *
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data
{
  int number;
  int count;
  struct data* next;
} Node;

typedef struct
{
  Node* top;
} List;

void execute();
List* show_menu( List* );
List* resolve_option( int, List* );
List* create_list( bool );
List* push( List*, int, bool );
List* pop( List*, bool );
bool is_empty( List*, bool );
List* show_list( List* );
//List* join_list( List* );
int get_top_value( List*, bool );
int resolve_value_pop( int );
List* delete_list( List* );

int main()
{
  execute();
  return 0;
}

void execute()
{
  List* list = NULL;

  while( true )
  {
    list = show_menu( list );
  }

  return;
}

List* show_menu( List* list )
{
  int temp_option = -1;

  printf("\n\n");
  printf( "Ingrese el numero de opcion: \n" );
  printf( "Crear lista:                 (1)\n" );
  printf( "Agregar elemento a la lista: (2)\n" );
  printf( "Sacar elemento de la lista:  (3)\n" );
  printf( "Listar lista:                (4)\n" );
  printf( "Ordenar lista:               (5)\n" );
  printf( "Eliminar la lista:           (6)\n" );
  printf( "Salir:                       (7)\n" );
  printf("\n\n");

  scanf( " %d", &temp_option );
  fflush( stdin );

  return resolve_option( temp_option, list );
}

List* resolve_option( int option, List* list )
{
  int input_user_value =  NULL;
  bool verbose =          true;

  switch( option )
  {
    case 1:
      list = create_stack( verbose );
    break;
    case 2:
      list = push( list, input_user_value, verbose );
    break;
    case 3:
      list = pop( list, verbose );
    break;
    case 4:
      list = show_stack( list );
    break;
    case 5:
      list = sort_stack( list );
    break;
    case 6:
      list = delete_stack( list );
    break;
    case 7:
      exit( EXIT_SUCCESS );
    break;
  }

  return list;
}

List* create_stack( bool is_verbose )
{
  List* temp_list = ( List* )malloc( sizeof( List ) );
  temp_list->top =   NULL;
  
  if( is_verbose ) printf( "Se creo la lista %p\n", (void*)temp_list );

  return temp_list;
}

List* push( List* list, int aux_value, bool is_verbose )
{
  int temp_number = aux_value;
  Node* node =      NULL;

  node = (Node*)malloc( sizeof( Node ) );
  
  if( temp_number == NULL )
  {
    printf( "Ingrese valor:\n" );
    scanf( " %d", &temp_number );
    fflush( stdin );
  }

  node->number =    temp_number;
  node->next =      NULL;
    
  node->next =  list->top;
  list->top =   node;

  if( is_verbose ) printf( "Se creo el nodo %p y valor de memoria %d \n", (void*)node, get_top_value( list, is_verbose ) );

  return list;
}

List* pop( List* list, bool is_verbose )
{
  int value_erase;
  Node* memory_erase;

  if( is_empty( list, is_verbose ) ) return list;

  Node* temp =    list->top;
  value_erase =   get_top_value( list, is_verbose );
  memory_erase =  temp;

  list->top =    temp->next;
  free( temp );

  if( is_verbose ) printf( "Se borro el nodo %p y valor de memoria %d \n", (void*)memory_erase, value_erase );

  return list;
}

bool is_empty( List* list, bool is_verbose )
{
  if( list->top != NULL ) return false;

  if( is_verbose ) printf( "Pila vacia \n" );
  return true;
}

List* show_stack( List* list )
{
  bool verbose = true;

  if( is_empty( list, verbose ) ) return list;

  Node* current = list->top;
  
  printf( "Contenido de la lista: \n" );

  while( current != NULL )
  {
      printf( "%d \n", current->number );
      current = current->next;
  }

  return list;
}

int get_top_value( List* list, bool is_verbose )
{
  if( is_empty( list, is_verbose ) ) return 0;
  
  return list->top->number;
}

List* delete_stack( List* list )
{
  bool verbose = true;
  bool no_verbose = false;

  if( is_empty( list, verbose ) ) return list;

  while( !is_empty( list, no_verbose ) )
  {
    pop( list, no_verbose );
  }

  free( list );

  printf( "La lista ha sido eliminada\n" );
  return NULL;
}
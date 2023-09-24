/*

Pila - Desarrollar un menu de operaciones basicas junto con pila ordenada.

*/

/**
 *  Muchas funciones tiene implementado el parametro is_verbose.
 *  Esto es para que se pueda reutilizar la misma funcion para el usuario o para uso interno del programa.
 *  En caso de que no se necesite mostrar los mensajes de ouptup
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data
{
  int number;
  struct data* preview;
} Node;

typedef struct
{
  Node* top;
} Stack;

void execute();
Stack* show_menu( Stack* );
Stack* resolve_option( int, Stack* );
Stack* create_stack( bool );
Stack* push( Stack*, int, bool );
Stack* pop( Stack*, bool );
bool is_empty( Stack*, bool );
Stack* show_stack( Stack* );
Stack* sort_stack( Stack* );
int get_top_value( Stack*, bool );
int resolve_value_pop( int );
Stack* delete_stack( Stack* stack );

int main()
{
  execute();
  return 0;
}

void execute()
{
  Stack* stack = NULL;

  while( true )
  {
    stack = show_menu( stack );
  }

  return;
}

Stack* show_menu( Stack* stack )
{
  int temp_option = -1;

  printf("\n\n");
  printf( "Ingrese el numero de opcion:      \n" );
  printf( "Crear pila:                    (1)\n" );
  printf( "Agregar elemento a la pila:    (2)\n" );
  printf( "Sacar elemento de la pila:     (3)\n" );
  printf( "Listar pila:                   (4)\n" );
  printf( "Ordenar pila:                  (5)\n" );
  printf( "Eliminar la pila:              (6)\n" );
  printf( "Salir:                         (7)\n" );
  printf("\n\n");

  scanf( " %d", &temp_option );
  fflush( stdin );

  return resolve_option( temp_option, stack );
}

Stack* resolve_option( int option, Stack* stack )
{
  int input_user_value =  NULL;
  bool verbose =          true;

  switch( option )
  {
    case 1:
      stack = create_stack( verbose );
    break;
    case 2:
      stack = push( stack, input_user_value, verbose );
    break;
    case 3:
      stack = pop( stack, verbose );
    break;
    case 4:
      stack = show_stack( stack );
    break;
    case 5:
      stack = sort_stack( stack );
    break;
    case 6:
      stack = delete_stack( stack );
    break;
    case 7:
      exit( EXIT_SUCCESS );
    break;
  }

  return stack;
}

Stack* create_stack( bool is_verbose )
{
  Stack* temp_stack = ( Stack* )malloc( sizeof( Stack ) );
  temp_stack->top =   NULL;
  
  if( is_verbose ) printf("Se creo la pila %p\n", (void*)temp_stack);

  return temp_stack;
}

/**
 *  push va a contar con un valor auxiliar que se le puede pasar a la funcion.
 *  esto es para distinguir el caso de uso frente a una usuario que ingresa valores 
 *  y cuando el programa lo utiliza para funciones internas.
**/
Stack* push( Stack* stack, int aux_value, bool is_verbose )
{
  int temp_number =     aux_value;
  Node* little_stack =  NULL;

  // Crear nodo que genera espacio de memoria
  little_stack = ( Node* )malloc( sizeof( Node ) );
  
  if( temp_number == NULL )
  {
    // Cargar datos de nodo si no se paso un valor auxiliar
    printf( "Ingrese valor:\n" );
    scanf( " %d", &temp_number );
    fflush( stdin );
  }

  // Cargar dato en el nuevo nodo
  little_stack->number =  temp_number;
    
  // Reasigna direccion - apilar
  little_stack->preview = stack->top;
  stack->top =            little_stack;

  if( is_verbose ) printf( "Se creo el nodo %p y valor de memoria %d \n", (void*)little_stack, get_top_value( stack, is_verbose ) );

  return stack;
}

Stack* pop( Stack* stack, bool is_verbose )
{
  int value_erase;
  Node* memory_erase;

  if( is_empty( stack, is_verbose ) ) return stack;

  // Crear nodo temporarl para operaciones
  Node* temp =    stack->top;

  // Gaurdar datos con los que se van a trabajar para debuggin
  value_erase =   get_top_value( stack, is_verbose );
  memory_erase =  temp;

  // Reasignar memoria
  stack->top =    temp->preview;
  free( temp );

  if( is_verbose ) printf( "Se borro el nodo %p y valor de memoria %d \n", (void*)memory_erase, value_erase );

  return stack;
}

bool is_empty( Stack* stack, bool is_verbose )
{
  if( stack->top != NULL ) return false;

  if( is_verbose ) printf( "Pila vacia \n" );
  return true;
}

Stack* show_stack( Stack* stack )
{
  bool verbose = true;

  if( is_empty( stack, verbose ) ) return stack;

  Node* current = stack->top;
  
  printf( "Contenido de la pila: \n" );

  while( current != NULL )
  {
      printf( "%d \n", current->number );
      current = current->preview;
  }

  return stack;
}

// Ordenamiento por insetion sort
Stack* sort_stack( Stack* stack )
{
  bool no_verbose = false;
  Stack* sorted_stack = create_stack( no_verbose );

  while( !is_empty( stack, no_verbose ) )
  {
    int current = get_top_value( stack, no_verbose );
    pop( stack, no_verbose );

    while( !is_empty( sorted_stack, no_verbose ) && get_top_value( sorted_stack, no_verbose ) > current )
    {
      int top_value = get_top_value( sorted_stack, no_verbose );
      pop( sorted_stack, no_verbose );
      push( stack, top_value, no_verbose );
    }

    push( sorted_stack, current, no_verbose );
  }

  while( !is_empty( sorted_stack, no_verbose ) )
  {
      int top_value = get_top_value( sorted_stack, no_verbose );
      pop( sorted_stack, no_verbose );
      push( stack, top_value, no_verbose );
  }

  printf( "Pila ordenada\n" );

  return stack;
}

int get_top_value( Stack* stack, bool is_verbose )
{
  if( is_empty( stack, is_verbose ) ) return 0;
  
  return stack->top->number;
}

Stack* delete_stack( Stack* stack )
{
  bool verbose = true;
  bool no_verbose = false;

  if( is_empty( stack, verbose ) ) return stack;

  while( !is_empty( stack, no_verbose ) )
  {
    pop( stack, no_verbose );
  }

  free(stack);

  printf("La pila ha sido eliminada\n");
  return NULL;
}
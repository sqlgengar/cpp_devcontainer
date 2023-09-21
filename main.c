/*

Pila - Desarrollar un menu de operaciones basicas junto con pila ordenada.

*/

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
Stack* create_stack();
Stack* push( Stack* );
Stack* pop( Stack* );
bool is_empty( Stack* );
Stack* show_stack( Stack* );
Stack* sort_stack( Stack* );

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
  switch( option )
  {
    case 1:
      stack = create_stack();
    break;
    case 2:
      stack = push(stack);
    break;
    case 3:
      stack = pop(stack);
    break;
    case 4:
      stack = show_stack( stack );
    break;
    case 5:
      stack = sort_stack( stack );
    break;
    case 6:
      //delete_stack();
    break;
    case 7:
      //nos_re_vimos();
    break;
  }

  return stack;
}

Stack* create_stack()
{
  Stack* temp_stack = ( Stack* )malloc( sizeof( Stack ) );
  temp_stack->top =   NULL;
  
  printf("Se creo la pila %p\n", (void*)temp_stack);

  return temp_stack;
}

Stack* push( Stack* stack )
{
  int temp_number =     0;
  Node* little_stack =  NULL;

  // Crear nodo que genera espacio de memoria
  little_stack = ( Node* )malloc( sizeof( Node ) );
  
  // Cargar datos de nodo
  printf( "Ingrese valor:\n" );
  scanf( " %d", &temp_number );
  fflush( stdin );
  little_stack->number =  temp_number;
    
  // Reasigna direccion - apilar
  little_stack->preview = stack->top;
  stack->top =            little_stack;
  printf( "Se creo el nodo %p y valor de memoria %d \n", (void*)little_stack, little_stack->number );

  return stack;
}

Stack* pop( Stack* stack )
{
  int value_erase;
  Node* memory_erase;

  if( is_empty( stack ) ) return stack;

  Node* temp =    stack->top;
  value_erase =   temp->number;
  memory_erase =  temp;
  stack->top =    temp->preview;
  free( temp );

  printf( "Se borro el nodo %p y valor de memoria %d \n", (void*)memory_erase, value_erase );

  return stack;
}

bool is_empty( Stack* stack )
{
  if( stack->top != NULL ) return false;

  printf( "Pila vacia \n" );
  return true;
}

Stack* show_stack( Stack* stack )
{
  if( is_empty( stack ) ) return stack;

  Node* current = stack->top;
  
  printf( "Contenido de la pila: \n" );

  while( current != NULL )
  {
      printf( "%d \n", current->number );
      current = current->preview;
  }

  return stack;
}

Stack* sort_stack( Stack* stack )
{
  Stack* sorted_stack = create_stack();

  while( !is_empty( stack ) )
  {
    int current = pop(stack)->number;

    while( !is_empty(sorted_stack) && sorted_stack->top->number > current )
    {
      push(stack)->number = pop(sorted_stack)->number;
    }

    push(sorted_stack)->number = current;
  }

  while( !is_empty( sorted_stack ) )
  {
    push(stack)->number = pop(sorted_stack)->number;
  }

  printf( "Pila ordenada\n" );

  return stack;
}
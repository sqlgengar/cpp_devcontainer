/*

Pila - Desarrollar un menu de operaciones basicas junto con pila ordenada.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
  int number;
  struct nodo * preview;
}nodo;

void execute();
void show_menu();
void resolve_option( int );
nodo* create_stack();
void add_element( nodo** );
void show_stack( nodo* );



int main()
{
  execute();
  return 0;
}

void execute()
{
  while( true )
  {
    show_menu();
  }

  return;
}

void show_menu()
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

  resolve_option( temp_option );

  return;
}

void resolve_option( int option )
{
  nodo* stack;

  switch( option )
  {
    case 1:
      stack = create_stack();
    break;
    case 2:
      add_element( &stack );
    break;
    case 3:
      //delete_element();
    break;
    case 4:
      show_stack( stack );
    break;
    case 5:
      //sort_stack();
    break;
    case 6:
      //delete_stack();
    break;
    case 7:
      //nos_re_vimos();
    break;
  }

  return;
}

nodo* create_stack()
{
  nodo* temp_stack = NULL;
  printf("Se creo la pila %x\n",temp_stack);

  return temp_stack;
}

void add_element( nodo** stack )
{
  int temp_number = 0;
  nodo* little_stack = NULL;

  // Crear nodo que genera espacio de memoria
  little_stack = ( nodo* )malloc( sizeof( nodo ) );
  
  // Cargar datos de nodo
  printf( "Ingrese valor:\n" );
  scanf( " %d", &temp_number );
  fflush( stdin );
  little_stack->number = temp_number;
  little_stack->preview = NULL;
    
  // Reasigna direccion - apilar
  little_stack->preview = *stack;
  *stack = little_stack;
  printf(" Se creo el nodo %x y valor de memoria %d \n", little_stack, little_stack->number );

  return;
}

//mostrar lista de pila
void show_stack(nodo* top) {
   //verifica si esta vacia
    /*
    if (isEmpty(top)) {
        printf("La pila está vacía.\n");
        return;
    }*/
    //muestra pila
    nodo* current = top;
    printf("Contenido de la pila:\n");
    while (current != NULL) {
        printf(" test \n");
        printf("%d\n", current->number);
        current = current->preview;
    }
}
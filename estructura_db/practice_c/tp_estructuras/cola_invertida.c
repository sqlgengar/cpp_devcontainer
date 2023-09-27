/**
 *  Desarrollar menu de operaciones basicas junto con cola invertida.
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data
{
    int number;
    struct data* next;
} Node;

typedef struct
{
    Node* front;
    Node* rear;
} Queue; 

void execute();
Queue* show_menu( Queue* );
Queue* resolve_option( int, Queue* );
Queue* create_queue( bool );
Queue* enqueue( Queue*, int, bool );
Queue* dequeue( Queue*, bool );
bool is_empty( Queue*, bool );
Queue* show_queue( Queue* );
Queue* invert_queue( Queue* );
int get_front_value( Queue*, bool );
Queue* delete_queue( Queue* );

int main()
{
  execute();
  return 0;
}

void execute()
{
  Queue* queue = NULL;

  while( true )
  {
    queue = show_menu(queue);
  }
}

Queue* show_menu( Queue* queue )
{
  int temp_option = -1;

  printf( "\n\n" );
  printf( "Ingrese el numero de opcion:\n" );
  printf( "Crear cola:                   (1)\n" );
  printf( "Agregar elemento a la cola:   (2)\n" );
  printf( "Sacar elemento de la cola:    (3)\n" );
  printf( "Listar cola:                  (4)\n" );
  printf( "Invertir cola:                (5)\n" );
  printf( "Eliminar la cola:             (6)\n" );
  printf( "Salir:                        (7)\n" );
  printf( "\n\n" );

  scanf( " %d", &temp_option );
  fflush( stdin );

  return resolve_option( temp_option, queue );
}

Queue* resolve_option( int option, Queue* queue )
{
  int input_user_value =  NULL;
  bool verbose =          true;

  switch( option )
  {
    case 1:
      queue = create_queue( verbose );
    break;
    case 2:
      queue = enqueue( queue, input_user_value, verbose );
    break;
    case 3:
      queue = dequeue( queue, verbose );
    break;
    case 4:
      queue = show_queue( queue );
    break;
    case 5:
      queue = sort_queue( queue );
    break;
    case 6:
      queue = delete_queue( queue );
    break;
    case 7:
      exit( EXIT_SUCCESS );
    break;
  }

  return queue;
}

Queue* create_queue( bool is_verbose )
{
  Queue* temp_queue = (Queue*)malloc( sizeof( Queue ) );
  temp_queue->front = NULL;
  temp_queue->rear =  NULL;

  if( is_verbose ) printf( "Se creo la cola %p\n", (void*)temp_queue );

  return temp_queue;
}

Queue* enqueue( Queue* queue, int aux_value, bool is_verbose )
{
  int temp_number = aux_value;
  Node* new_node =  (Node*)malloc( sizeof( Node ) );

  if( temp_number == NULL )
  {
    printf( "Ingrese valor:\n" );
    scanf( " %d", &temp_number );
    fflush( stdin );
  }

  new_node->number =  temp_number;
  new_node->next =    NULL;

  // Si la cola esta vacia el principio y el final hacen referencia al mismo elemento.
  if( is_empty( queue, is_verbose ) )
  {
    queue->front =  new_node;
    queue->rear =   new_node;
  }

  // Actualiza las referencias del final de la cola para agregarlo.
  queue->rear->next = new_node;
  queue->rear =       new_node;

  if( is_verbose ) printf( "Se encolo el nodo %p y valor de memoria %d \n", (void*)new_node, get_front_value( queue, is_verbose ) );

  return queue;
}

Queue* dequeue( Queue* queue, bool is_verbose )
{
  if( is_empty( queue, is_verbose ) ) return queue;

  int value_removed =   get_front_value( queue, is_verbose );
  Node* node_removed =  queue->front;

  // Chequeamos si es el unico elemento en la cola
  if( queue->front == queue->rear )
  {
    queue->front =  NULL;
    queue->rear =   NULL;
  }
  if( queue->front != queue->rear ) queue->front = queue->front->next;

  free( node_removed );

  if( is_verbose ) printf( "Se desencolo el nodo %p y valor de memoria %d \n", (void*)node_removed, value_removed );

  return queue;
}

bool is_empty( Queue* queue, bool is_verbose )
{
  if( queue->front != NULL ) return false;

  if( is_verbose ) printf( "Cola vacia \n" );
  return true;
}

Queue* show_queue( Queue* queue )
{
  bool verbose = true;

  if( is_empty( queue, verbose ) ) return queue;

  Node* current = queue->front;

  printf( "Contenido de la cola: \n" );
  while( current != NULL )
  {
    printf("%d \n", current->number);
    current = current->next;
  }

  return queue;
}

Queue* invert_queue( Queue* queue )
{
  bool no_verbose =       false;
  Queue* inverted_queue = create_queue( no_verbose );

  // Crear una cola auxiliar en el orden inverso con las mismas operaciones de cola.
  while( !is_empty( queue, no_verbose ) )
  {
    int current = get_front_value( queue, no_verbose );

    dequeue( queue, no_verbose );
    enqueue(inverted_queue, current, no_verbose);
  }

  // Sobreescribir la cola invertida.
  while( !is_empty( inverted_queue, no_verbose ) )
  {
    int current = get_front_value( inverted_queue, no_verbose );

    dequeue( inverted_queue, no_verbose );
    enqueue( queue, current, no_verbose );
  }

  printf( "Cola invertida\n" );
  return queue;
}

int get_front_value( Queue* queue, bool is_verbose )
{
  if( is_empty( queue, is_verbose ) ) return 0;

  return queue->front->number;
}

Queue* delete_queue( Queue* queue )
{
  bool verbose =    true;
  bool no_verbose = false;

  if( is_empty( queue, verbose ) ) return queue;

  while( !is_empty( queue, no_verbose ) )
  {
    dequeue(queue, no_verbose);
  }

  free(queue);

  printf( "La cola ha sido eliminada\n" );
  return NULL;
}
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
  char* list_name;
} List;

typedef struct
{
  List* list_1;
  List* list_2;
  List* join_list;
  List* current_list;
} Lists;

void execute();
Lists* init_lists();
List* create_list( bool );
Lists* show_menu( Lists* );
Lists* resolve_option( int, Lists* );
List* switch_list( Lists* );
int input_temp_temp_value_user();
List* push( List*, int, bool );
Node* create_node( int );
int get_top_temp_temp_value( List*, bool );
bool is_empty( List*, bool );
List* pop( List*, bool );
void show_list( List* );
Lists* delete_list( Lists* );
List* intersect_lists( Lists* );
void show_interseciont_list( List* );

int main()
{
  execute();
  return 0;
}

void execute()
{
  Lists* lists = init_lists();

  while( true )
  {
    lists = show_menu( lists );
  }
  return;
}

/**
 *  La idea es que el programa siempre cree la inicilizacion de las dos listas en backgraound,
 *  ademas de que seleccione la lista uno por defult para empezar a trabajar.
**/
Lists* init_lists()
{
  bool no_verbose = false;

  Lists* new_lists =          (Lists*)malloc( sizeof ( Lists ) );

  new_lists->list_1 =             NULL;
  new_lists->list_2 =             NULL;
  new_lists->current_list =       NULL;
  new_lists->current_list =       NULL;

  new_lists->list_1 =             create_list( no_verbose );
  new_lists->list_2 =             create_list( no_verbose );

  new_lists->list_1->list_name =  "|---LISTA 1---|";
  new_lists->list_2->list_name =  "|---LISTA 2---|";

  new_lists->current_list =       new_lists->list_1;

  return new_lists;
}

List* create_list( bool is_verbose )
{
  List* temp_list = (List*)malloc( sizeof( List ) );
  temp_list->top =  NULL;

  if( is_verbose ) printf( "Se creó la lista %p\n", (void*)temp_list );

  return temp_list;
}

Lists* show_menu( Lists* lists )
{
  int temp_option;

  printf( "/**************************************/\n" );
  printf( "TRABAJANDO CON LA LISTA: %s             \n", lists->current_list->list_name );
  printf( "/**************************************/\n" );
  printf( "\n                                      \n" );

  printf( "Ingrese el número de opción:            \n" );
  printf( "Cambiar de lista actual:             (1)\n" );
  printf( "Agregar elemento a la lista actual:  (2)\n" );
  printf( "Sacar elemento de la lista actual:   (3)\n" );
  printf( "Listar lista actual:                 (4)\n" );
  printf( "Eliminar lista actual:               (5)\n" );
  printf( "Inteseccion de listas:               (6)\n" );
  printf( "Mostrar interseccion de listas:      (7)\n" );
  printf( "Salir:                               (8)\n" );
  printf( "\n                                      \n" );

  scanf(" %d", &temp_option );
  fflush( stdin );

  return resolve_option( temp_option, lists );
}

Lists* resolve_option( int option, Lists* lists )
{
  int temp_temp_value_user;
  bool verbose =    true;

  switch( option )
  {
    case 1:
      lists->current_list = switch_list( lists );
    break;
    case 2:
      temp_temp_value_user =  input_temp_temp_value_user();
      lists->current_list =   push( lists->current_list, temp_temp_value_user, verbose );
    break;
    case 3:
      lists->current_list = pop( lists->current_list, verbose );
    break;
    case 4:
      show_list( lists->current_list );
    break;
    case 5:
      lists = delete_list( lists );
    break;
    case 6:
      lists->join_list = intersect_lists( lists );
    break;
    case 7:
      show_list( lists->join_list );
    break;
    case 8:
      exit( EXIT_SUCCESS );
    break;
  }

  return lists;
}

List* switch_list( Lists* lists )
{
  if( lists->current_list == lists->list_1 ) return lists->list_2;
  
  return lists->list_1;
}

int input_temp_temp_value_user()
{
  int temp_temp_temp_value;

  printf( "Ingrese un valor: \n" );
  scanf( " %d", &temp_temp_temp_value );
  fflush( stdin );

  return temp_temp_temp_value;
}

/**
 *  Este push siempre busca donde insertar el nuevo elemento de forma correcta, por lo cual lo pila siempre va a estar ordenada,
 *  si el valor esta repetido, suma al contador, evitando la duplicacion de valores.
 * 
 *  Una opcion para entender mas facil el push seria devidirlo en varias partes.
 *  por ejemplo, asumir que la lista no esta ordenada, en primera isntancia buscar si el valor es repetido
 *  despues se podria simplemente insertar en valor en la parte mas alta de la pila, y ordenar la pila a lo ultimo.
**/
List* push( List* list, int temp_temp_value, bool is_verbose )
{
  bool no_verbose = false;
  Node* new_node =  create_node( temp_temp_value );

  if( is_empty( list, no_verbose ) || temp_temp_value < list->top->number )
  {
    new_node->next =  list->top;
    list->top =       new_node;
  }

  else
  {
    Node* current = list->top;

    while( current->next != NULL && current->next->number < temp_temp_value )
    {
      current = current->next;
    }

    if( current->number == temp_temp_value )
    {
      current->count++;
      free(new_node);
    }

    else
    {
      new_node->next =  current->next;
      current->next =   new_node;
    }
  }

  if( is_verbose ) printf( "Se creó el nodo %p y valor de memoria %d\n", (void*)new_node, get_top_temp_temp_value( list, is_verbose ) );

  return list;
}

Node* create_node( int temp_temp_value )
{
  Node* new_node =  NULL;
  new_node =        (Node*)malloc( sizeof( Node ) );

  new_node->number =  temp_temp_value;
  new_node->count =   1;
  new_node->next =    NULL;

  return new_node;
}

int get_top_temp_temp_value( List* list, bool is_verbose )
{
  if( is_empty( list, is_verbose ) ) return 0;
  
  return list->top->number;
}

bool is_empty( List* list, bool is_verbose )
{
  if( list->top != NULL ) return false;

  if( is_verbose ) printf( "Lista vacía\n" );

  return true;
}

List* pop(List* list, bool is_verbose)
{
  int temp_temp_value_erase;
  Node* memory_erase;

  if( is_empty( list, is_verbose ) ) return list;

  Node* temp =    list->top;
  temp_temp_value_erase =   get_top_temp_temp_value( list, is_verbose );
  memory_erase =  temp;

  list->top = temp->next;
  free(temp);

  if( is_verbose ) printf( "Se borró el nodo %p y valor de memoria %d\n", (void*)memory_erase, temp_temp_value_erase );

  return list;
}

void show_list( List* list )
{
  bool verbose =  true;
  Node* current = NULL;
  int count =     1;
  
  if( is_empty( list, verbose ) ) return;

  current = list->top;

  printf( "Contenido de la lista:\n" );

  while( current != NULL )
  {
    printf( "------------\n" );
    printf( "Nodo      %d\n", count );
    printf( "valor:    %d\n", current->number );
    printf( "contador: %d\n", current->count );
    printf( "            \n" );

    current = current->next;
    count++;
  }
  return;
}

Lists* delete_list( Lists* lists )
{
    bool verbose =    true;
    bool no_verbose = false;
    char* list_name = lists->current_list->list_name;

    if( is_empty( lists->current_list, verbose ) ) return lists;

    if( lists->current_list == lists->list_1 )
    {
      while( !is_empty( lists->list_1, no_verbose ) )
      {
        pop( lists->list_1, no_verbose );
      }
      free( lists->list_1 );

      printf( "La lista %s ha sido eliminada\n", list_name );

      lists->current_list = lists->list_2;
      return lists;
    }

    while( !is_empty( lists->list_2, no_verbose ) )
    {
        pop( lists->list_2, no_verbose );
    }
    free( lists->list_2 );

    printf("La lista %s ha sido eliminada\n", list_name );

    lists->current_list = lists->list_1;
    return lists;
}

List* intersect_lists( Lists* lists )
{
  bool no_verbose = false;
  List* join =      create_list( no_verbose );
  Node* node_1 =    lists->list_1->top;

  while( node_1 != NULL )
  {
    int temp_value =    node_1->number;
    Node* node_2 =      lists->list_2->top;
    int count_node_1 =  node_1->count;
    int count_node_2 =  0;

    // Contar la cantidad de veces que se repite el elemento en la segunda lista
    while( node_2 != NULL )
    {
      if( node_2->number == temp_value )
      {
        count_node_2 = node_2->count;
        break;
      }
      node_2 = node_2->next;
    }

    // Agregar el elemento a la lista de resultados según la cantidad mínima de repeticiones
    for( int i = 0; i < count_node_1 && i < count_node_2; i++ )
    {
      join = push( join, temp_value, false );
    }
    node_1 = node_1->next;
  }

  return join;
}
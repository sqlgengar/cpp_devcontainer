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
  List* current_list;
} Lists;

void execute();
Lists* init_lists();
List* create_list( bool );
Lists* show_menu( Lists* );
Lists* resolve_option( int, Lists* );
List* switch_list( Lists* );
List* push( List*, int, bool );
Node* create_node( int );
Node* resolve_unique_value( Node*, Node* );
int get_top_value( List*, bool );
bool is_empty( List*, bool );
//List* pop(List*, bool);
//List* show_list(List*);
//List* delete_list(List*);

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
  int temp_option = NULL;

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
  printf( "Salir:                               (6)\n" );
  printf( "\n                                      \n" );

  scanf(" %d", &temp_option );
  fflush( stdin );

  return resolve_option( temp_option, lists );
}

Lists* resolve_option( int option, Lists* lists )
{
  int input_user_value =  NULL;
  bool verbose =          true;

  switch( option )
  {
    case 1:
      lists->current_list = switch_list( lists );
    break;
    case 2:
      lists->current_list = push( lists->current_list, input_user_value, verbose );
    break;
    case 3:
      //pop;
    break;
    case 4:
      //show_list;
    break;
    case 5:
      //delete_list;
    break;
    case 6:
      exit( EXIT_SUCCESS );
    break;
  }

  return lists;

/*
  //else if (option == 6)
  {
    if (lists->current_list != NULL)
      lists->current_list = pop(lists->current_list, verbose);
    else
      printf("No se ha seleccionado ninguna lista para quitar elementos.\n");
  }
*/
}

List* switch_list( Lists* lists )
{
  if( lists->current_list == lists->list_1 ) return lists->list_2;
  
  return lists->list_1;
}

List* push( List* list, int aux_value, bool is_verbose )
{
  Node* node =  NULL;

  node = create_node( aux_value );
  node = resolve_unique_value( list->top, node );

  node->next =    list->top;
  list->top =     node;

  if( is_verbose ) printf( "Se creó el nodo %p y valor de memoria %d\n", (void*)node, get_top_value( list, is_verbose ) );

  return list;
}

Node* create_node( int value )
{
  int temp_number = value;
  Node* new_node =  NULL;
  new_node =        (Node*)malloc( sizeof( Node );

  if( value == NULL )
  {
    printf( "Ingrese valor:\n" );
    scanf( " %d", &temp_number );
    fflush( stdin );
  }

  new_node->number =  temp_number;
  new_node->count =   1;
  new_node->next =    NULL;

  return new_node;
}

Node* resolve_unique_value( Node* list_node, Node* new_node )
{
  if( list_node == NULL ) return new_node;

  if( list_node->number > new_node->number ) return create_node( new_node->number );

  if( list_node->number == new_node->number )
  {
    list_node->count++;
    return list_node;
  }

  

}

int get_top_value( List* list, bool is_verbose )
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

/*
List* pop(List* list, bool is_verbose)
{
    int value_erase;
    Node* memory_erase;

    if (is_empty(list, is_verbose)) return list;

    Node* temp = list->top;
    value_erase = get_top_value(list, is_verbose);
    memory_erase = temp;

    list->top = temp->next;
    free(temp);

    if (is_verbose) printf("Se borró el nodo %p y valor de memoria %d\n", (void*)memory_erase, value_erase);

    return list;
}
*/

/*
List* show_list(List* list)
{
    bool verbose = true;

    if (is_empty(list, verbose)) return list;

    Node* current = list->top;

    printf("Contenido de la lista:\n");

    while (current != NULL)
    {
        printf("%d\n", current->number);
        current = current->next;
    }

    return list;
}
*/

/*
List* delete_list(List* list)
{
    bool verbose = true;
    bool no_verbose = false;

    if (is_empty(list, verbose)) return list;

    while (!is_empty(list, no_verbose))
    {
        pop(list, no_verbose);
    }

    free(list);

    printf("La lista ha sido eliminada\n");
    return NULL;
}
*/
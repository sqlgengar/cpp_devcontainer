/*

 Escriba una función en C++ llamada eliminar() que elimina una estructura existente de la lista de estructuras vinculadas creada por el programa 13.11. El algoritmo
para eliminar una estructura vinculada deberá seguir la secuencia desarrollada para
eliminar una estructura desarrollada en el ejercicio 4 en la sección 13.4. El argumento transmitido a eliminar() deberá ser la dirección de la estructura que precede
al registro que se eliminará. En la función de eliminación, asegúrese que el valor
del apuntador en la estructura eliminada reemplaza al valor del miembro apuntador
de la estructura precedente antes que se elimine la estructura.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXRECS 3
#define MAX_CHARS 500

typedef struct TeleType
{
  char name[MAX_CHARS];
  char phoneNo[MAX_CHARS];
  struct TeleType *nextaddr;
} TeleType;

void check_memory( TeleType* );
void populate( TeleType* );
void display( TeleType* );
void reassign_address( TeleType* );
void eliminar( TeleType* );

int main()
{
  TeleType *list = NULL;
  TeleType *current = NULL;

  list = ( TeleType* )malloc( sizeof( TeleType ) );
  check_memory( list );
  current = list;

  for( int i = 0; i < MAXRECS - 1; i++ )
  {
    populate( current );
    current->nextaddr = ( TeleType* )malloc( sizeof( TeleType ) );
    check_memory( current->nextaddr );
    current = current->nextaddr;
  }

  populate( current );
  current->nextaddr = NULL;

  printf( "\nThe  list  consists  of  the  following  records:\n" );
  display( list );

  reassign_address( list );
  display( list );

  free(list);
  free(current);

  return 0;
}

void check_memory( TeleType* pointer_list )
{
  if( pointer_list == NULL )
  {
    printf( "memory not available\n" );
    free( pointer_list );
    exit( EXIT_FAILURE );
  }
}

void populate( TeleType* record )
{
  printf( "Enter a name:\n" );
  scanf( " %s", &record->name );
  fflush( stdin );

  printf( "Enter  the  phone  number:\n" );
  scanf( " %s", &record->phoneNo );
  fflush( stdin );

  return;
}

void display( TeleType* contents )
{
  while( contents != NULL )
  {
    printf( "%s %s \n", contents->name, contents->phoneNo );

    contents = contents->nextaddr;
  }

  printf( "\n" );

  return;
}

void reassign_address( TeleType* list )
{
  int temp_index = -1;
  TeleType* init_list = list;
  TeleType* next_node = NULL;
  TeleType* temp_list = list;
  TeleType* delete_node = NULL;

  printf( "Enter the element to delete:\n" );
  scanf( " %d", &temp_index );
  fflush( stdin );

  for( int i = 1; i <= MAXRECS; i++ )
  {
    if( i == temp_index )
    {
      next_node = temp_list->nextaddr;
      break;
    }

    temp_list = temp_list->nextaddr;
  }

  for( int j = 1; j <= MAXRECS; j++ )
  {
    if( j == temp_index - 1 )
    {
      delete_node = list->nextaddr;
      list->nextaddr = next_node;
      break;
    }

    list = list->nextaddr;
  }

  list = init_list;

  eliminar( delete_node );

  return;
}

void eliminar( TeleType* address_kill )
{
  free( address_kill );
}
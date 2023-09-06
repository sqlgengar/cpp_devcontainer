/*

Generalice la descripción obtenida en el ejercicio 3 para describir la secuencia 
de pasos necesaria para eliminar la n-ésima estructura de una lista de estructuras
vinculadas. La n-ésima estructura es precedida por la estructura (n – 1) y es seguida por la estructura (n + 1). Asegúrese de almacenar en forma correcta todos los
valores apuntadores.

*/

#include <stdio.h>

typedef struct TeleType
{
  char name[500];
  char phoneNo[500];
  struct TeleType *nextaddr;
} TeleType;

int count_elements_list( TeleType* );
int input_delete( int );
TeleType* find_n_minus_one( TeleType*, int );
TeleType* find_n_plus_one( TeleType*, int );
void reassign_adress( TeleType*, TeleType*, TeleType* );
void display( TeleType* );

int main()
{
  int index_delete = -1;
  int elements_list = 0;
  TeleType* address_minus_one = NULL;
  TeleType* address_plus_one = NULL;

  TeleType t1 = {"Acme, Sam","(555) 898-2392"};
  TeleType t2 = {"Dolan, Edith","(555) 682-3104"};
  TeleType t3 = {"Lanfrank, John","(555) 718-4581"};
  TeleType t4 = {"Perez, Alejandro","(555) 321-9876"};
  TeleType t5 = {"Gonzalez , Maria","(555) 789-6543"};
  TeleType *first;

  first = &t1;
  t1.nextaddr = &t2;
  t2.nextaddr = &t3;
  t3.nextaddr = &t4;
  t4.nextaddr = &t5;
  t5.nextaddr = NULL;

  elements_list =     count_elements_list( first );
  index_delete =      input_delete( elements_list );
  address_minus_one = find_n_minus_one( first, index_delete );
  address_plus_one =  find_n_plus_one( first, index_delete );
  
  reassign_adress( first, address_minus_one, address_plus_one );

  display(first);
  return 0;
}

int count_elements_list( TeleType* list )
{
  int temp_count = 0;

  while( list != NULL )
  {
    temp_count++;
    list = list->nextaddr;
  }

  return temp_count;
}

int input_delete( int max_elements )
{
  int temp_input = -1;

  while( temp_input <= 0 || temp_input >= max_elements )
  {
    printf( "Ingrese el elemento que desea eliminar: \n" );
    scanf( " %d", &temp_input );
    fflush( stdin );
  }
  
  return temp_input;
}

TeleType* find_n_minus_one( TeleType* list, int index )
{
  TeleType* temp_address = NULL;
  int count = 1;
  int index_find = index - 1;

  while( list != NULL )
  {
    if( count == index_find )
    {
      temp_address = list;
      return temp_address;
    }

    list = list->nextaddr;
    count++;
  }
}

TeleType* find_n_plus_one( TeleType* list, int index )
{
  TeleType* temp_address = NULL;
  int count = 1;
  int index_find = index + 1;

  while( list != NULL )
  {
    if( count == index_find )
    {
      temp_address = list;
      return temp_address;
    }

    list = list->nextaddr;
    count++;
  }
}

void reassign_adress( TeleType* list, TeleType* adrress_index, TeleType* adrress_next )
{
  while( list != NULL )
  {
    if( list == adrress_index )
    {
      list->nextaddr = adrress_next;
      return;
    }

    list = list->nextaddr;
  }
}

void display( TeleType *contents )
{
  while (contents != NULL)
  {
    printf( "%s %s \n", contents->name, contents->phoneNo );

    contents = contents->nextaddr;
  }
  
  printf( "\n" );

  return;
}
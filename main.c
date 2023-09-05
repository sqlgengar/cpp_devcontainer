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

void reassign_nodes( TeleType* );
void display( TeleType* );

int main()
{
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

  reassign_nodes( first );

  display(first);
  return 0;
}

void reassign_nodes( TeleType* list )
{
  int temp_index = 0;
  int count_index = 1;

  printf( "Ingrese el elemento que quiere quitar de la lista (1-5): \n" );
  scanf( " %d", &temp_index );
  fflush( stdin );

  while( list != NULL )
  {
    if( count_index == temp_index )
    {
      list = list->nextaddr;
    }

    list = list->nextaddr;
    count_index++;
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
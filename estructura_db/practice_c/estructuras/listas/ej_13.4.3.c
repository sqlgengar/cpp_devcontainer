/*

Usando la lista de estructuras vinculada ilustrada en la figura 13.13, escriba la secuencia de pasos necesaria para eliminar de la lista el registro de Edith Domínguez.

*/

#include <stdio.h>

typedef struct TeleType
{
  char name[500];
  char phoneNo[500];
  struct TeleType *nextaddr;
} TeleType;

void display( TeleType* );

int main()
{
  TeleType t1 = {"Acme, Sam","(555) 898-2392"};
  TeleType t2 = {"Dolan, Edith","(555) 682-3104"};
  TeleType t3 = {"Lanfrank, John","(555) 718-4581"};
  TeleType *first;

  first = &t1;
  t1.nextaddr = &t2;
  t2.nextaddr = &t3;
  t3.nextaddr = NULL;

  t1.nextaddr = &t3;

  display(first);
  return 0;
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
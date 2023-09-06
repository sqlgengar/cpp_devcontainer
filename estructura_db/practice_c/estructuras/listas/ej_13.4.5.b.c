/*

ando el tipo definido en el ejercicio 5a, modifique el programa 13.9 para enlistar los nombres y números telefónicos en orden inverso.

*/

#include <stdio.h>

typedef struct TeleType
{
  struct TeleType *lastaddr;
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
  TeleType t4 = {"Perez, Alejandro","(555) 321-9876"};
  TeleType t5 = {"Gonzalez , Maria","(555) 789-6543"};
  TeleType *first;
  TeleType *last;

  first = &t1;
  last = &t5;

  t1.lastaddr = NULL;
  t1.nextaddr = &t2;

  t2.lastaddr = &t1;
  t2.nextaddr = &t3;

  t3.lastaddr = &t2;
  t3.nextaddr = &t4;

  t4.lastaddr = &t3;
  t4.nextaddr = &t5;

  t5.lastaddr = &t4;
  t5.nextaddr = NULL;

  display(last);
  return 0;
}

void display( TeleType *contents )
{
  while (contents != NULL)
  {
    printf( "%s %s \n", contents->name, contents->phoneNo );

    contents = contents->lastaddr;
  }
  
  printf( "\n" );

  return;
}
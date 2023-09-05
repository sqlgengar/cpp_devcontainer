/*

Modifique el programa 13.9 para solicitar al usuario un nombre. Haga que el programa busque el nombre introducido en la lista existente. Si el nombre está en la
lista, despliegue el número telefónico correspondiente; de lo contrario despliegue
este mensaje:
El nombre no está en el directorio telefónico actual

#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;
struct TeleType
{
  string name;
  string phoneNo;
  TeleType *nextaddr;
};
void display(TeleType *);       // function prototype
int main()
{
  TeleType t1 = {"Acme, Sam","(555) 898-2392"};
  TeleType t2 = {"Dolan, Edith","(555) 682-3104"};
  TeleType t3 = {"Lanfrank, John","(555) 718-4581"};
  TeleType *first;    // create a pointer to a structure
  first = &t1;        // store t1's address in first
  t1.nextaddr = &t2;  // store t2's address in t1.nextaddr
  t2.nextaddr = &t3;  // store t3's address in t2.nextaddr
  t3.nextaddr = NULL; // store the NULL address in t3.nextaddr
  display(first);     // send the address of the first structure
  return 0;
}
void display(TeleType *contents) // contents is a pointer to a stru
{                                // of type TeleType
  while (contents != NULL)   // display till end of linked list
  {
    cout << endl << setiosflags(ios::left)
         << setw(30) << contents->name
         << setw(20) << contents->phoneNo ;
    contents = contents->nextaddr;     // get next address
  }
  cout << endl;
  return;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TeleType
{
  char name[500];
  char phoneNo[500];
  struct TeleType* nextaddr;
} TeleType;

void display( char* );
void input_name( TeleType* );

int main()
{
  TeleType t1 = {"Acme, Sam","(555) 898-2392"};
  TeleType t2 = {"Dolan, Edith","(555) 682-3104"};
  TeleType t3 = {"Lanfrank, John","(555) 718-4581"};
  TeleType *primero;    // create a pointer to a structure
  primero = &t1;        // store t1's address in first
  t1.nextaddr = &t2;  // store t2's address in t1.nextaddr
  t2.nextaddr = &t3;  // store t3's address in t2.nextaddr
  t3.nextaddr = NULL; // store the NULL address in t3.nextaddr

  input_name( primero );

  return 0;
}

void input_name( TeleType* list )
{
  char temp_name[500];
  char* delimiter = ", ";
  char* token = NULL;
  int result_match = 0;

  printf( "Ingrese un nombre: \n" );
  scanf( " %s", temp_name );
  fflush( stdin );

  while( list != NULL )
  {
    token = strtok( list->name, delimiter );
    token = strtok( NULL, delimiter );

    result_match = strcmp( token, temp_name );
    if( result_match == 0 ) display( list->phoneNo );

    list = list->nextaddr;
  }

  printf( "El nombre no está en el directorio telefónico actual" );
}

void display( char* tel )
{
  printf( "%s \n", tel );
  exit( EXIT_SUCCESS );
}
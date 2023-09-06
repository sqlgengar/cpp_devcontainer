/*

 Como se describió en la tabla 13.1, el operador new devuelve la dirección de la
primera área de almacenamiento nueva asignada o NULL si no se dispone de almacenamiento suficiente. Modifique el programa 13.11 para comprobar que se ha
devuelto una dirección válida antes que se haga una llamada a poblar(). Despliegue un mensaje apropiado si no se dispone de almacenamiento suficiente.

include  <iostream>
#include  <iomanip>
#include  <string>
using  namespace  std;
const  int  MAXRECS  =  3;      //  maximum  no.  of  records
struct  TeleType
{
    char  name;
    char  phoneNo;
    TeleType  *nextaddr;
};
void  populate(TeleType  *);      //  function  prototype  needed  by  main(
void  display(TeleType  *);        //  function  prototype  needed  by  main(
int  main()
{
    int  i;
    TeleType  *list,  *current;  //  two  pointers  to  structures  of
                                                        //  type  TeleType
        //  get  a  pointer  to  the  first  structure  in  the  list
    list  =  new  TeleType;
    current  =  list;
        //  populate  the  current  structure  and  create  the  remaining  str
    for(i  =  0;  i  <  MAXRECS  -  1;  i++)
    {
        populate(current);
        current->nextaddr  =  new  TeleType;
        current  =  current->nextaddr;
    }
    populate(current);                  //  populate  the  last  structure
    current->nextaddr  =  NULL;    //  set  the  last  address  to  a  NULL  add
    cout  <<  "\nThe  list  consists  of  the  following  records:\n";
    display(list);      //  display  the  structures
    return  0;
}
    //  input  a  name  and  phone  number
void  populate(TeleType  *record)  //  record  is  a  pointer  to  a
{                                                              //  structure  of  type  TeleType
    cout  <<  "Enter  a  name:  ";
    getline(cin,record->name);
    cout  <<  "Enter  the  phone  number:  ";
    getline(cin,record->phoneNo);
    return;
}
void  display(TeleType  *contents)  //  contents  is  a  pointer  to  a
{                                                                            //  structure  of  type  TeleType
    while  (contents  !=  NULL)                //  display  till  end  of  linked  list
    {
        cout  <<  endl  <<  setiosflags(ios::left)
                <<  setw(30)  <<  contents->name
                <<  setw(20)  <<  contents->phoneNo;
        contents  =  contents->nextaddr;
    }
    cout  <<  endl;
    return;
}

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

int  main()
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
/*

Escriba un programa en C++ que contenga una lista vinculada de diez números enteros. Haga que el programa despliegue los números en la lista.

*/

#include <stdio.h>

typedef struct numbers
{
  int number;
  struct numbers* next_node;
} Node;

void printer( Node* );

int main()
{
  /* Inicnializar valores de la lista */
  Node n1 = {1};
  Node n2 = {2};
  Node n3 = {3};
  Node n4 = {4};
  Node n5 = {5};
  Node n6 = {6};
  Node n7 = {7};
  Node n8 = {8};
  Node n9 = {9};
  Node n10 = {10};

  /* Inicializar direcciones de la lista */
  Node* init_list = &n1;
  n1.next_node = &n2;
  n2.next_node = &n3;
  n3.next_node = &n4;
  n4.next_node = &n5;
  n5.next_node = &n6;
  n6.next_node = &n7;
  n7.next_node = &n8;
  n8.next_node = &n9;
  n9.next_node = &n10;
  n10.next_node = NULL;

  printer( init_list );
}

void printer( Node* list )
{
  while( list != NULL )
  {
    printf( "%d \n", list->number );

    list = list->next_node;
  }
}
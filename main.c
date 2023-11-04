/*
** La idea de este script es poder practicar arboles binarios balanceados(AVL).
** Estos arboles son de grado 2, eso significa que cada nodo contiene su valor, y la referencia a sus dos nodos hijos.
** Estos arboles siempre se arman con la regla de que a la izquierda se ubica un nodo con menor valor, y a la derecha un nodo con mayor valor.
** Estos arboles tiene la paticularidad de siempre estan balanceados, es factor de balanceo tiene que estar siempre entre -1 y 1.
** Los nodos a la izquierda tiene valor -1 y los nodos a la derecha tiene valor 1. Al sumarlos da el factor de balance.
** https://www.youtube.com/watch?v=vRwi_UcZGjU
** https://github.com/GunterMueller/Books-3/blob/master/Data%20Structure%20and%20Algorithm%20Analysis%20in%20C%2B%2B%204th%20ed.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estructura para un nodo del arbol binario AVL
struct avl_node
{
  int data;
  struct avl_node* left;
  struct avl_node* right;
  int height;
};

int get_height( struct avl_node* );
int max( int, int );
struct avl_node* create_node( int );
struct avl_node* rotate_right( struct avl_node* );
struct avl_node* rotate_left( struct avl_node* x );
struct avl_node* insert( struct avl_node*, int );
void print_tree( struct avl_node*, int );

int main()
{
  struct avl_node* root =  NULL;
  int temp_value =        0;

  while( true )
  {
    printf( "Ingrese un valor entero para el arbol:\n" );
    scanf( " %d", &temp_value );
    fflush( stdin );

    insert( root, temp_value );

    printf( "\nRepresentacion grafica del arbol:\n" );
    print_tree( root, 0 );
    printf( "\n" );
  }

  return 0;
}

// Funcion para obtener la altura de un nodo (o -1 si es nulo)
int get_height( struct avl_node* node )
{
  if( node == NULL ) return -1;

  return node->height;
}

// Funcion para obtener el maximo de dos enteros
int max( int a, int b )
{
  return( a > b ) ? a : b;
}

// Funcion para crear un nuevo nodo
struct avl_node* create_node( int value )
{
  struct avl_node* new_node = (struct avl_node*)malloc( sizeof( struct avl_node ) );

  new_node->data =    value;
  new_node->left =    NULL;
  new_node->right =   NULL;
  new_node->height =  0;

  return new_node;
}

// Funcion para rotar un nodo hacia la derecha
struct avl_node* rotate_right( struct avl_node* y )
{
  struct avl_node* x =  y->left;
  struct avl_node* T2 = x->right;

  x->right =  y;
  y->left =   T2;

  printf( "Rotar derecha\n" );
  y->height = max( get_height( y->left ), get_height( y->right ) ) + 1;
  x->height = max( get_height( x->left ), get_height( x->right ) ) + 1;

  return x;
}

// Funcion para rotar un nodo hacia la izquierda
struct avl_node* rotate_left( struct avl_node* x )
{
  struct avl_node* y =  x->right;
  struct avl_node* T2 = y->left;

  y->left =   x;
  x->right =  T2;

  printf( "Rotar izquierda\n" );
  x->height = max( get_height( x->left ), get_height( x->right ) ) + 1;
  y->height = max( get_height( y->left ), get_height( y->right ) ) + 1;

  return y;
}

// Funcion para equilibrar el arbol AVL despues de insertar un nodo
struct avl_node* insert( struct avl_node* node, int value )
{
  if( node == NULL ) return create_node(value);

  if( value < node->data )
  {
    node->left = insert(node->left, value);
    return node;
  }
  if( value > node->data )
  {
    node->right = insert(node->right, value);
    return node;
  }
  if( value = node->data ) return node;

  node->height = 1 + max( get_height( node->left ), get_height( node->right ) );

  int balance = get_height( node->left ) - get_height( node->right );

  // Caso Izquierda-Izquierda
  if( balance > 1 && value < node->left->data ) return rotate_right( node );

  // Caso Derecha-Derecha
  if( balance < -1 && value > node->right->data ) return rotate_left( node );

  // Caso Izquierda-Derecha
  if( balance > 1 && value > node->left->data )
  {
    node->left = rotate_left( node->left );
    return rotate_right( node );
  }

  // Caso Derecha-Izquierda
  if( balance < -1 && value < node->right->data )
  {
    node->right = rotate_right( node->right );
    return rotate_left( node );
  }

  return node;
}

// Función para imprimir el árbol graficamente
void print_tree( struct avl_node* root, int level )
{
  if( root != NULL )
  {
    print_tree( root->right, level + 1 );
    for( int i = 0; i < level; i++ )
    {
      printf("    ");
    }
    printf( "%d (L %d)\n", root->data, level );
    print_tree( root->left, level + 1 );
  }

  return;
}
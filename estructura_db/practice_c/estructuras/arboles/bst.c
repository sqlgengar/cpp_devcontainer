/*
** La idea de este script es poder practicar arboles binarios de busqueda(BST).
** Estos arboles son de grado 2, eso significa que cada nodo contiene su valor, y la referencia a sus dos nodos hijos.
** Estos arboles siempre se arman con la regla de que a la izquierda se ubica un nodo con menor valor, y a la derecha un nodo con mayor valor.
** Ademas existen tres formas de recorrer estos arboles, in-order, pre-order, post-order.
** Esto solo afecta al algoritmo de busqueda, el arbol es uno solo siempre.
** https://www.youtube.com/watch?v=tBaOQeyXYqg
** https://github.com/GunterMueller/Books-3/blob/master/Data%20Structure%20and%20Algorithm%20Analysis%20in%20C%2B%2B%204th%20ed.pdf
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Estructura para un nodo del arbol binario
struct TreeNode
{
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
};


struct TreeNode* createNode( int );
struct TreeNode* insert( struct TreeNode*, int );
void displayInOrder( struct TreeNode* root );
void printTree( struct TreeNode*, int );
void displayInOrder( struct TreeNode* );
void displayPreOrder( struct TreeNode* );
void displayPostOrder( struct TreeNode* );


int main()
{
  struct TreeNode* root = NULL;
  int temp_value = 0;

  while( true )
  {
    printf( "Ingrese un valor entero para el arbol: \n" );
    scanf( " %d", &temp_value );
    fflush( stdin );

    root = insert( root, temp_value );

    printf( "\n" );
    printf( "Arbol binario en orden: " );
    displayInOrder( root );
    printf( "\n" );

    printf( "Arbol binario en preorden: " );
    displayPreOrder( root );
    printf( "\n" );

    printf( "Arbol binario en postorden: " );
    displayPostOrder( root );
    printf( "\n" );

    printf( "\nRepresentación gráfica del árbol:\n" );
    printTree( root, 0 );
    printf( "\n" );
  }

  return 0;
}


// Funcion para crear un nuevo nodo
struct TreeNode* createNode( int value )
{
  struct TreeNode* newNode = (struct TreeNode*)malloc( sizeof( struct TreeNode ) );

  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Funcion para insertar un valor en el arbol
struct TreeNode* insert( struct TreeNode* root, int value )
{
  if(root == NULL)
  {
    return createNode( value );
  }

  if( value < root->data )
  {
    root->left = insert( root->left, value );
    return root;
  }

  if( value > root->data )
  {
    root->right = insert( root->right, value );
    return root;
  }

  return root;
}

// Funcion para mostrar el arbol en orden (in-order)
void displayInOrder( struct TreeNode* root )
{
  if( root != NULL )
  {
    displayInOrder( root->left );
    printf( "%d ", root->data );
    displayInOrder( root->right );
  }

  return;
}

// Funcion para mostrar el arbol en preorden (pre-order)
void displayPreOrder( struct TreeNode* root )
{
  if( root != NULL )
  {
    printf( "%d ", root->data );
    displayPreOrder( root->left );
    displayPreOrder( root->right );
  }

  return;
}

// Funcion para mostrar el arbol en postorden (post-order)
void displayPostOrder( struct TreeNode* root )
{
  if( root != NULL )
  {
    displayPostOrder( root->left );
    displayPostOrder( root->right );
    printf( "%d ", root->data );
  }

  return;
}

// Función para imprimir el árbol graficamente
void printTree( struct TreeNode* root, int level )
{
  if( root != NULL )
  {
    printTree( root->right, level + 1 );
    for( int i = 0; i < level; i++ )
    {
      printf("    ");
    }
    printf( "%d (L %d)\n", root->data, level );
    printTree( root->left, level + 1 );
  }

  return;
}
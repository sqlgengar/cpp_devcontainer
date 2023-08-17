#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo
{
    int number;
    struct nodo* last;
} nodo;

nodo* create_node();
void show_menu();
void resolve_option( int, nodo* );
void add_node( nodo** );
void printer( nodo* );
void delete_node( nodo** );

int main()
{
    show_menu();
    return 0;
}

nodo* create_node()
{
    int temp_number;
    nodo *temp_pila;
    
    temp_pila = ( nodo* )malloc( sizeof( nodo ) );

    printf( "Ingrese un numero: \n " );

    scanf( " %d", &temp_number );

    temp_pila->number = temp_number;
    temp_pila->last =   NULL;

    return temp_pila;
}

void show_menu()
{
    int temp_option =   0;
    nodo *pila =        NULL;
    pila =              create_node();

    while( true )
    {
        printf( "1) Agregar nodo a la pila \n" );
        printf( "2) Eliminar nodo a la pila \n" );
        printf( "3) Salir \n" );
        printf( "4) mostrar \n" );

        scanf( " %d", &temp_option );

        if( temp_option == 3 ) exit( EXIT_SUCCESS );

        resolve_option( temp_option, pila );
    }
}

void resolve_option( int option, nodo* pila )
{
    switch( option )
    {
        case 1:
            add_node( &pila );
        break;
        case 2:
            delete_node( &pila );
        break;
        case 4:
            printer( pila );
        break;
    }
}

void add_node( nodo** pila )
{
    nodo *new_data =    NULL;
    new_data =          create_node();

    nodo* temp = *pila;
    while( temp->last != NULL )
    {
            temp = temp->last;
    }
    temp->last = new_data;
}

void printer( nodo* data_pila )
{
    nodo* aux = data_pila;

    while( aux != NULL )
    {
        printf( "Number: %d, Address of last: %p \n", aux->number, (void*)aux->last );
        aux = aux->last;
    }
}

void delete_node( nodo** pila )
{
    nodo data;
    nodo *aux;

    aux =   *pila;
    /*data =  **pila;*/
    *pila = (*pila)->last;

    /*printf( "data %d \n", data.number );*/
    /*printf( "aux %d \n", aux->number );*/

    free( aux );

    
}
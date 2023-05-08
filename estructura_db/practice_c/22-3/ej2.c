/*
Dado este vector, utilzar un puntero hacia la lista y recorrelo con el puntero
int lista [] = { 24, 30, 15, 45, 34 };
*/

#include <stdio.h>

#define MAX_ELEMENTS 5

int main()
{
    int lista [MAX_ELEMENTS] = { 24, 30, 15, 45, 34 };
    int *pointer;

    pointer = &lista;

    for( int i = 0; i < MAX_ELEMENTS; i++ )
    {
        printf( "%d \n", *( pointer + i ) );
    }

    return 0;
}
/*
    Realizar un programa que dada la captura de la cadena, y determinar lo siguiente.
    A) El largo de la cadena, realizando una funcion llamada cuenta_caracteres.
    B) La cantidad de palabras ingresadas, realizando una funcion llamada cuenta_pal.
    C) La cantidad de letras y numeros que posee ese texto realizando una funcion llamada cuenta_letras.
    D) Convertir la cadena ingresada en mayusculas en manteniendo la original, realizando una funcion llamada mayu.
    E) Mostrar la cadena invertida(recursividad).
    G) Dada una vocal determinada indicar la cantidad de apariciones en el texto en una funcion llamada cantidad_vocal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 80

void count_length( char[MAX_CHAR] );
void count_word( char[MAX_CHAR] );

int main()
{
    char text[MAX_CHAR];

    printf( "Enter a text: \n" );
    fgets( text, MAX_CHAR, stdin );

    count_length( text );

    return 0;
}

void count_length( char current_text[MAX_CHAR] )
{
    int temp_count = 0;

    while( *current_text != '\0' )
    {
        temp_count++;
        current_text++;
    }

    printf( "The lenght of string is: %d \n", temp_count );
}


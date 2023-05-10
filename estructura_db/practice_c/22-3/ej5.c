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
#include <ctype.h>

#define MAX_CHAR 80

void length_string( char[MAX_CHAR] );
void count_word( char[MAX_CHAR] );
void count_char( char[MAX_CHAR] );
void upper_case( char[MAX_CHAR] );

int main()
{
    char text[MAX_CHAR];

    printf( "Enter a text: \n" );
    fgets( text, MAX_CHAR, stdin );

    length_string( text );

    count_word( text );

    count_char( text );

    upper_case( text );

    return 0;
}

void length_string( char current_text[MAX_CHAR] )
{
    int temp_length;

    temp_length = strlen( current_text );

    printf( "The length of text is: %d \n", temp_length );
}

void count_word( char split_text[MAX_CHAR] )
{
    char *sub_string;
    char *token =           " ";
    int temp_count_words =  0;

    sub_string = strtok( split_text, token );

    while( sub_string != NULL )
    {
        temp_count_words++;

        sub_string = strtok( NULL, token );
    }

    printf( "The amount of words is: %d \n", temp_count_words );
}

void count_char( char chars[MAX_CHAR] )
{
    int temp_amount_letters =   0;
    int temp_amount_numbers =   0;

    while( *chars != '\n' )
    {
        if( isalpha( *chars ) )
        {
            temp_amount_letters++;
        }
        if( isdigit( *chars )  )
        {
            temp_amount_numbers++;
        }
        chars++;
    }

    printf( "The amount of letters is: %d \n", temp_amount_letters );
    printf( "The amount of numbers is: %d \n", temp_amount_numbers );
}

void upper_case( char origin_string[MAX_CHAR] )
{
    while( *origin_string != '\n' )
    {
        *origin_string = toupper( *origin_string );
        if( *origin_string == '\0' )
        {
            printf( " " );    
        }
        if( *origin_string != '\0' )
        {
            printf( "%c", *origin_string );
        }
        origin_string++;
    }
    printf( "\n");
}
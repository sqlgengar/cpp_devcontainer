/*
Hacer un programa que pida al usuario la cantidad de elementos que necesita almeacenar, para ello realizqar la funcion cargar
luego mostrar el vector pasandole el titulo vector desordenado. Luego ordenar ese vector y mostrarlo con el titulo vetor ordenado,
por ultimo liberar el espacio de memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE_RAND 100

void load_data( int*, int );
void print_r( int*, int );
void order_data( int*, int );

int main()
{
    int *memory;
    int size_array;

    /*  
        La creacion de la memoria dinamica se debe hacer en main
        Si se queire hacer en una funcion aparte se debera utilizar un puntero a funcion
    */
    /*----------------------------------------------ASIGNACION-MEMORIA-DINAMICA---------------------------------------------------*/
    printf( "Enter the amount of element for array: \n" );
    scanf( " %d", &size_array );
    fflush( stdin );

    memory = (int*)calloc( size_array, sizeof(int) );
    /*----------------------------------------------------------------------------------------------------------------------------*/

    load_data( memory, size_array );

    print_r( memory, size_array );

    printf( "\n\n" );

    order_data( memory, size_array );

    free( memory );
    return 0;
}

void load_data( int *data_array, int size )
{
    int temp_rand;

    srand(time(NULL));

    for( int i = 0; i < size; i++ )
    {
        temp_rand = rand() % MAX_VALUE_RAND;

        *( data_array + i ) = temp_rand;
    }
}

void print_r( int *array_rand, int size )
{
    for ( int i = 0; i < size; i++ )
    {
        printf( "%d \n", *array_rand++ );
    }
}

void order_data( int *order_array, int size )
{
    int temp_data;

    for( int i = 0; i < size; i++ )
    {
        int temp_comp;

        temp_comp = *( order_array + i ) - *( order_array + ( i+1 ) );

        if( temp_comp < 0 )
        {
            temp_data =                     *( order_array + i );
            *( order_array + i ) =          *( order_array + ( i+1 ) );
            *( order_array + ( i+1 ) ) =    temp_data;

            if( !i ) continue;

            for( int j = i; j >= 0; j-- )
            {
                temp_comp = *( order_array + j ) - *( order_array + ( j-1 ) );

                if( temp_comp < 0 ) break;
                
                temp_data =                     *( order_array + j );
                *( order_array + j ) =          *( order_array + ( j-1 ) );
                *( order_array + ( j-1 ) ) =    temp_data;
            }
        }
    }

    print_r( order_array, size );
}
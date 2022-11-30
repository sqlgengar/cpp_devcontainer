#include <stdio.h>
#include <stdlib.h>

/*
    TODO: practica numero 4 funciones recusivas
*/

int sum_r( int );

int main(){

    int input_number = 0,
        final_add = 0;

    printf( "Ingrese un numero entero: \n" );
    scanf( " %d", &input_number );
    
    final_add = sum_r( input_number );
    
    printf( "La suma de las cifras es: %i \n", final_add );

    printf( "script done \n" );
    return 0;

}

int sum_r( int number ){

    if( number > 0 ){

        return( sum_r( number / 10 ) + number % 10 );
    
    }
    else{

        return number;

    }

}
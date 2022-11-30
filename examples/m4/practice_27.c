#include <stdio.h>

/*
    TODO: practica numero 4 funciones recusivas
*/

int mult_r( int, int );

int main(){

    int first_number = 0,
        second_number = 0,
        final_mult = 0;

    printf( "Ingrese un numero entero: \n" );
    scanf( " %d", &first_number );

    printf( "Ingrese otro numero entero: \n" );
    scanf( " %d", &second_number );
    
    final_mult = mult_r( first_number, second_number );
    
    printf( "La multiplicaion de los numeros es: %i \n", final_mult );

    printf( "script done \n" );
    return 0;

}

int mult_r( int number_1, int number_2 ){

    if( number_2 > 0 ){

        return( mult_r( number_1, number_2 - 1 ) + number_1 );
    
    }
    else{

        return number_2;

    }

}
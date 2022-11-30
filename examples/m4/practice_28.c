#include <stdio.h>

/*
    TODO: practica numero 4 funciones recusivas
*/

void print_r_desc( int );
void print_r_asc( int, int );

int main(){

    int number_n = 0,
        count = 1;

    printf( "Ingrese un numero entero: \n" );
    scanf( " %d", &number_n );
    
    print_r_desc( number_n );
    print_r_asc( number_n, count );

    printf( "script done \n" );
    return 0;

}

void print_r_desc( int number ){

    if( number > 0 ){

        printf( "%i \n", number );
        print_r_desc( number - 1 );
    
    }

}

void print_r_asc( int number, int count ){

    if( number >= count ){

        printf( "%i \n", count );
        print_r_asc( number, count + 1 );
    
    }

}
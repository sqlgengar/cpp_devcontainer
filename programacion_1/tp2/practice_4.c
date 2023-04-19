#include <stdio.h>

int main(){

    int number;

    printf( "enter a number: \n");

    scanf( "%i", &number );
    fflush( stdin );

    if( ( number % 2 ) != 0 ){

        printf( "the number are odd \n" );
        exit(0);

    }

    printf( "the number are even \n" );

    return 0;

}
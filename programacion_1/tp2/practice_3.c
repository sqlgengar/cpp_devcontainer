#include <stdio.h>

int main(){

    int firts_number,
        second_number;

    printf( "enter a number: \n");

    scanf( "%i", &firts_number );
    fflush( stdin );

    printf( "enter a number: \n");

    scanf( "%i", &second_number );
    fflush( stdin );

    if( firts_number != second_number ){

        printf( "bouth number not are equal \n" );
        exit(0);

    }

    printf( "bouth number are equal \n" );

    return 0;

}
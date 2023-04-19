#include <stdio.h>

int main(){

    int first_number,
        second_number;

    printf( "enter a number: \n");

    scanf( "%i", &first_number );
    fflush(stdin) ;

    printf( "enter a number: \n");

    scanf( "%i", &second_number );
    fflush(stdin);

    if( ( first_number + second_number ) % 2 != 0 ){

        printf( "the add between bouth numbers are odd \n" );
        exit(0);

    }

    printf( "the add between bouth numbers are even \n" );

    return 0;

}
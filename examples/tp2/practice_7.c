#include <stdio.h>
#include <stdlib.h>

int main(){

    int number;

    printf( "enter a number of fourth digits: \n");

    scanf( "%i", &number );
    fflush(stdin) ;

    if( ( number / 100 ) != ( number % 100 ) ){

        printf( "the number not is palindromic \n" );
        exit(0);

    }

    printf( "the number is palindromic \n" );

    return 0;

}
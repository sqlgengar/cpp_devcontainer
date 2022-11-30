#include <stdio.h>

int main (){

        short int number;

        printf( "enter a interger number: \n" );

        scanf( "%hi", &number );
        fflush( stdin );

        printf( "the last number is %hi \n", number % 10 );

        return 0;

}

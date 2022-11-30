#include <stdio.h>

int main(){

    int first_number,
        second_number,
        third_number;

    printf( "enter a number: \n");

    scanf( "%i", &first_number );
    fflush(stdin) ;

    printf( "enter a number: \n");

    scanf( "%i", &second_number );
    fflush(stdin);

    printf( "enter a number: \n");

    scanf( "%i", &third_number );
    fflush(stdin);

    if( first_number == second_number == third_number ){

        printf( "the numbers are equal \n" );
        exit(0);

    }

    if( (first_number < second_number) < third_number ){

        printf( "the first number is the lower \n" );
        exit(0);

    }
    else if( second_number < first_number < third_number ){

        printf( "the second number is the lower \n" );
        exit(0);

    }

    printf( "the third number is the lower \n" );

    return 0;

}
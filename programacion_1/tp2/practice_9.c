#include <stdio.h>
#include <stdlib.h>

int main(){

    char first_letter,
         second_letter,
         third_letter;
    
    printf( "enter the first letter: \n");

    scanf( "%c", &first_letter );
    fflush(stdin);

    printf( "enter the second letter \n");

    scanf( "%c", &second_letter );
    fflush(stdin);

    printf( "enter the third letter \n");

    scanf( "%c", &third_letter );
    fflush(stdin);

    if( type_travel == 's' && weigth < 20 ){

        printf( "the cost on travel are $1500 \n" );
        exit(0);

    }
    else if( type_travel == 's' && weigth > 20 ){

            printf( "the cost on travel are $%i \n", 1500 + ( ( weigth - 20 ) * 800 ) );
            exit(0);

        }
        else if( type_travel == 'l' && weigth < 20 ){

                printf( "the cost on travel are $2000 \n" );
                exit(0);

            }

    printf( "the cost on travel are $%i \n", 2000 + ( ( weigth - 20 ) / 5 ) * 800 );

    return 0;

}
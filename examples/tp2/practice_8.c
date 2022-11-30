#include <stdio.h>
#include <stdlib.h>

int main(){

    int weigth;
    char type_travel;
    
    printf( "enter the type of travel: (s\\l) \n");

    scanf( "%c", &type_travel );
    fflush(stdin);

    printf( "enter the amount of travel: \n");

    scanf( "%i", &weigth );
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
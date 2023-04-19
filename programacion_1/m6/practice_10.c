#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int is_repeat( int[], int );

int main(){

        int 	array[SIZE],
		i = 0;

        do{

		int count_repeat = 0;

                printf( "Enter a value for the array or zero for exit \n" );
                scanf( " %d", &array[i] );
                fflush( stdin );

		count_repeat = is_repeat( array, array[i] );

		printf( "the count repeat for %d is %d \n", array[i], count_repeat );

		i++;

        }while( i < SIZE );

        printf( "script done \n" );
        return 0;

}

int is_repeat( int array[SIZE], int value ){

        int count_repeat = 0;

	if( !value ){

		exit( EXIT_SUCCESS );//exit by the user
		
	}

	for( int i = 0; i < SIZE; i++ ){

		if( array[i] == value ){

			count_repeat++;

		}

	}

	return count_repeat;

}

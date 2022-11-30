#include <stdio.h>
#define SIZE 4

void show_non_repeat( int[] );

int main(){

	int array[SIZE];

	for( int i = 0; i < SIZE; i++ ){
		
		printf( "Enter a value for the array \n" );
		scanf( " %d", &array[i] );
		fflush( stdin );

	}
	
	show_non_repeat( array );

	printf( "script done \n" );
	return 0;

}

void show_non_repeat( int array[SIZE] ){

	int 	array_non_repeat[SIZE],
		count_repeat = -1,
		index_non_repeat = 0;

	array_non_repeat[0] = array[0];

	for( int i = 0; i < SIZE; i++ ){

		int is_repeat = 0;

		for( int j = 0; j < SIZE; j++ ){

			if( array[j] == array_non_repeat[i] ){

				is_repeat = 1;
				count_repeat++;

			}

		}

		if( !is_repeat ){

			array_non_repeat[index_non_repeat] = array[i];
			index_non_repeat++;

		}

	}

	for( int k = 0; k < (SIZE - count_repeat); k++ ){

		printf( "array_non_repeat[%d] -> %d \n", k, array_non_repeat[k] );

	}

}

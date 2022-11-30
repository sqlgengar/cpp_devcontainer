#include <stdio.h>
#define SIZE 10

int main(){

	int value = -1,
	    index = -1,
	    bingo[SIZE];

	for( int i = 0; i < 10; i++ ){

		printf( "Enter the position: (0-10) \n" );
		scanf( " %d", &index );

		printf( "Enter the value of position: \n" );
		scanf( " %d", &value );

		bingo[index] = value;

	}

	for( int j = 0; j < 10; j++ ){

		printf( "Position %d, value %d \n", j, bingo[j] );

	}

	return 0;

}


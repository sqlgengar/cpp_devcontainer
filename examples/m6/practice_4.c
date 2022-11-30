#include <stdio.h>
#define COUNT_COND 4
#define SIZE_H 20

void show_histogram( char[][SIZE_H] );

int main(){

	char histogram[COUNT_COND][SIZE_H];

	for( int i = 0; i < COUNT_COND; i++ ){

			printf( "enter a value to histogram: \n" );
			fgets( histogram[i], SIZE_H, stdin );
			fflush( stdin );

	}

	show_histogram( histogram );

	printf( "script done \n" );
	return 0;

}

void show_histogram( char histogram[][SIZE_H] ){

	for( int i = 0; i < COUNT_COND; i++ ){

		printf( "Cond %d: %s", i+1, histogram[i] );

	}

}


//1: ***
//2: **
//Cond 1:

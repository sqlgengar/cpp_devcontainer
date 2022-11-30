#include <stdio.h>
#define SIZE_ARRAY 100

void load_array( float[SIZE_ARRAY], int );
void print_r( float[SIZE_ARRAY], int );

int main(){

	int 	n;
	float 	array[SIZE_ARRAY];

	printf( "Enter the index max of array \n" );
	scanf( " %d", &n );
	fflush( stdin );

	load_array( array, n );
	print_r( array, n );

	printf( "\n script done \n" );

	return 0;

}

void load_array( float array[SIZE_ARRAY], int n ){

	int 	y;
	float 	x;

	for( int i = 0; i < n; i++ ){

		printf( "Enter the position by load \n" );
		scanf( " %d", &y );
		fflush( stdin );

		printf( "Enter the value for the position \n" );
		scanf( " %f", &x );
		fflush( stdin );
		
		array[y] = x;

	}

}

void print_r( float array[SIZE_ARRAY], int n ){

	for( int i = 0; i < n; i++ ){

		printf( "array[%d] -> %.2f \n", i, array[i] );

	}

}

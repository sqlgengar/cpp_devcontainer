#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void insert_asc( int[] );
void insert_desc( int[] );
void insert_pos( int[] );
void print_array( int[] );

int main(){

	int array[SIZE],
		value_option = 0;

	printf( "Program for manipule vectors, please enter a option: \n" );
	

	while( value_option != 4 ){
		
		printf( "1) Insert value ascendent \n" );
		printf( "2) Insert value descendent \n" );
		printf( "3) Insert value in particular position \n" );
		printf( "4) Exit program \n" );

		scanf( " %d", &value_option );
		fflush( stdin );

		switch( value_option ){

			case 1:
					insert_asc( array );
					break;
			case 2:
					insert_desc( array );
					break;
			case 3:
					insert_pos( array );
					break;
			case 4:
					exit( EXIT_SUCCESS );//end program by user option
					break;
			default:
					printf( "Value invalid for option \n" );
					printf( "Please enter a value between 1-4: \n" );
					break;
		}

	}

	printf( "Script done \n" );
	return 0;

}

void insert_asc( int array[SIZE] ){

	int temp;

	printf( "Enter new value for the array \n" );
	scanf( " %d", &temp );
	fflush( stdin );

	for( int i = SIZE; i >= 0; i-- ){

		array[i+1] = array[i];

	}

	array[0] = temp;

	print_array( array );

}

void insert_desc( int array[SIZE] ){

	int temp;

	printf( "Enter new value for the array \n" );
	scanf( " %d", &temp );
	fflush( stdin );

	for( int i = 0; i < SIZE; i++ ){

		array[i] = array[i+1];

	}

	array[SIZE-1] = temp;

	print_array( array );

}

void insert_pos( int array[SIZE] ){

	int temp_index,
		temp_value;

	printf( "Enter the position for a new value \n" );
	scanf( " %d", &temp_index );
	fflush( stdin );

	while( temp_index > SIZE || temp_index < 0 ){
		
		printf( "Value of index invalid \n" );
		printf( "Enter value between 0 and %d \n", SIZE );
		scanf( " %d", &temp_index );
		fflush( stdin );

	}

	printf( "Enter the new value \n" );
	scanf( " %d", &temp_value );
	fflush( stdin );

	for( int i = temp_index; i >= 0; i-- ){

		array[i+1] = array[i];

	}

	array[temp_index] = temp_value;

	print_array( array );

}

void print_array( int array[SIZE] ){

	for( int i = 0; i < SIZE; i++ ){

		printf( "array[%d] -> %d \n", i, array[i] );

	}

}

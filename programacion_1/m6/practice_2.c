#include <stdio.h>
#define SIZE_MAX 10

void charge_vec( int[], int );
int read_mark( int[] );
int turns( int, int[], int );
void reverse_order( int[], int );

int main(){

	int vec[SIZE_MAX],
		size_off = 0,
		index_find = 0,
		count_turns = 0,
		value_turn = 0;

	printf( "Enter a number of element to will charge: (<10) \n" );
	scanf( " %d", &size_off );

	charge_vec( vec, size_off );

	index_find = read_mark( vec );

	if( !index_find ){

		printf( "Value dont find in vec \n" );

	}
	else{

		printf( "Value find in index %d \n", index_find );

	}

	printf( "Enter a number to find turns into vec: \n" );
	scanf( " %d", &value_turn );

	count_turns = turns( value_turn, vec, SIZE_MAX );

	printf( "The number of turns for %d is %d \n", value_turn, count_turns );

	reverse_order( vec, SIZE_MAX );

	return 0;

}

void charge_vec( int vec[], int size_off ){

	int value;

	while( size_off > SIZE_MAX ){
		
		printf( "Invalid size of vector \n" );
		printf( "Enter a number of element to will charge: (<10) \n" );
		scanf( " %d", &size_off );		

	}

	for( int i = 0; i < size_off; i++ ){
		
		printf( "Enter a value for vec: \n" );
		scanf( " %d", &value );
		vec[i] = value;
	
	}

	for( int j = 0; j < size_off; j++ ){
		
		printf( "Index %d, value %d \n", j, vec[j] );

	}
		
}

int read_mark( int vec[] ){

	int temp_value = 0;

	printf( "Enter a value to lookup: \n" );
	scanf( " %d", &temp_value );

	for( int i = 0; i < SIZE_MAX; i++){
		
		if( vec[i] == temp_value ){

			return i;

		}

	}
	
	return 0;

}

int turns( int value_turn, int vec[], int size ){

	int temp_count = 0;

	for (int i = 0; i < size; i++){
		
		if( vec[i] == value_turn ){

			temp_count++;

		}

	}
	
	return temp_count;

}

void reverse_order( int vec[], int size ){

	for (int i = size; i >= 0; i--){
		
		printf( "%d , %d \n", i, vec[i] );

	}

}
#include <stdio.h>
#define SIZE_MAX 3

int charge_vec( int[] );
void add_elements( int[] );
void find_min( int[] );
float calc_avg( int[] );
void value_g_avg( int[], float );
void mult_l_element( int[], int );
void max_values( int[] );
void value_odd( int[] );
void value_not_odd( int[] );
void value_position( int[] );

int main(){

	int vec[SIZE_MAX],
		vec_odd[SIZE_MAX],
		last_value;
	float avg;

	last_value = charge_vec( vec );
	add_elements( vec );
	find_min( vec );
	avg = calc_avg( vec );
	value_g_avg( vec, avg );
	mult_l_element( vec, last_value );
	max_values( vec );
	value_odd( vec );
	value_not_odd( vec );
	value_position( vec );

	printf( "script done \n" );
	return 0;

}

int charge_vec( int vec[] ){

	int temp_value;

	for( int i = 0; i < SIZE_MAX; i++ ){

		printf( "Enter a number for vec: \n" );
		scanf( " %d", &temp_value );
		fflush( stdin );

		vec[i] = temp_value;

	}

	for( int j = 0; j < SIZE_MAX; j++ ){

		printf( "vec[%d] => %d \n", j, vec[j] );

	}

	return vec[SIZE_MAX-1];

}

void add_elements( int vec[] ){

	int temp_add = 0;

	for( int i = 0; i < SIZE_MAX; i++ ){
		
		temp_add += vec[i];

	}
	
	printf( "The add of elemets in vec is: %d \n", temp_add );

}

void find_min( int vec[] ){

	int min;

	min = vec[0];

	for( int i = 1; i < SIZE_MAX; i++ ){		
		
		if( vec[i] < min ){
			
			min = vec[i];

		}

	}

	printf( "The min value in vec is: %d \n", min );
	
}

float calc_avg( int vec[] ){

	int temp_add = 0;
	float temp_avg;

	for( int i = 0; i < SIZE_MAX; i++ ){
		
		temp_add += vec[i];

	}
	
	temp_avg = temp_add / ( SIZE_MAX - 1 ) * 1.0;

	printf( "The avg of elemets in vec is: %f \n", temp_avg );

	return temp_avg;

}

void value_g_avg( int vec[], float avg ){

	for( int i = 0; i < SIZE_MAX; i++ ){
		
		if( vec[i] > avg ){
			
			printf( "%d is grated of the average \n", vec[i] );

		}
		
	}
	
}

void mult_l_element( int vec[], int last_value ){

	for( int i = 0; i < SIZE_MAX; i++ ){
		
		if( ( vec[i] % last_value ) == 0 ){
			
			printf( "%d is multiple of %d \n", vec[i], last_value );

		}
		
	}

}

void max_values( int vec[] ){

	int max,
		count_max = 0;

	max = vec[0];

	for( int i = 1; i < SIZE_MAX; i++ ){
		
		if( vec[i] > max ){
			
			max = vec[i];

		}

	}

	for( int j = 0; j < SIZE_MAX; j++ ){
		
		if( vec[j] == max ){
			
			printf( "The max value %d in %d index \n", max, j );
			count_max++;

		}

	}
	
	printf( "The count of max is: %d \n", count_max );

}

void value_odd( int vec[] ){

	for( int i = 0; i < SIZE_MAX; i++ ){
	
		if( ( vec[i] % 2 ) != 0 ){

			printf( "%d is odd \n", vec[i] );

		}
		
	}

}

void value_not_odd( int vec[] ){

	for( int i = 0; i < SIZE_MAX; i++ ){

		if( ( vec[i] % 2 ) == 0 ){

			printf( "%d is not odd \n", vec[i] );

		}

	}

}

void value_position( int vec[] ){

	for( int i = 0; i < SIZE_MAX; i++ ){

		if( ( i % 2 ) == 0 ){

			printf( "%d in %d positon \n", vec[i], i );

		}

	}

}


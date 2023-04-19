#include <stdio.h>
#define SIZE_ARRAY 2

typedef struct{

	int id;
	float price;

} Products;

void calc_discount( Products[SIZE_ARRAY] );
void max_price( Products[SIZE_ARRAY] );

int main(){

	Products product[SIZE_ARRAY];

	calc_discount( product );
	max_price( product );

	printf( "script done \n" );

	return 0;

}

void calc_discount( Products product[SIZE_ARRAY] ){

	float amount_discount = 0;

	for( int i = 0; i < SIZE_ARRAY; i++ ){

		printf( "Enter an id for the product \n" );
		scanf( " %d", &product[i].id );
		fflush( stdin );

		printf( "Enter an price for the product \n" );
		scanf( " %f", &product[i].price );
		fflush( stdin );

		amount_discount 	= product[i].price * 0.2;
		product[i].price 	-= amount_discount;

		printf( "Price of product with discount is: %.2f \n", product[i].price );

	}

}

void max_price( Products product[SIZE_ARRAY] ){

	int temp_max_id = product[0].id;

	for( int i = 1; i < SIZE_ARRAY; i++ ){

		if( product[i].price > product[i-1].price ){

			temp_max_id = product[i].id;

		}

	}

	printf( "The product with max price is id %d \n", temp_max_id );

}

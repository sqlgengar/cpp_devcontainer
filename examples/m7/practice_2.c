#include <stdio.h>

typedef struct{

	int id;
	float price;

} Products;

void calc_discount( Products * );

int main(){

	Products generic;

	calc_discount( &generic );

	printf( "script done \n" );

	return 0;

}

void calc_discount( Products *generic ){

	float amount_discount = 0;

	printf( "Enter an id for the product \n" );
	scanf( " %d", &generic->id );
	fflush( stdin );

	printf( "Enter an price for the product \n" );
	scanf( " %f", &generic->price );
	fflush( stdin );

	amount_discount = generic->price * 0.2 ;

	printf( "Price of product with discount is: %.2f \n", generic->price - amount_discount );

}

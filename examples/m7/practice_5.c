#include <stdio.h>

typedef struct{

	int id;
	int colour;
	float price;

} Fruits;

void init_struc( Fruits * );

int main(){

	Fruits fruit;

	init_struc( &fruit );

	printf( "Fruit id %d, colour %d, price %.2f \n", fruit.id, fruit.colour, fruit.price );

	printf( "script done \n" );

	return 0;

}

void init_struc( Fruits *fruit ){


	printf( "Enter an id for the fruit \n" );
	scanf( " %d", &fruit->id );
	fflush( stdin );

	printf( "Enter a colour for the fruit \n" );
	printf( "ORANJE -> 1 \n" );
	printf( "RED    -> 2 \n" );
	printf( "YELLOW -> 3 \n" );
	scanf( " %d", &fruit->colour );
	fflush( stdin );

	printf( "Enter a price for the fruit \n" );
	scanf( " %f", &fruit->price );
	fflush( stdin );

}

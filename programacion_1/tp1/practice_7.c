#include <stdio.h>

int main (){

	float input_1,
	      input_2;

	printf( "enter the first number \n"  );

	scanf( "%f", &input_1 );
	fflush( stdin );

	printf( "enter the second number \n" );

	scanf( "%f", &input_2 );
	fflush( stdin );

	printf( "the addition between the numbers is: 		%.2f \n", input_1 + input_2 );
	printf( "the subtraction between the numbers is: 	%.2f \n", input_1 - input_2 );
	printf( "the multiplication between the numbers is: 	%.2f \n", input_1 * input_2 );
	printf( "the divition between the numbers is: 		%.2f \n", input_1 / input_2 );

	return 0;

}

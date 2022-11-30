#include <stdio.h>

int main (){

	short int number;

	printf( "enter a interger number: \n" );

	scanf( "%hi", &number );
	fflush( stdin );

	printf( "the firts number is %hi, the second number is %hi, the third number is %hi \n",
		number / 100, (number % 100) / 10, number % 10 );

	return 0;

}

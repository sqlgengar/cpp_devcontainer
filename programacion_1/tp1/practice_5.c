#include <stdio.h>

int main (){

	int temp,
	    value_1 = 1,
	    value_2 = 2;

	printf( "value_1 original is = %i\n", value_1 );
	printf( "value_2 original is = %i\n", value_2 );

	temp 	= value_1;
	value_1 = value_2;
	value_2 = temp;

	printf( "value_1 switch is = %i\n", value_1 );
	printf( "value_2 switch is = %i\n", value_2 );

	return 0;
}

#include <stdio.h>

int main (){

	int days;

	printf( "enter one number equal to days of the mounth: \n" );

	scanf( "%i", &days );
	fflush( stdin );

	printf( "the amount in seconds is: %.2lf \n", (double) 86400.0 * days );

	return 0;

}

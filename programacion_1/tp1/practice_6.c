#include <stdio.h>

int main (){

	double value_km;

	printf( "enter a value in km: \n" );

	scanf( "%lf", &value_km );

	printf( "the value in m is: %.2lf\n", (double) value_km * 1000.0 );

	return 0;

}

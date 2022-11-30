#include <stdio.h>

int main (){

	double value_seconds;

	printf( "enter one value in seconds: \n" );

	scanf( "%lf", &value_seconds );
	fflush( stdin );

	printf( "the vaule in days is:    %0.4lf \n", (double) value_seconds / 86400.0 	);
	printf( "the vaule in hours is:   %0.4lf \n", (double) value_seconds / 3600.0  	);
	printf( "the vaule in minutes is: %0.4lf \n", (double) value_seconds / 60.0    	);
	printf( "the vaule in seconds is: %0.4lf \n", (double) value_seconds		);

	return 0;

}

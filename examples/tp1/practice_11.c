#include <stdio.h>

int main (){

	float 	hour_man,
	    	service;

	printf( "enter the hours working: \n" );

	scanf( "%f", &hour_man );
	fflush( stdin );

	printf( "enter the years of service: \n" );

	scanf( "%f", &service );
	fflush( stdin );

	printf( "the net salary is: %.2f  \n",
	      ( hour_man * 4500.0 ) + ( service * 90 )  );

	return 0;

}

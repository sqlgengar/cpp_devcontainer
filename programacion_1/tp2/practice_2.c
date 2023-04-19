#include <stdio.h>

int main(){

	int number,
	    mounth,
	    day;

	printf( "enter a number: \n" );

	scanf( "%i", &number );
	fflush( stdin );

	if( ( number % 5 ) != 0 ){

		printf( "%i is not multiple of 5 \n", number );

	}

	printf( "enter a number of day: \n" );

	scanf( "%i", &day );
	fflush( stdin );

	printf( "enter a number of mounth: \n" );

	scanf( "%i", &mounth );
	fflush( stdin );

	if( mounth == 1 || mounth == 2 || mounth == 3 ){

		printf( "correspond to first trimester \n" );

	}

	return 0;

}

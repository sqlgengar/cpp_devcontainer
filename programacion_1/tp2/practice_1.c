#include <stdio.h>

int main(){

	int x = 2,
	    y = 6,
	    z = 4;

	if( x > y || x < z ){

		printf( "true \n" );

	}
	else{
		
		printf( "false \n" );

	}


	if( x < y && x == y ){

                printf( "true \n" );

        }
        else{

                printf( "false \n" );

        }

	if( ( x < y && x != y ) || !( x == y ) ){

                printf( "true \n" );

        }
        else{

                printf( "false \n" );

        }

	return 0;

}

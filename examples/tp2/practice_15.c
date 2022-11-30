#include <stdio.h>

int main(){

	char c_input;

	printf( "enter a character \n" );

	scanf(" %c", &c_input);
	fflush(stdin);

	if( c_input >= 'A' &&  c_input <= 'U' ){

		c_input = c_input + 32;

	}

	switch( c_input ){

		case 'a':
				printf( "the character ingress is a vocal \n" );
				break;
		case 'e':
				printf( "the character ingress is a vocal \n" );
				break;
		case 'i':
				printf( "the character ingress is a vocal \n" );
				break;
		case 'o':
				printf( "the character ingress is a vocal \n" );
				break;
		case 'u':
				printf( "the character ingress is a vocal \n" );
				break;
		default:
				printf( "the character ingress is not a vocal \n" );
				break;

	}

	return 0;

}

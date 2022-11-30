#include <stdio.h>
#include <stdlib.h>

int main(){

	int first_number,
	    second_number;

	char operator;

	printf( "enter a number: \n" );

	scanf(" %i", &first_number);
	fflush(stdin);

	printf( "enter another number: \n" );
	
	scanf(" %i", &second_number);
	fflush(stdin);

	printf( "enter a letter of operator: (S\\R\\M\\D) \n" );

	scanf(" %c", &operator);
	fflush(stdin);

	if( operator >= 'd' && operator <= 's' ){

		operator = operator - 32;

	}

	switch(operator){

		case 'S':
				printf( "the add between both numbers is: %.2f \n", (float) first_number + second_number * 1.0 );
				break;
		case 'R':
				printf( "the sub between both numbers is: %.2f \n", (float) first_number - second_number * 1.0 );
				break;
		case 'M':
				printf( "the multi between both numbers is: %.2f \n", (float) first_number * second_number * 1.0 );
				break;
		case 'D':
				if( second_number == 0 ){
					
					printf( "ivalid operation div by cero \n" );
					exit(0);

				}

				printf( "the div between both number is: %.2f \n", (float) first_number / second_number * 1.0 );
				break;
		default:
				printf( "invalid operator selected \n" );
				break;

	}

	return 0;

}

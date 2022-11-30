#include <stdio.h>
#include <math.h>

int main(){

	int  x;
	float num;

	printf( "(1) EL TRIPLE \n" );
	printf( "(2) EL CUADRUPLE \n" );
	printf( "(3) LOGARITMO NATURAL \n" );
	printf( "(4) LOGARITMO DECIMAL \n" );
	printf( "Escribe el numero de la opcion que desees: \n" );

	scanf(" %i", &x);
	fflush(stdin);

	printf( "enter the number to evalue: \n" );

	scanf(" %f", &num);
	fflush(stdin);

	switch(x){

		case 1:
				printf( "the triple of number is: %.2f \n", 		num * 3  );
				break;
		case 2:
				printf( "the quadruple of number is: %.2f \n", 		num * 4  );
				break;
		case 3:
				printf( "the natural logarithm of number is: %.2f \n", 	log(x)   );
				break;
		case 4:
				printf( "the common logarithm of number is: %.2f \n", 	log10(x) );
				break;
		default:
				printf( "invalid opcion \n" );
				break;
	}

	return 0;

}

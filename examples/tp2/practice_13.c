#include <stdio.h>
#include <stdlib.h>

int main(){

	int  side_1,
	     side_2,
	     side_3,
	     sum_12,
	     sum_23,
	     sum_13;

	printf( "entre the firts side: \n"  );

	scanf(" %i", &side_1);
	fflush(stdin);

	printf( "enter the second side: \n" );

	scanf(" %i", &side_2);
	fflush(stdin);

	printf( "enter the third side: \n"  );

        scanf(" %i", &side_3);
        fflush(stdin);

	sum_12 = side_1 + side_2;
	sum_23 = side_2 + side_3;
	sum_13 = side_1 + side_3;

	if( sum_12 > side_3 && sum_23 > side_1 && sum_13 > side_2 ){

		if( side_1 == side_2 && side_2 == side_3 ){

			printf( "the triangle is equilater \n" );
			exit(0);
		}
		else if ( side_1 != side_2 && side_2 != side_3 && side_1 != side_3 ){

			printf( "the triagle is escalen \n" );
			exit(0);
		}

		printf( "the triangle is isoceles \n" );
		exit(0);

	}

	printf( "invalide lengh side for triangle \n" );

	return 0;

}

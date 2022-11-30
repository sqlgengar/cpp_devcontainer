#include <stdio.h>
#include <stdlib.h>

int main(){

	char name_alumn[20];
	int  note;

	printf( "entre the name of alumn: \n" );

	scanf(" %s", name_alumn);
	fflush(stdin);

	printf( "enter the note of alumn: \n" );

	scanf(" %i", &note);
	fflush(stdin);

	switch( note ){

		case 10:
				printf( "%s obtuvo un sobresaliente \n"	, name_alumn );
				break;

		case 9:
                                printf( "%s obtuvo un distinguido \n"	, name_alumn );
                                break;

		case 8:
                                printf( "%s obtuvo un distinguido \n"	, name_alumn );
                                break;
		case 7:
                                printf( "%s obtuvo un bueno \n"		, name_alumn );
                                break;
		case 6:
                                printf( "%s obtuvo un bueno \n"		, name_alumn );
                                break;
		case 5:
                                printf( "%s obtuvo un aprobado \n"	, name_alumn );
                                break;
		case 4:
                                printf( "%s obtuvo un aprobado \n"	, name_alumn );
                                break;
		case 3:
                                printf( "%s obtuvo un reprobado \n"	, name_alumn );
                                break;
		case 2:
                                printf( "%s obtuvo un reprobado \n"	, name_alumn );
                                break;
		case 1:
                                printf( "%s obtuvo un reprobado \n"	, name_alumn );
                                break;
		default:
				printf( "nota no valida \n" );
				break;
		}

	return 0;

}

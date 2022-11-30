#include <stdio.h>

int main(){

	char name[20];
	int  day,
	     mounth,
	     year;

	printf( "entre the name: \n" );

	scanf(" %s", name);
	fflush(stdin);

	printf( "enter the day of birth: \n" );

	scanf(" %i", &day);
	fflush(stdin);

	printf( "enter the mounth of birth: \n" );

        scanf(" %i", &mounth);
        fflush(stdin);

	printf( "enter the year of birth: \n" );

        scanf(" %i", &year);
        fflush(stdin);

	switch( mounth ){

		case 12:
				printf( "%s nacio el %i de diciembre de %i \n", 	name, day, year );
				break;
		case 11:
                                printf( "%s nacio el %i de noviembre de %i \n", 	name, day, year );
                                break;
		case 10:
                                printf( "%s nacio el %i de octubre de %i \n", 		name, day, year );
                                break;
		case 9:
                                printf( "%s nacio el %i de septiembre de %i \n", 	name, day, year );
                                break;
		case 8:
                                printf( "%s nacio el %i de agosto de %i \n", 		name, day, year );
                                break;
		case 7:
                                printf( "%s nacio el %i de julio de %i \n", 		name, day, year );
                                break;
		case 6:
                                printf( "%s nacio el %i de junio de %i \n", 		name, day, year );
                                break;
		case 5:
                                printf( "%s nacio el %i de mayo de %i \n", 		name, day, year );
                                break;
		case 4:
                                printf( "%s nacio el %i de abril de %i \n", 		name, day, year );
                                break;
		case 3:
                                printf( "%s nacio el %i de marzo de %i \n", 		name, day, year );
                                break;
		case 2:
				printf( "%s nacio el %i de febrero de %i \n", 		name, day, year );
                                break;
		case 1:
				printf( "%s nacio el %i de enero de %i \n", 		name, day, year );
                                break;
		default:
				printf( "invalid mounth \n" );
				break;
		}

	return 0;

}

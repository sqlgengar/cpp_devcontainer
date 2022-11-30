#include <stdio.h>
#define DAYS 30				//cantidad dde dias que el progrmaa maneja, sin vlaidadcion de cantidad de dias por mes
#define MOUNTHS 12			//cantidad de meses que el programa maneja
#define YEARS 5				//cantidad de a;os que el progrmaa puede manejar
#define MOUNTH_WILD_CHILD 4	//valor para calcular el promedio de sensacion terminal, mes-1  

/*
	A lo largo del script se hace la correccion de valor-1 para trabajar internamente,
	valor+1 para mostrar al usuario
	para los dias, meses y a;ios
	esto porque si bien el dia 0 no existe, el index 0 corresponde al dia 1
*/

enum date{ YEAR, MOUNTH, DAY };
enum temps{ MAX = 200, MIN = -273, WILD_CHILD = 300 };

typedef struct{
	
	short int temp_max;
	short int temp_min;
	short int wild_chill;
	short int status;

} Data;

void load_data( Data[YEARS][MOUNTHS][DAYS], short int, short int, short int );
//short int get_min_temp( Data[YEARS][MOUNTHS][DAYS], short int );
//short int get_avg_wild_chill( Data[YEARS][MOUNTHS][DAYS], short int, short int );
//void show_data( Data[YEARS][MOUNTHS][DAYS] );
//void show_temp_min_years( Data[YEARS][MOUNTHS][DAYS], short int );
//void show_avg_wild_chill_may( Data[YEARS][MOUNTHS][DAYS], short int );

short int valide_value( short int, int );

int main(){

	Data temps[YEARS][MOUNTHS][DAYS];
	short int 	aux_year,
				aux_mounth,
				aux_day,
				flag = 0
	;


//init array data
	for( short int i = 0; i < YEARS; i++ ){

		for( short int j = 0; j < MOUNTHS; j++){

			for( short int k = 0; k < DAYS; k++){
				
				temps[i][j][k].temp_max 	= 200;
				temps[i][j][k].temp_min 	= -273;
				temps[i][j][k].wild_chill 	= 300;
				temps[i][j][k].status 		= 0;

			}			
			
		}		

	}

	do{
	
		printf( "Ingresar un a;o para cargar \n" );
		scanf( " %hd", &aux_year );
		fflush( stdin );

		aux_year 	= valide_value( aux_year, YEAR );

		printf( "Ingresar un mes para cargar \n" );
		scanf( " %hd", &aux_mounth );
		fflush( stdin );

		aux_mounth 	= valide_value( aux_mounth, MOUNTH );

		printf( "Ingresar un dia para cargar \n" );
		scanf( " %hd", &aux_day );
		fflush( stdin );

		aux_day 	= valide_value( aux_day, DAY );

		load_data( temps, aux_year, aux_mounth, aux_day );

		printf( "Si desea no cargar mas datos ingrese 0 \n" );
		printf( "en caso contrario ingrese cualquier numero \n" );

		scanf( " %hd", &flag );
		fflush( stdin );

	} while ( flag );

	printf( "\n SCRIPT DONE \n" );
	return 0;

}

short int valide_value( short int value, int type ){

	switch( type ){
	
		case YEAR:
					while(value <= 0 || value > YEARS){

					printf( "Valor de a;o incorrecto \n" );
					printf( "Ingrese un valor entre 1-%d \n", YEARS );
					scanf( " %hd", &value );
					fflush( stdin );

					}
					return value - 1;		
		break;

		case MOUNTH:
					while(value <= 0 || value > MOUNTHS){

					printf( "Valor de mes incorrecto \n" );
					printf( "Ingrese un valor entre 1-%d \n", MOUNTHS );
					scanf( " %hd", &value );
					fflush( stdin );

					}
					return value - 1;		
		break;
	
		case DAY:
					while(value <= 0 || value > DAYS){

					printf( "Valor de dia incorrecto \n" );
					printf( "Ingrese un valor entre 1-%d \n", DAYS );
					scanf( " %hd", &value );
					fflush( stdin );

					}
					return value - 1;		
		break;
		
		case WILD_CHILD:
							while(value <= MIN || value > WILD_CHILD){

							printf( "Valor para la sensacion termica es incorrecto \n" );
							printf( "Ingrese un valor entre %d y %d \n", MIN, WILD_CHILD );
							scanf( " %hd", &value );
							fflush( stdin );

							}
							return value;		
		break;	
		
		default:
							while(value <= MIN || value > MAX){

							printf( "Valor para la tempraturra es incorrecto \n" );
							printf( "Ingrese un valor entre %d y %d \n", MIN, MAX );
							scanf( " %hd", &value );
							fflush( stdin );

							}
							return value;

	}

}

void load_data( Data values[YEARS][MOUNTHS][DAYS], short int year, short int mounth, short int day){

	short int 	aux_temp_max,
				aux_temp_min,
				aux_wild_chill
	;

	if( values[year][mounth][day].status == 1 ){

		printf( "Esta fecha %hd/%hd/%hd ya tiene un valor guardado, no se puede volver a escribir \n", day, mounth, year );
		return;

	}

	printf( "Ingresar temperatura maxima para la fecha %hd/%hd/%hd: \n", day + 1, mounth + 1, year + 1 );
	scanf( " %hd", &aux_temp_max );
	fflush( stdin );

	values[year][mounth][day].temp_max 		= valide_value( aux_temp_max, MAX );

	printf( "Ingresar temperatura minima para la fecha %hd/%hd/%hd: \n", day + 1, mounth + 1, year + 1 );
	scanf( " %hd", &aux_temp_min );
	fflush( stdin );

	values[year][mounth][day].temp_min 		= valide_value( aux_temp_min, MIN );

	printf( "Ingresar la sensacion termica para la fecha %hd/%hd/%hd: \n", day + 1, mounth + 1, year + 1 );
	scanf( " %hd", &aux_wild_chill );
	fflush( stdin );

	values[year][mounth][day].wild_chill 	= valide_value( aux_wild_chill, WILD_CHILD );

	values[year][mounth][day].status 		= 1;

}

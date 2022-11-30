#include<stdio.h>
#define DIM 50

/*
	No esta exacto el calculo de vida mas promedora
	Deberia devolver un float
	Pero en C la funcion solo puede devolver un tipo de dato
	El tipo de dato que devuelve la funcion tendria que ser algo como un UNION
*/

enum types{ VIDA, PROFUNDIDAD, PROMETEDORA };

typedef struct{

	int densidad_flora;
	int densidad_fauna;
	int profundidad;
	int velocidad_corriente;
	int status;

} Data;

int load_data( Data[DIM][DIM], int, int );
void input_cord( Data[DIM][DIM] );
int calc_max( Data[DIM][DIM], int );
void show_results( int, int, int );

int main(){

	Data mn2[DIM][DIM];
	int max_life = 0,
		max_profundidad = 0,
		max_prometedora = 0;

	for( int i = 0; i < DIM; i++){
		
		for( int j = 0; j < DIM; j++){
			
			mn2[i][j].status = 0;

		}
		
	}

	input_cord( mn2 );

	max_life = calc_max( mn2, VIDA );
	max_profundidad = calc_max( mn2, PROFUNDIDAD );
	max_prometedora = calc_max( mn2, PROMETEDORA );

	show_results( max_life, max_profundidad, max_prometedora );

	printf( "\n SCRIPT DONE \n" );
	return 0;

}

void input_cord( Data current_mn2[DIM][DIM] ){

	int cord_x = 0,
		cord_y = 0;

	do{

		printf( "Ingrese la coordenada en X del mn2 a cargar: \n" );
		scanf( " %d", &cord_x );
		fflush( stdin );

		printf( "Ingrese la coordenada en Y del mn2 a cargar: \n" );
		scanf( " %d", &cord_y );
		fflush( stdin );

	} while( load_data( current_mn2, cord_x, cord_y ) );

}

int load_data( Data mn2[DIM][DIM], int x, int y ){

	int flag = 0;

	printf( "Ingese el valor de densidad de flora: (0-9) \n" );
	scanf( " %d", &mn2[x][y].densidad_flora );
	fflush( stdin );

	printf( "Ingese el valor de densidad de fauna: (0-9) \n" );
	scanf( " %d", &mn2[x][y].densidad_fauna );
	fflush( stdin );

	printf( "Ingese el valor de profundidad: (0-9) \n" );
	scanf( " %d", &mn2[x][y].profundidad );
	fflush( stdin );

	printf( "Ingese el valor de velocidad de corriente: (0-9) \n" );
	scanf( " %d", &mn2[x][y].velocidad_corriente );
	fflush( stdin );

	mn2[x][y].status = 1;

	printf( "Para seguir cargando valores en el mapa \n" );
	printf( "ingrese un numero distinto de 0 \n" );
	scanf( " %d", &flag );

	return flag;

}

int calc_max( Data mn2[DIM][DIM], int type ){

	int temp_max_value = 0,
		temp_value = 0;

	switch( type ){
	
		case VIDA:
					for( int i = 0; i < DIM; i++ ){

						for( int j = 0; j < DIM; j++){
			
							if( mn2[i][j].status ){

								temp_value = mn2[i][j].densidad_fauna + mn2[i][j].densidad_flora;

								if( temp_max_value < temp_value ){

									temp_max_value = temp_value;

								}

							}

						}

					}	
	break;
	case PROFUNDIDAD:
					for( int i = 0; i < DIM; i++ ){

						for( int j = 0; j < DIM; j++){
			
							if( mn2[i][j].status ){

								temp_value = mn2[i][j].profundidad;

								if( temp_max_value < temp_value ){

									temp_max_value = temp_value;

								}

							}

						}

					}	
	break;
	case PROMETEDORA:
					for( int i = 0; i < DIM; i++ ){

						for( int j = 0; j < DIM; j++){
			
							if( mn2[i][j].status ){

								temp_value = ( mn2[i][j].densidad_fauna + mn2[i][j].densidad_flora ) / mn2[i][j].profundidad;

								if( temp_max_value < temp_value ){

								temp_max_value = temp_value;

								}

							}

						}

					}	
	break;
	
	}

	return temp_max_value;

}

void show_results( int max_life, int max_profundidad, int max_prometedora ){

	printf( "El mayor valor de vida es: %d \n", max_life );
	printf( "El mayor valor de profundidad es: %d \n", max_profundidad );
	printf( "El mayor valor de prometedora es: %d \n", max_prometedora );

}
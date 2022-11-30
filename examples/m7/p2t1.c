#include <stdio.h>
#define AMOUNT_YEARS 		4  //amount of years that program can load
#define AMOUNT_MOUNTHS 		12 //amount of mounths that program can load
#define AMOUNT_DAYS 		30 //amount of days that program can load, without logic of validate
#define INDEX_SEPTEMBER 	9

//TODO: hacer funcion de validacion reutilizable con swicht

typedef struct{

	int presents;
	int missings;

} Days;

void load_days( Days [AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS] );
void avg_presents( Days [AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS] );
void max_presents( Days [AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS] );
void presents_sep_years( Days [AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS] );

int main(){

	Days date[AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS];
	
	load_days( date );
	avg_presents( date );
	max_presents( date );
	presents_sep_years( date );

	printf( "\n script done \n" );

	return 0;

}

void load_days( Days new_day[AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS] ){

	int index_day;

	for( int y = 0; y < AMOUNT_YEARS; y++ ){

		printf( "year %d of %d \n", y + 1, AMOUNT_YEARS );
		
		for( int m = 0; m < AMOUNT_MOUNTHS; m++ ){

			printf( "-> mounth %d of %d \n", m + 1, AMOUNT_MOUNTHS );

			for( int d = 0; d < AMOUNT_DAYS; d++ ){

				int flag = 1,
					temp_index_day = -1;

				printf( "--> day %d of %d \n", d + 1, AMOUNT_DAYS );

				printf( "Enter 0 by not load any more day \n" );
				scanf( " %d", &flag );
				fflush( stdin );

				if( !flag ) return;

				while( temp_index_day < 0 || temp_index_day > AMOUNT_DAYS ){

					printf( "Enter the day of the mounth \n" );
					scanf( " %d", &temp_index_day );
					fflush( stdin );

					if( temp_index_day < 0 || temp_index_day > AMOUNT_DAYS ){

						printf( "Value for day invalid \n" );
						printf( "Enter a number between 1 and %d \n", AMOUNT_DAYS );

					}

				}

				index_day = temp_index_day - 1;

				printf( "Enter the amount of presents \n" );
				scanf( " %d", &new_day[y][m][index_day].presents );
				fflush( stdin );

				printf( "Enter the amount of missings \n" );
				scanf( " %d", &new_day[y][d][index_day].missings );
				fflush( stdin );

			}

		}

	}

}

void avg_presents( Days date_user[AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS] ){

	int 	index_year,
	    	index_mounth,
	    	sum_presents = 0,
			temp_index_year = -1,
			temp_index_mounth = -1;
	float 	avg;

	while( temp_index_year < 0 || temp_index_year > AMOUNT_YEARS ){

		printf( "Enter a year for calc the average \n" );
		scanf( " %d", &temp_index_year );
		fflush( stdin );

		if( temp_index_year < 0 || temp_index_year > AMOUNT_YEARS ){

			printf( "Value for year invalid \n" );
			printf( "Enter a number between 1 and %d \n", AMOUNT_YEARS );

		}

	}

	index_year = temp_index_year - 1;

	while( temp_index_mounth < 0 || temp_index_mounth > AMOUNT_MOUNTHS ){

		printf( "Enter a mounth for calc the average \n" );
		scanf( " %d", &temp_index_mounth );
		fflush( stdin );

		if( temp_index_mounth < 0 || temp_index_mounth > AMOUNT_MOUNTHS ){

			printf( "Value for mounth invalid \n" );
			printf( "Enter a number between 1 and %d \n", AMOUNT_MOUNTHS );

		}

	}

	index_mounth = temp_index_mounth -1;

	for( int d = 0; d < AMOUNT_DAYS; d++ ){

		sum_presents += date_user[index_year][index_mounth][d].presents;

	}

	avg = sum_presents / ( AMOUNT_DAYS * 1.0 ); //correction by float divition

	printf( "The average value for year %d, mounth %d, is %.2f \n", index_year + 1, index_mounth + 1, avg );

}

void max_presents( Days date_user[AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS] ){

	int temp_max_day,
		temp_index_year = -1,
		max_day,
		max_mounth,
		amount_presents = 0,
	    index_year;
	
	while( temp_index_year < 0 || temp_index_year > AMOUNT_YEARS ){

		printf( "Enter de year for look up the max presents \n" );
		scanf( " %d", &temp_index_year );
		fflush( stdin );

		if( temp_index_year < 0 || temp_index_year > AMOUNT_YEARS ){

			printf( "Value for year invalid \n" );
			printf( "Enter a number between 1 and %d \n", AMOUNT_YEARS );

		}

	}

	index_year = temp_index_year - 1;

	for( int m = 0; m < AMOUNT_MOUNTHS; m++ ){

		for( int d = 0; d < AMOUNT_DAYS; d++ ){

			if( date_user[index_year][m][d].presents > amount_presents ){

				amount_presents = date_user[index_year][m][d].presents;
				temp_max_day = d;
				max_mounth = m;

			}

		}

	}

	max_day = 30 * max_mounth + temp_max_day + 1;

	printf( "The max day for presenteeism is %d \n", max_day );

}

void presents_sep_years( Days date_user[AMOUNT_YEARS][AMOUNT_MOUNTHS][AMOUNT_DAYS] ){

	int 	sum_presents = 0,
			temp_max_mounth,
			temp_max_day,
			max_day;
	float 	avg;

	for( int y = 0; y < AMOUNT_YEARS; y++ ){

		for( int d = 0; d < AMOUNT_DAYS; d++ ){

			sum_presents += date_user[y][INDEX_SEPTEMBER - 1][d].presents;

		}

		avg = sum_presents / ( AMOUNT_DAYS * 1.0 ); //correction by float divition

		printf( "The average value for year %d, mounth september, is %.2f \n", y + 1, avg );

	}
	
	for( int y = 0; y < AMOUNT_YEARS; y++ ){

		int amount_presents = 0;

		for( int m = 0; m < AMOUNT_MOUNTHS; m++ ){

			for( int d = 0; d < AMOUNT_DAYS; d++ ){

				if( date_user[y][m][d].presents > amount_presents ){

					amount_presents = date_user[y][m][d].presents;
					temp_max_day = d;
					temp_max_mounth = m;

				}

			}

		}

	max_day = 30 * temp_max_mounth + temp_max_day + 1;

	printf( "For year %d, the day with max presents is %d \n", y + 1, max_day );

	}

}
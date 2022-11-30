#include <stdio.h>
#include <stdlib.h>

enum bool{ 

	FALSE, 
	TRUE 

};

typedef struct{
	
	int day;
	int mounth;
	int year;

} Date;

void create_date( Date * );
void get_day( int );
void get_mounth( int );
void get_year( int );
void is_leap_year( int );

int main(){

	Date current_date;

	create_date( &current_date );

	get_day( current_date.day );
	get_mounth( current_date.mounth );
	get_year( current_date.year );

	is_leap_year( current_date.year );

	printf( "script done \n" );

	return 0;

}

void create_date( Date *insert_date ){

	printf( "Enter a day for the date: \n" );
	scanf( " %d", &insert_date->day );
	fflush( stdin );

	printf( "Enter a mounth for the date: \n" );
	scanf( " %d", &insert_date->mounth );
	fflush( stdin );

	printf( "Enter a year for the date: \n" );
	scanf( " %d", &insert_date->year );
	fflush( stdin );

}

void get_day( int date_day ){

	printf( "The day for the date is: %d \n", date_day );

}

void get_mounth( int date_mounth ){

	printf( "The mounth for the date is: %d \n", date_mounth );

}

void get_year( int date_year ){

	printf( "The year for the date is: %d \n", date_year );

}

void is_leap_year( int date_year ){

	if( ( date_year % 4 != 0 || date_year % 100 == 0 ) && date_year % 400 != 0 ){

		printf( "The year %d is not lead year \n", date_year );
		exit( EXIT_SUCCESS );

	}

	printf( "The year %d is lead year \n", date_year );

}

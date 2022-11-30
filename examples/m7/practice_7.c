#include <stdio.h>
#define MAX_GRADES 2 //max value for amount grades by student
#define MAX_FILES  2 //mas value for amount of input studens

typedef enum{ 

	DESAPROBADO = 0,
	APROBADO_PRACIAL = 1, 
	APROBADO = 3 

} Status;

typedef struct{

	int file;
	int all_grades[MAX_GRADES];
	Status final_grade;
	float average;

} Students;

Students load_student();
float calc_avg( Students );
float max_avg( Students[] );
void print_results( Students[], float );

int main(){

	Students all_students[MAX_FILES];
	float max_average;

	for( int i = 0; i < MAX_FILES; i++){

		all_students[i] = load_student();

	}

	for( int j = 0; j < MAX_FILES; j++ ){

		all_students[j].average = calc_avg( all_students[j] );

	}

	max_average = max_avg( all_students );

	print_results( all_students, max_average );

	printf( "script done \n" );
	
	return 0;

}

Students load_student(){

	Students new_student;

	printf( "Enter a file number for the student: \n" );
	scanf( " %d", &new_student.file );
	fflush( stdin );


	for( int i = 0; i < MAX_GRADES; i++ ){

		printf( "Enter the grade |%d-%d| \n", i+1, MAX_GRADES );
		scanf( " %d", &new_student.all_grades[i] );
		fflush( stdin );

	}

	printf( "Enter status of student \n" );
	printf( "DESAPROBADO \t -> 0 \n" );
	printf( "APROBADO PARCIAL -> 1 \n" );
	printf( "APROBADO \t -> 2 \n" );

	scanf( " %d", &new_student.final_grade );
	fflush( stdin );
		
	return new_student;

}

float calc_avg( Students calc_student ){

	int sum_avg = 0;
	float avg_grades;

	for( int i = 0; i < MAX_GRADES; i++ ){

		sum_avg += calc_student.all_grades[i];

	}

	avg_grades = sum_avg / ( MAX_GRADES * 1.0 );

	return avg_grades;

}

float max_avg( Students student[MAX_FILES] ){

	float m_avg = 0;

	for( int i = 0; i < MAX_FILES; i++ ){

		if( m_avg < student[i].average ){

			m_avg = student[i].average;

		}

	}

	return m_avg;

}

void print_results( Students files[MAX_FILES], float max_average ){

	for( int i = 0; i < MAX_FILES; i++ ){

		printf( "\n File %d \n", files[i].file );
		
		for( int j = 0; j < MAX_GRADES; j++ ){

			printf( "-> grade[%d]: %d \n", j, files[i].all_grades[j] );

		}

		switch( files[i].final_grade ){

			case DESAPROBADO:
					printf( "Status Desaprobado \n" );
					break;

			case APROBADO_PRACIAL:
					printf( "Status Aprobado parcial \n" );
					break;

			case APROBADO:
					printf( "status Aprovado \n" );
					break;

		}

		printf( "Average: %.2f \n", files[i].average );

	}

	printf( "Max average: %.2f \n", max_average );

}
	

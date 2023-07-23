#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUMBER_NOTES 2
#define MAX_CHARS_FILE 5000
#define MAX_CHARS_VAR 256

typedef struct
{
	int number_file;
	int notes[MAX_NUMBER_NOTES];
	float average_notes;
} Alumns;

void execute();
bool input_file_number( Alumns**, int* );
void input_notes( Alumns**, int );
void calc_avg_notes( Alumns**, int );
void write_file_text( Alumns*, int, char* );
char* formatter( Alumns*, int );
void read_file_text( char* );

int main()
{
	execute();

	return(0);
}

void execute()
{
	bool is_break = true;
	char *path_file_text = "/workspaces/cpp_devcontainer/programacion_1/m8/_files/data.txt";
	int array_count = 0;
	Alumns* alumns = (Alumns*)calloc( 1, sizeof(Alumns) );

	do
	{
		is_break = input_file_number( &alumns, &array_count );
	} while( is_break );

	write_file_text( alumns, array_count, path_file_text );

	read_file_text( path_file_text );

	free( alumns );
}

bool input_file_number( Alumns **alumns, int *array_count )
{
	int temp_file_number;

	printf( "Ingrese un numero de legajo: (-1 para finalizar) \n" );
	scanf( " %d", &temp_file_number );
	fflush( stdin );

	if( temp_file_number == -1 ) return false;

	if( *array_count != 0 )
	{
		Alumns* temp = (Alumns*)realloc( *alumns, ( sizeof(Alumns) * ( *array_count + 1 ) ) );
		*alumns = temp;
	} 

	(*alumns)[*array_count].number_file = temp_file_number;

	input_notes( alumns, *array_count );

	(*array_count)++;
	return true;
}

void input_notes( Alumns **alumns, int arrary_count )
{
	int temp_notes[MAX_NUMBER_NOTES];

	for( int i = 0; i < MAX_NUMBER_NOTES; i++ )
	{
		printf( "Ingrese nota(%d-%d) del alumno: \n", i+1, MAX_NUMBER_NOTES );
		scanf( " %d", &temp_notes[i] );
		fflush( stdin );
	}
	
	for( int j = 0; j < MAX_NUMBER_NOTES; j++ )
	{
		(*alumns)[arrary_count].notes[j] = temp_notes[j];
	}

	calc_avg_notes( alumns, arrary_count );
}

void calc_avg_notes( Alumns **alumns, int arrary_count )
{
	float temp_avg_notes;
	int temp_sum_notes = 0;

	for( int i = 0; i < MAX_NUMBER_NOTES; i++ )
	{
		temp_sum_notes += (*alumns)[arrary_count].notes[i];
	}
	
	temp_avg_notes = (float)temp_sum_notes / MAX_NUMBER_NOTES;

	(*alumns)[arrary_count].average_notes = temp_avg_notes;
}

void write_file_text( Alumns *data_alums, int index_data, char* path_file )
{
	
	FILE *file_text;
	char *data_text;

	file_text = fopen( path_file, "w" );

	data_text = formatter( data_alums, index_data );

	fprintf( file_text, data_text);

	fclose( file_text );
}

char* formatter( Alumns *data_alums, int index_data )
{
	char* construc_data_string = (char*)malloc(MAX_CHARS_FILE * sizeof(char));
	char* delimiter = " ";
	char* crlf = "\n";

	memset( construc_data_string, 0, sizeof(construc_data_string) );

	for( int i = 0; i < index_data; i++ )
	{
		char temp_string[MAX_CHARS_FILE];
		memset( temp_string, 0, sizeof(temp_string) );

		sprintf( temp_string, "%d", data_alums[i].number_file );
		strcat( construc_data_string, temp_string );
		strcat( construc_data_string, delimiter );

		for( int j = 0; j < MAX_NUMBER_NOTES; j++ )
		{
			memset( temp_string, 0, sizeof(temp_string) );

			sprintf( temp_string, "%d", data_alums[i].notes[j] );
			strcat( construc_data_string, temp_string );
			strcat( construc_data_string, delimiter );
		}

		memset( temp_string, 0, sizeof(temp_string) );

		sprintf( temp_string, "%f", data_alums[i].average_notes );
		strcat( construc_data_string, temp_string );
		strcat( construc_data_string, crlf );
	}

	return construc_data_string;
}

void read_file_text( char* path_file )
{
	FILE* file_stream;
	char buff[MAX_CHARS_VAR];

	file_stream = fopen( path_file, "r" );

	while( fgets( buff, sizeof( buff ), file_stream) != NULL )
	{
        printf( "%s", buff );
    }

	fclose( file_stream );
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR_BUFF 256
#define MAX_CHAR_FILE 5000

void init();
FILE* open_file( char*, char* );
void close_file( FILE* );
void tokenizer( FILE*, char* );
void write_file( FILE*, char[MAX_CHAR_FILE] );

int main()
{
	init();
	return 0;
}

void init()
{
	char* file_input = "/workspaces/cpp_devcontainer/programacion_1/m8/_files/lorem.txt";
	char* file_output = "/workspaces/cpp_devcontainer/programacion_1/m8/_files/tokenfile.txt";
	FILE* stream_file = NULL;
	char* mode = "r";

	stream_file = open_file( file_input, mode );

	tokenizer( stream_file, file_output );

	close_file( stream_file );
}

FILE* open_file( char* path, char* mode )
{
	FILE* temp_stream = NULL;

	temp_stream = fopen( path, mode );

	return temp_stream;
}

void tokenizer( FILE* stream_data, char* file_to_write )
{
    char line[MAX_CHAR_BUFF];
    char delimiters[] = " .,;:?!\n";
    char* word;
	char construc_string[MAX_CHAR_FILE];
	FILE* stream_output = NULL;
	char* mode_output_file = "w";

    while( fgets( line, MAX_CHAR_BUFF, stream_data ) != NULL )
	{
        word = strtok( line, delimiters );

        while( word != NULL )
		{
            strcat( construc_string, word );
			strcat( construc_string, "\n" );
            word = strtok( NULL, delimiters );
        }
    }

	stream_output = open_file( file_to_write, mode_output_file );

	write_file( stream_output, construc_string );

	close_file( stream_output );
}

void close_file( FILE* stream )
{
	fclose( stream );
}

void write_file( FILE* stream, char data_text[MAX_CHAR_FILE] )
{
	fprintf( stream, data_text );
}
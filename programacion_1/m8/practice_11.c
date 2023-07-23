#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNS 5
#define MAX_BUFF_CHARS 256

typedef struct
{
	int number_file;
	float average_notes;
    bool status;
} Alumns;

void init();
FILE* open_file( char*, char* );
void init_struct( Alumns[MAX_ALUMNS] );
void get_data( FILE*, Alumns[MAX_ALUMNS] );
void printer( Alumns[MAX_ALUMNS] );
int find_breaker( Alumns[MAX_ALUMNS] );
void proccess_data( Alumns[MAX_ALUMNS], char[MAX_BUFF_CHARS], int );
void write_file( FILE*, char[MAX_BUFF_CHARS] );

int main()
{
    init();
    return 0;
}

void init()
{
    char* path_file_data =      "/workspaces/cpp_devcontainer/programacion_1/m8/_files/promedios.txt";
    char* path_file_procces =   "/workspaces/cpp_devcontainer/programacion_1/m8/_files/aprobados.txt";
    FILE* stream_data =         NULL;
    int index_break =           0;
    Alumns data_alumns[MAX_ALUMNS];
    char string_to_write[MAX_BUFF_CHARS];

    stream_data = open_file( path_file_data, "r" );
    init_struct( data_alumns );

    get_data( stream_data, data_alumns );
    fclose( stream_data );
    index_break = find_breaker( data_alumns );

    /*printer( data_alumns );*/
    proccess_data( data_alumns, string_to_write, index_break );

    stream_data = NULL;
    stream_data = open_file( path_file_procces, "w" );

    write_file( stream_data, string_to_write );
    fclose( stream_data );
}

FILE* open_file( char* path, char* mode )
{
    FILE* temp_stream = NULL;
    temp_stream =       fopen( path, mode );

    return temp_stream;
}

void init_struct( Alumns temp_struct[MAX_ALUMNS] )
{
    for( int i = 0; i < MAX_ALUMNS; i++ )
    {
        temp_struct[i].number_file =    -1;
        temp_struct[i].average_notes =  -1.0;
        temp_struct[i].status =         false;
    }
}

void get_data( FILE* stream_data, Alumns data_alumns[MAX_ALUMNS] )
{
    char line[MAX_BUFF_CHARS];
    int count_lines =   0;
    char* single_data = NULL;
    char* delimiter =   " ";

    while( fgets( line, MAX_BUFF_CHARS, stream_data ) != NULL )
	{
        single_data = strtok( line, delimiter );
        if (single_data == NULL) break;

        sscanf( single_data, "%d", &data_alumns[count_lines].number_file );

        single_data = strtok( NULL, delimiter );
        if (single_data == NULL) break;

        sscanf( single_data, "%f", &data_alumns[count_lines].average_notes );

        data_alumns[count_lines].status = true;

        count_lines++;
    }
}

void printer( Alumns data[MAX_ALUMNS] )
{
    for( int i = 0; i < MAX_ALUMNS; i++ )
    {
        printf( "###############\n" );
        printf( "legajo %d \n",         data[i].number_file );
        printf( "promedio %0.2f \n",    data[i].average_notes );
        printf( "estado %d \n",         data[i].status );
    }
}

int find_breaker( Alumns data[MAX_ALUMNS] )
{
    for( int i = 0; i < MAX_ALUMNS; i++ )
    {
        if( data[i].status == false ) return i;
    }
}

void proccess_data( Alumns data[MAX_ALUMNS], char string_data[MAX_BUFF_CHARS], int break_data )
{
    float approved =                7.0;
    char title[MAX_BUFF_CHARS] =    "Los aprobados son";
    char buff_data[MAX_BUFF_CHARS];

    strcat( string_data, title );
    strcat( string_data, "\n" );

    for( int i = 0; i < break_data; i++ )
    {
        if( data[i].average_notes >= approved )
        {
            sprintf( buff_data, "%d", data[i].number_file );
            strcat( string_data, buff_data );

            strcat( string_data, " " );

            sprintf( buff_data, "%0.2f", data[i].average_notes );
            strcat( string_data, buff_data );

            strcat( string_data, "\n" );
        }
    }
}

void write_file( FILE* stream, char data[MAX_BUFF_CHARS] )
{
    fprintf( stream, data );
}
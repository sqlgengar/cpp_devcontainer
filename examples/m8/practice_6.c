#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 500

typedef struct
{
	int side_array;
	int year;
    int line_max;

} Configs;

Configs load_config( char* );

int main()
{
    Configs local_config;
    char *path = "./examples/m8/_files/config.txt";

    local_config = load_config( path );

    printf( "Tamaño de arrays: %d \n", local_config.side_array );
    printf( "Año: %d \n", local_config.year );
    printf( "Máximo de líneas: %d \n", local_config.line_max );

    return 0;

}

Configs load_config( char *path )
{
    Configs new_config;
    FILE *file;
    char buffer[MAX_BUFFER];

    file = fopen( path, "r" );
    
    if ( file == NULL )
    {
        fprintf( stderr, "fail to open file \n" );
        exit(EXIT_FAILURE);

    }

    while( fgets( buffer, MAX_BUFFER, file ) )
    {
        if( strcmp( buffer, "Archivo de configuración" ) == 0 ) continue;

        if( sscanf( buffer, "Tamaño de arrays: %d", &new_config.side_array) ==  EOF ) continue;
        if( sscanf( buffer, "Año: %d", &new_config.year ) ==                    EOF ) continue;
        if( sscanf( buffer, "Máximo de líneas: %d", &new_config.line_max) ==    EOF ) continue;

    }

    fclose(file);
    return new_config;

}
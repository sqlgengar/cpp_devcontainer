#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR_NAME 50
#define MAX_PERSONS 500
#define MAX_BUFF 5000

typedef struct
{
    int number_register;
    int number_file;
    char name[MAX_CHAR_NAME];
    int age;
    bool status;
} Person;

void execute();
void init_struct( Person[MAX_PERSONS] );
void load_data( Person[MAX_PERSONS], int* );
bool resolve_continue( int );
void formatter( Person[MAX_PERSONS], int, char[MAX_BUFF] );
void write_file( char[MAX_BUFF] );
void load_file();
void print_data( int, int, char[MAX_CHAR_NAME], int );
void flush_new_line( char* );

int main()
{
    execute();
    return 0;
}

void execute()
{
    Person persons[MAX_PERSONS];
    int index_break =               0;
    char string_data[MAX_BUFF] =    "";

    init_struct( persons );
    load_data( persons, &index_break );
    formatter( persons, index_break, string_data );
    write_file( string_data );

    load_file();
}

void init_struct( Person void_struct[MAX_PERSONS] )
{
    for( int i = 0; i < MAX_PERSONS; i++ )
    {
        void_struct[i].number_register =        -1;
        void_struct[i].number_file =            -1;
        strcpy( void_struct[i].name, "" );
        void_struct[i].age =                    -1;
        void_struct[i].status =                 false;
    }
}

void load_data( Person data_persons[MAX_PERSONS], int* index_break )
{
    bool has_continue = true;

    while( has_continue )
    {
        int temp_int =                      -1;
        char temp_string[MAX_CHAR_NAME] =   "";

        printf( "Ingrese el numero de legajo: (0 para salir) \n" );
        scanf( " %d", &temp_int );
        fflush( stdin );

        has_continue = resolve_continue( temp_int );
        if( has_continue == false ) break;
        data_persons[(*index_break)].number_register = (*index_break) + 1;
        data_persons[(*index_break)].number_file =     temp_int;

        printf( "Ingrese nombre: \n" );
        scanf( " %s", temp_string );
        fflush( stdin );
        strcpy( data_persons[(*index_break)].name, temp_string );

        printf( "Ingrese la edad: \n" );
        scanf( " %d", &temp_int );
        fflush( stdin );
        data_persons[(*index_break)].age = temp_int;

        data_persons[(*index_break)].status = true;
        (*index_break)++;
    }
}

bool resolve_continue( int file_number )
{
    if( file_number == 0 ) return false;

    return true;
}

void formatter( Person data[MAX_PERSONS], int index, char data_string[MAX_BUFF] )
{
    char temp_string[MAX_BUFF] = "";

    for( int i = 0; i < index; i++ )
    {
        strcat( data_string, "Registro #" );
        sprintf( temp_string, "%d", data[i].number_register );
        strcat( data_string, temp_string );
        strcat( data_string, "\n" );
        strcpy( temp_string, "" );

        strcat( data_string, "Legajo: " );
        sprintf( temp_string, "%d", data[i].number_file );
        strcat( data_string, temp_string );
        strcat( data_string, "\n" );
        strcpy( temp_string, "" );

        strcat( data_string, "Nombre: " );
        strcat( data_string, data[i].name );
        strcat( data_string, "\n" );

        strcat( data_string, "Edad: " );
        sprintf( temp_string, "%d", data[i].age );
        strcat( data_string, temp_string );
        strcat( data_string, "\n" );

        strcat( data_string, "\n" );
    }
}

void write_file( char data[MAX_BUFF] )
{
    char* path =    "/workspaces/cpp_devcontainer/programacion_1/m8/_files/data.txt";
    FILE* stream =  NULL;

    stream = fopen( path, "w" );

    fprintf( stream, data );

    fclose( stream );
}

void load_file()
{
    char* path =                    "/workspaces/cpp_devcontainer/programacion_1/m8/_files/data.txt";
    FILE* stream =                  NULL;
    char* token =                   NULL;
    char buff[MAX_BUFF] =           "";
    char* delimiter =               "#:";
    int temp_register =             -1;
    int temp_file =                 -1;
    char temp_name[MAX_CHAR_NAME] = "";
    int temp_age =                  -1;

    stream = fopen( path, "r" );

    while( fgets( buff, MAX_BUFF, stream ) != NULL )
    {
        token = strtok( buff, delimiter );
        token = strtok( NULL, delimiter);
        sscanf( token, "%d", &temp_register );

        fgets( buff, MAX_BUFF, stream );
        
        token = strtok( buff, delimiter );
        token = strtok( NULL, delimiter);
        sscanf( token, "%d", &temp_file );

        fgets( buff, MAX_BUFF, stream );

        token = strtok( buff, delimiter );
        token = strtok( NULL, " " );
        flush_new_line( token );
        strcpy( temp_name, token );

        fgets( buff, MAX_BUFF, stream );
        token = strtok( buff, delimiter );
        token = strtok( NULL, delimiter);
        sscanf( token, "%d", &temp_age );

        print_data( temp_register, temp_file, temp_name, temp_age );

        fgets( buff, MAX_BUFF, stream );
    }
}

void flush_new_line( char* string )
{
    int lenght = 0;

    lenght = strlen( string );
    string[lenght - 1] = '\0';
}

void print_data( int register_number, int file_number, char name[MAX_CHAR_NAME], int age )
{
    printf( "%d-%d|%s|%d \n", register_number, file_number, name, age );
}
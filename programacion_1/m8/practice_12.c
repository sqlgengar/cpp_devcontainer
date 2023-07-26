#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHARS_NAME 50
#define MAX_EMPLOYEES 500
#define MAX_BUFF_CHARS 5000
#define YEARS_FIRST_RISE 5
#define YEARS_SECOND_RISE 10
#define AMOUNT_FIRST_RISE 30
#define AMOUNT_SECOND_RISE 35

typedef struct
{
    char name[MAX_CHARS_NAME];
    float salary;
    int months;
    int years;
    bool status;
} Employees;

void init();
FILE* open_file( char*, char* );
void init_struct( Employees[MAX_EMPLOYEES] );
void get_data( Employees[MAX_EMPLOYEES], FILE* );
int find_break( Employees[MAX_EMPLOYEES] );
void proccess_rise( Employees[MAX_EMPLOYEES], int );
void formatter( Employees[MAX_EMPLOYEES], char[MAX_BUFF_CHARS], int );
void update_data( char[MAX_BUFF_CHARS], FILE* );

int main()
{
    init();
    return 0;
}

void init()
{
    Employees data_employees[MAX_EMPLOYEES];
    char* path_file =                       "/workspaces/cpp_devcontainer/programacion_1/m8/_files/sueldos.txt";
    FILE* file_stream =                     NULL;
    int index_break =                       MAX_EMPLOYEES;
    char data_formated[MAX_BUFF_CHARS] =    "";

    file_stream = open_file( path_file, "r" );
    init_struct( data_employees );

    get_data( data_employees, file_stream );
    index_break = find_break( data_employees );
    fclose( file_stream );

    proccess_rise( data_employees, index_break );
    file_stream = NULL;
    file_stream = open_file( path_file, "w" );

    formatter( data_employees, data_formated, index_break );
    update_data( data_formated, file_stream );
    fclose( file_stream );
}

FILE* open_file( char* path, char* mode )
{
    FILE* temp_stream = fopen( path, mode );

    return temp_stream;
}

void init_struct( Employees employees_struct[MAX_EMPLOYEES] )
{
    for( int i = 0; i < MAX_EMPLOYEES; i++ )
    {
        strcpy( employees_struct[i].name, "" );
        employees_struct[i].salary =    -1.0;
        employees_struct[i].months =    -1;
        employees_struct[i].years =     -1;
        employees_struct[i].status =    false;
    }
}

void get_data( Employees data[MAX_EMPLOYEES], FILE* stream )
{
    char line[MAX_BUFF_CHARS];
    int count_lines =   0;
    char* single_data = NULL;
    char* delimiter =   ";";

    while( fgets( line, MAX_BUFF_CHARS, stream ) != NULL )
	{
        single_data = strtok( line, delimiter );
        if (single_data == NULL) break;
        strcpy( data[count_lines].name, single_data );

        single_data = strtok( NULL, delimiter );
        if (single_data == NULL) break;
        sscanf( single_data, "%f", &data[count_lines].salary );

        single_data = strtok( NULL, delimiter );
        if (single_data == NULL) break;
        sscanf( single_data, "%d", &data[count_lines].months );

        single_data = strtok( NULL, delimiter );
        if (single_data == NULL) break;
        sscanf( single_data, "%d", &data[count_lines].years );

        data[count_lines].status = true;

        count_lines++;
    }
}

int find_break( Employees results[MAX_EMPLOYEES] )
{
    for( int i = 0; i < MAX_EMPLOYEES; i++ )
    {
        if( results[i].status == false ) return i;
    }
}

void proccess_rise( Employees data_raw[MAX_EMPLOYEES], int index_break )
{
    for( int i = 0; i < index_break; i++ )
    {
        float increment = 0.0;

        data_raw[i].months++;

        if( data_raw[i].months > 12 )
        {
            data_raw[i].months = 1;
            data_raw[i].years++;
        }

        if( data_raw[i].years < YEARS_FIRST_RISE ) continue;

        if( data_raw[i].years >= YEARS_FIRST_RISE && data_raw[i].years < YEARS_SECOND_RISE )
        {
            increment = ( data_raw[i].salary * AMOUNT_FIRST_RISE ) / 100;
            data_raw[i].salary += increment;
        }
        if( data_raw[i].years >= YEARS_SECOND_RISE )
        {
            increment = ( data_raw[i].salary * AMOUNT_SECOND_RISE ) / 100;
            data_raw[i].salary += increment;
        }
    }
}

void formatter( Employees data[MAX_EMPLOYEES], char data_formated[MAX_BUFF_CHARS], int index_break )
{
    for( int i = 0; i < index_break; i++ )
    {
        char temp_string[MAX_BUFF_CHARS] = "";

        strcat( data_formated, data[i].name );
        strcat( data_formated, ";" );

        sprintf( temp_string, "%0.2f", data[i].salary );
        strcat( data_formated, temp_string );
        strcat( data_formated, ";" );
        strcpy( temp_string, "" );

        sprintf( temp_string, "%d", data[i].months );
        strcat( data_formated, temp_string );
        strcat( data_formated, ";" );
        strcpy( temp_string, "" );

        sprintf( temp_string, "%d", data[i].years );
        strcat( data_formated, temp_string );
        strcpy( temp_string, "" );

        strcat( data_formated, "\n" );
    }
}

void update_data( char data_string[MAX_BUFF_CHARS], FILE* stream )
{
    fprintf( stream, data_string );
}
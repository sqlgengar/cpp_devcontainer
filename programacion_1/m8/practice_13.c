#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHARS_NAME 50
#define MAX_CHARS_ADDRESS 100
#define MAX_CUSTOMERS 1000
#define MAX_BUFF_STRING 50000

typedef struct
{
    char name[MAX_CHARS_NAME];
    char address[MAX_CHARS_ADDRESS];
    char gender[9];
    float credit;
    bool status;
} Customers;

void init();
FILE* open_file( char*, char* );
void init_struct( Customers[MAX_CUSTOMERS] );
void get_data( Customers[MAX_CUSTOMERS], FILE* );
int find_break( Customers[MAX_CUSTOMERS] );
void process_data_files( Customers[MAX_CUSTOMERS], char[MAX_BUFF_STRING], char[MAX_BUFF_STRING], int );
void write_file( char[MAX_BUFF_STRING], FILE* );
void printer_info( Customers[MAX_CUSTOMERS], int );

int main()
{
    init();
    return 0;
}

void init()
{
    char* path_customers =                  "/workspaces/cpp_devcontainer/programacion_1/m8/_files/clientes.txt";
    char* path_male_customers =             "/workspaces/cpp_devcontainer/programacion_1/m8/_files/varon.txt";
    char* path_female_customers =           "/workspaces/cpp_devcontainer/programacion_1/m8/_files/mujer.txt";
    FILE* stream_file =                     NULL;
    int index_break =                       0;
    char data_males[MAX_BUFF_STRING] =      "";
    char data_females[MAX_BUFF_STRING] =    "";
    Customers data_customers[MAX_CUSTOMERS];

    stream_file = open_file( path_customers, "r" );
    init_struct( data_customers );
    get_data( data_customers, stream_file );
    fclose(stream_file);
    stream_file = NULL;
    index_break = find_break( data_customers );

    process_data_files( data_customers, data_males, data_females, index_break );
    stream_file = open_file( path_male_customers, "w" );
    write_file( data_males, stream_file );
    fclose( stream_file );
    stream_file = NULL;
    stream_file = open_file( path_female_customers, "w" );
    write_file( data_females, stream_file );
    fclose( stream_file );
    stream_file = NULL;

    printer_info( data_customers, index_break );
}

FILE* open_file( char* path, char* mode )
{
    return fopen( path, mode );
}

void init_struct( Customers data[MAX_CUSTOMERS] )
{
    for( int i = 0; i < MAX_CUSTOMERS; i++ )
    {
        strcpy( data[i].name,       "" );
        strcpy( data[i].address,    "" );
        strcpy( data[i].gender,     "" );
        data[i].credit =            0.0;
        data[i].status =            false;
    }
}

void get_data( Customers data[MAX_CUSTOMERS], FILE* stream )
{
    char buff[MAX_BUFF_STRING] =    "";
    char* token =                   NULL;
    char* delimiter =               ";";
    int count_lines =               0;

    while( fgets( buff, MAX_BUFF_STRING, stream ) )
    {
        token = strtok( buff, delimiter );
        if( token == NULL ) break;
        strcpy( data[count_lines].name, token );

        token = strtok( NULL, delimiter );
        if( token == NULL ) break;
        strcpy( data[count_lines].address, token );

        token = strtok( NULL, delimiter );
        if( token == NULL ) break;
        strcpy( data[count_lines].gender, token );

        token = strtok( NULL, delimiter );
        if( token == NULL ) break;
        sscanf( token, "%f", &data[count_lines].credit );

        data[count_lines].status = true;

        count_lines++;
    }
}

int find_break( Customers data[MAX_CUSTOMERS] )
{
    for( int i = 0; i < MAX_CUSTOMERS; i++ )
    {
        if( data[i].status == false ) return i;
    }
    
    return MAX_CUSTOMERS;
}

void process_data_files( Customers customers[MAX_CUSTOMERS], char males[MAX_BUFF_STRING], char females[MAX_BUFF_STRING], int index )
{
    for( int i = 0; i < index; i++ )
    {
        char temp_string[MAX_BUFF_STRING] = "";

        if( strcmp( customers[i].gender, "masculino" ) == 0 )
        {
            strcat( males, customers[i].name );
            strcat( males, ";" );
            strcat( males, customers[i].address );
            strcat( males, ";" );
            strcat( males, customers[i].gender );
            strcat( males, ";" );
            sprintf( temp_string, "%0.2f", customers[i].credit );
            strcat( males, temp_string );
            strcat( males, "\n" );

            continue;
        }

        strcat( females, customers[i].name );
        strcat( females, ";" );
        strcat( females, customers[i].address );
        strcat( females, ";" );
        strcat( females, customers[i].gender );
        strcat( females, ";" );
        sprintf( temp_string, "%0.2f", customers[i].credit );
        strcat( females, temp_string );
        strcat( females, "\n" );
    }
}

void write_file( char data_string[MAX_BUFF_STRING], FILE* stream )
{
    fprintf( stream, data_string );
}

void printer_info( Customers all_data[MAX_CUSTOMERS], int index )
{
    int total_customer =        index;
    int total_males =           0;
    int total_females =         0;
    float sum_credits_males =   0.0;
    float sum_credits_females = 0.0;
    float avg_credit_males =    0.0;
    float avg_credit_females =  0.0;

    for( int i = 0; i < index; i++ )
    {
        if( strcmp( all_data[i].gender, "masculino" ) == 0 )
        {
            total_males++;
            sum_credits_males += all_data[i].credit;
            continue;
        }

        total_females++;
        sum_credits_females += all_data[i].credit;
    }
    
    avg_credit_males =      sum_credits_males / total_males;
    avg_credit_females =    sum_credits_females / total_females;

    printf( "Numero total de clientes %d \n",           total_customer );
    printf( "Numero total de varones %d \n",            total_males );
    printf( "Numero total de mujeres %d \n",            total_females );
    printf( "Promedio de saldos para hombres %0.2f \n", avg_credit_males );
    printf( "Promedio de saldos para mujeres %0.2f \n", avg_credit_females );
}
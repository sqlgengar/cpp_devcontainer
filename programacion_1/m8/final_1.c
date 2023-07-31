#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_STRING 500
#define MAX_REGISTERS 5000

typedef enum
{
    ALL_DATA,
    SORTED_DATA
} Type_printer;

typedef struct
{
    int id;
    char brand[MAX_BUFF_STRING];
    char model[MAX_BUFF_STRING];
    float price;
    float discount;
    bool status;
} Products;

void execute();
void init_struct( Products* );
void get_data( char*, Products* );
FILE* open_file( char*, char* );
int find_index_break( Products* );
int get_top_model( Products*, int );
void printer( Products*, int, Type_printer );
int resolve_top_id( Products*, int );
void show_sorted( Products*, int );
void insertion_sort( Products*, int );

int main()
{
    execute();
    return 0;
}

void execute()
{
    int index_break =   -1;
    int id_top_model =  -1;
    char* path_file =   "./productos.txt";
    Products data_products[MAX_REGISTERS];

    init_struct( data_products );
    get_data( path_file, data_products );
    index_break = find_index_break( data_products );
    if( index_break == -1 ) return;

    id_top_model = get_top_model( data_products, index_break );
    if( id_top_model == -1 ) return;

    show_sorted( data_products, index_break );
}

void init_struct( Products* data )
{
    for( int i = 0; i < MAX_REGISTERS; i++ )
    {
        data[i].id =            -1;
        strcpy( data[i].brand,  "\0" );
        strcpy( data[i].model,  "\0" );
        data[i].price =         -1.0;
        data[i].discount =      -1.0;
        data[i].status =        false;
    }
}

void get_data( char* path, Products* data )
{
    FILE* file_stream =             NULL;
    char line[MAX_BUFF_STRING] =    "\0";
    char* token =                   NULL;
    char* delimiter =               ",";
    int index =                      0;

    file_stream = open_file( path, "r" );

    /*Se ejecuta primera una unica vez para evitar el encabezado*/
    /*Esto ya mueve el puntero hasta la siguiente linea*/
    fgets( line, MAX_BUFF_STRING, file_stream );
    if( line == NULL ) return;

    while( fgets( line, MAX_BUFF_STRING, file_stream ) != NULL )
    {
        token = strtok( line, delimiter );
        if( token == NULL ) break;

        data[index].id = atoi( token );

        token = strtok( NULL, delimiter );
        if( token == NULL ) break;

        strcpy( data[index].brand, token );

        token = strtok( NULL, delimiter );
        if( token == NULL ) break;

        strcpy( data[index].model, token );

        token = strtok( NULL, delimiter );
        if( token == NULL ) break;

        data[index].price = atof( token );

        token = strtok( NULL, delimiter );
        if( token == NULL ) break;

        data[index].discount = atof( token );

        data[index].status = true;
        index++;
    }
    
    fclose( file_stream );
}

FILE* open_file( char* path, char* mode )
{
    FILE* temp_stream = fopen( path, mode );

    return temp_stream;
}

int find_index_break( Products* data )
{
    for( int i = 0; i < MAX_REGISTERS; i++ )
    {
        if( data[i].status == false ) return i;
    }
    
    return MAX_REGISTERS;
}

int get_top_model( Products* data, int index_break )
{
    int temp_top_id = -1;
    Type_printer print = ALL_DATA;

    printer( data, index_break, print );

    temp_top_id = resolve_top_id( data, index_break );
    
    return temp_top_id;
}

void printer( Products* data, int index_break, Type_printer type )
{
    switch( type )
    {
        case ALL_DATA:
            printf( "##################################################\n" );
            printf( "data in file: \n" );

            for( int i = 0; i < index_break; i++ )
            {
                printf( "%d ",      data[i].id );
                printf( "%s ",      data[i].brand );
                printf( "%s ",      data[i].model );
                printf( "%0.2f ",   data[i].price );
                printf( "%0.2f \n", data[i].discount );

                printf( "###################################################\n" );
            }
        break;
    
        case SORTED_DATA:
            printf( "##################################################\n" );
            printf( "sorted data: \n" );

            for( int i = 0; i < index_break; i++ )
            {
                printf( "%0.2f ",   data[i].price );
                printf( "%s ",      data[i].brand );
                printf( "%s \n",    data[i].model );

                printf( "###################################################\n" );
            }
        break;
    }
}

int resolve_top_id( Products* data, int index_break )
{
    float temp_max_final_price =    -1.0;
    int temp_top_id =               -1;

    for( int i = 0; i < index_break; i++ )
    {
        float temp_final_price = 0.0;

        temp_final_price = data[i].price - ( data[i].price * data[i].discount );

        if( temp_final_price > temp_max_final_price )
        {
            temp_max_final_price =  temp_final_price;
            temp_top_id =           i;
            continue;
        }
    }
    
    return temp_top_id;
}

void show_sorted( Products* data, int index_break )
{
    Type_printer print = SORTED_DATA;

    insertion_sort( data, index_break );

    printer( data, index_break, print );
}

void insertion_sort( Products* data, int index_break )
{
    for( int i = 1; i < index_break; i++ )
    {
        Products temp_register =    data[i];
        int j =                     i - 1;

        while( temp_register.price < data[j].price && j >= 0 )
        {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = temp_register;
    }
}
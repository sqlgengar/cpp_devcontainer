#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int cod_zona;
    int num_lista;
    int votos;
} registro;

void mostrarVotos(FILE *);
void pausa(void);
void cargarVotos(FILE *);
int validate_zone( int );
int validate_list( int );
void resolve_action( int, int, FILE* );
void new_register( int, int, FILE* );
void printer( FILE* );
void increment_vote( registro, FILE* );

int main()
{
    FILE *binario;
    char v[10] = "votos.dat";
    // if ((binario = fopen(v, "rb+")) == NULL)
    // esto esta comentado para que cuando ejecuten no acumule y solo guarde lo ingresado en ese momento
    binario = fopen(v, "wb+");
    cargarVotos(binario);
    mostrarVotos(binario);
    fclose(binario);
    return 0;
}

void pausa(void)
{
    printf("\n\nPresione Enter para continuar...\n\n");
    fflush(stdin);
    getchar();
}

void cargarVotos(FILE *x)
{
    int numlista, codZona, flag; // numlista seria el numero de Lista y codZona el codigo de zona
    registro r; // este es el registro r donde se guardara lo cargado por teclado
    // COMPLETAR LA CARGA DE VOTOS

    rewind(x);
    codZona =   0;
    numlista =  -1;

    while( codZona != -1 )
    {
        printf( "Ingrese el codigo de la zona: \n" );
        scanf( " %d", &codZona );
        fflush( stdin );
        if( codZona == -1 ) break;

        codZona = validate_zone( codZona );
        if( codZona == -1 ) break;

        printf( "Ingrese el numero de la lista: \n" );
        scanf( " %d", &numlista );
        fflush( stdin );

        numlista = validate_list( numlista );

        resolve_action( codZona, numlista, x );
    }

    printer( x );
}

void mostrarVotos(FILE *x)
{
    int totalVotos[3] = {0}; // acumula la cantidad de votos por lista
    int totalZonas[5] = {0}; // Acumula el total de votos por zona
    int votosTotales = 0; // acumula el total de votos en general
    char nom_lista[][40] = {"Juan Luis Manzur", "Beatriz Elias de Perez", "Ricardo Argentino Bussi"};
    char nom_zona[][40] = {"Aguilares", "Bella Vista", "Famailla", "Graneros", "La Cocha"};
    float porcentaje;
    registro r;

    rewind(x);
    // fread(&r, sizeof(r), 1, x); // INSTRUCCION PARA LEER ARCHIVO
   // COMPLETAR EL MOSTRAR

    fseek( x, 0L, SEEK_SET );
    fread( &r, sizeof( r ), 1, x );

    while( !feof( x ) )
    {
        printf( "\t %d \t - \t %d - \t %d \n", r.cod_zona, r.num_lista, r.votos );
        fread( &r, sizeof(r), 1, x );
    }

}

int validate_zone( int code_zone )
{
    while( code_zone < 1 || code_zone > 5 )
    {   
        printf( "Numero de zona incorrecto.\n" );
        printf( "Ingrese un numero de zona entre 1 y 5 o -1 para salir: \n" );

        scanf( " %d", &code_zone );
        fflush( stdin );
        if( code_zone == -1 ) break;
    }
    
    return code_zone;
}

int validate_list( int number_list )
{
    while( number_list < 1 || number_list > 3 )
    {   
        printf( "Numero de lista incorrecto.\n" );
        printf( "Ingrese un numero de la lista entre 1 y 3: \n" );

        scanf( " %d", &number_list );
        fflush( stdin );
    }
    
    return number_list;
}

void resolve_action( int code_zone, int number_list, FILE* stream_file )
{
    registro register_vote;
    bool is_code_zone = false;
    bool is_number_list = false;
    fseek( stream_file, 0L, SEEK_SET );

    while( !feof(stream_file) )
    {
        fread( &register_vote, sizeof( register_vote ), 1, stream_file );

        if( register_vote.cod_zona == code_zone )
        {
            is_code_zone = true;

            if( register_vote.num_lista == number_list ) is_number_list = true;
            break;
        }
    }

    if( is_code_zone && is_number_list )
    {
        increment_vote( register_vote, stream_file );
        return;
    }
    if( !is_code_zone || !is_number_list ) 
    {
        new_register( code_zone, number_list, stream_file );
        return;
    }
}

void new_register( int code_zone, int number_list, FILE* stream_file )
{
    registro temp_register;
    temp_register.cod_zona = code_zone;
    temp_register.num_lista = number_list;
    temp_register.votos = 1;

    fseek( stream_file, 0L, SEEK_END );
    fwrite( &temp_register, sizeof(temp_register), 1, stream_file );
}

void printer( FILE* stream )
{
    registro temp_data;

    fseek( stream, 0L, SEEK_SET );
    fread( &temp_data, sizeof(temp_data), 1, stream );

    while( !feof(stream) )
    {
        printf( "\t %d \t - \t %d - \t %d \n", temp_data.cod_zona, temp_data.num_lista, temp_data.votos );
        fread( &temp_data, sizeof(temp_data), 1, stream );
    }
}

void increment_vote( registro temp_data, FILE* stream )
{
    temp_data.votos++;

    fseek( stream, -sizeof( temp_data ), SEEK_CUR );
    fwrite( &temp_data, sizeof( temp_data ), 1, stream );
}
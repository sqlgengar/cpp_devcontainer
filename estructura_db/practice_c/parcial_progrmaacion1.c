/*
    La casa de electrónica ShangTsung dispone de un archivo productos.txt en cual lista el id de producto, 
    marca, modelo, precio de lista y descuento por pago al contado. Se pide:
    1) Desarrollar la función void getData(char* nomArchivo, registro* data); que reciba el nombre 
    del archivo nomArchivo y el puntero a un vector data. La función debe abrir el archivo y cargarlo en el 
    vector data.
    2) Desarrollar la función int getMejorModelo(registro* data); que reciba el vector ya cargado y:
    a. Muestre por pantalla el contenido del vector.
    b. Devuelva el id del registro que es la mejor opción pagando al contado (es decir, la más barata
    incluyendo el descuento por pago al contado).
    3) Desarrollar la función void mostrarOrdenado(registro* data); que reciba el vector data y lo 
    muestre ordenado según el precio de lista (mostrar con formato: precio de lista, marca,
    modelo).

    Para todos los puntos, utilizar la siguiente estructura:
    #define DIM 55
    typedef struct{
    int id;
    char marca[DIM];
    char modelo[DIM];
    float precio;
    float descuento;
    } registro;

    Se recomienda (o casi que se debe) utilizar funciones definidas en string.h, como strtok() (que tokeniza una 
    cadena), strcpy() (que copia cadenas), atoi() (que convierte cadenas a enteros y atof() (que convierte 
    cadenas a flotantes).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 55
#define BUFF 100

typedef struct{
    int id;
    char marca[DIM];
    char modelo[DIM];
    float precio;
    float descuento;
} Registro;

void get_data( char *, Registro * );

int main()
{
    Registro *registers;
    char *path = "./productos.txt";

    get_data( path, registers );

    return 0;
}

void get_data( char *path_file, Registro *data )
{
    FILE *file;
    char temp_data[BUFF];
    int temp_id;
    char temp_marca[DIM];
    char temp_modelo[DIM];
    float temp_precio;
    float temp_descuento;
    char delimiter = ',';

    file = fopen( path_file, "r" );
    rewind( file );
    data = (Registro*)calloc( BUFF, sizeof(Registro) );

    fgets( temp_data, BUFF, file );

    while( fgets( temp_data, BUFF, file ) )
    {
        sscanf( data, "%d, %[^,], %[^,], %f, %f", &temp_id, temp_marca, temp_modelo, &temp_precio, &temp_descuento );
        data->id =              temp_id;
        data->precio =          temp_precio;
        data->descuento =       temp_descuento;
        strcpy( data->marca,    temp_marca );
        strcpy( data->modelo,   temp_modelo );
        printf( "%d %s %s %.2f %.2f", data[0].id, data[0].marca, data[0].modelo, data[0].precio, data[0].descuento );
        data++;
    }
}
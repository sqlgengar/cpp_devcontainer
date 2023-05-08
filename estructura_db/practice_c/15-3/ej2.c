//ejercicio 2
/*  a).Realizar las funciones mostrar
    b).Ordenar el vector por nombre de rubro en forma alfabetica
    c).Mostrar el vector ordenado
    d).Mostrar el rubro con un aumento del 20% en el precio de mayor a menor
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_REGISTER 5

typedef struct
{
    int cod_rubro;
    char nom_rub[25];
    float precio;
}Registro;

void print_r( Registro[MAX_REGISTER] );
void insertion_sort( Registro[MAX_REGISTER] );
void increment_price( Registro[MAX_REGISTER] );

int main()
{
    Registro rubro[MAX_REGISTER] = 
    { 
        {1,"automotores",   15.25},
        {2,"oficinas",      12.46},
        {3,"ensenanza",     8.34},
        {4,"servicios",     10.54},
        {5,"profesionales", 14.80}
    };

    print_r( rubro );
    printf( "\n\n" );

    insertion_sort( rubro );

    print_r( rubro );
    printf( "\n\n" );

    increment_price( rubro );

    return 0;
}

void print_r( Registro p_register[MAX_REGISTER] )
{
    for( int i = 0; i < MAX_REGISTER; i++)
    {
        printf( "%d, %s,\t %.2f \n", p_register[i].cod_rubro, p_register[i].nom_rub, p_register[i].precio );
    }
}

void insertion_sort( Registro o_register[MAX_REGISTER] )
{
    for( int i = 0; i < MAX_REGISTER; i++ )
    {
        Registro temp_register;
        int temp_comp;

        temp_comp = strcmp( o_register[i].nom_rub, o_register[i+1].nom_rub );

        if( temp_comp > 0 )
        {
            temp_register =     o_register[i];
            o_register[i] =     o_register[i+1];
            o_register[i+1] =   temp_register;

            if( !i ) continue;

            for( int j = i; j >= 0; j-- )
            {
                temp_comp = strcmp( o_register[j].nom_rub, o_register[j-1].nom_rub );

                if( temp_comp > 0 ) break;
                   
                temp_register =     o_register[i];
                o_register[i] =     o_register[i+1];
                o_register[i+1] =   temp_register;
            }
        }
    }
}

void increment_price( Registro ip_register[MAX_REGISTER] )
{
    for( int i = 0; i < MAX_REGISTER; i++ )
    {
        Registro temp_register;
        float temp_comp;

        temp_comp = ip_register[i].precio - ip_register[i+1].precio;

        if( temp_comp < 0 )
        {
            temp_register =     ip_register[i];
            ip_register[i] =     ip_register[i+1];
            ip_register[i+1] =   temp_register;

            if( !i ) continue;

            for( int j = i; j >= 0; j-- )
            {
                temp_comp = ip_register[j].precio - ip_register[j-1].precio;

                if( temp_comp < 0 ) break;
                
                temp_register =     ip_register[j];
                ip_register[j] =     ip_register[j-1];
                ip_register[j-1] =   temp_register;
            }
        }
    }

    for( int k = 0; k < MAX_REGISTER; k++)
    {
        printf( "%d, %s,\t %.2f \n", ip_register[k].cod_rubro, ip_register[k].nom_rub, ( ( ip_register[k].precio * 0.20 ) + ip_register[k].precio ) );
    }
}
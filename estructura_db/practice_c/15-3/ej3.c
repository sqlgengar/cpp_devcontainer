/*Ejercicio 3
Dado el siguiente struct */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ALUMNS 2
#define MAX_CHARS 30
#define MAX_NOTES 5

typedef struct
{
    char nombre[30];
    char apellido[30];
    int edad;
    float notas[5];
}Alumno;

Alumno load_alumns();
void print_avg( Alumno[MAX_ALUMNS] );
void print_struc( Alumno[MAX_ALUMNS] );
void print_fails( Alumno[MAX_ALUMNS] );

/*Realice un programa qeu cargue 10 alumnos y ademas obtener:
        a). Una funcion que muestre solo los alumnos con promedio mayor a 7: nombre apellido promedio
        b). Una funcion que retorne cuantos alumnos tuvieron al menos 1 aplazo: (aplazos es 1,2,3) */

int main()
{
    Alumno alumns[MAX_ALUMNS];

    for( int i = 0; i < MAX_ALUMNS; i++ )
    {
        alumns[i] = load_alumns();
    }
    print_struc( alumns );

    print_avg( alumns );

    print_fails( alumns );

    return 0;
}

Alumno load_alumns()
{
    Alumno new_alumns;
    char temp_string[MAX_CHARS];
    int temp_age;

    printf( "Enter the name alumn: \n" );
    scanf( " %s", temp_string );
    fflush( stdin );
    strcpy( new_alumns.nombre, temp_string );
    strcpy( temp_string, "" );

    printf( "Enter the last name alumn: \n" );
    scanf( " %s", temp_string );
    fflush( stdin );
    strcpy( new_alumns.apellido, temp_string );
    strcpy( temp_string, "" );

    printf( "Enter the age of alumn: \n" );
    scanf( " %d", &temp_age );
    fflush( stdin );
    new_alumns.edad = temp_age;

    for( int i = 0; i < MAX_NOTES; i++)
    {
        float temp_nota;

        printf( "Enter the note %d of %d: \n", i+1, MAX_NOTES );
        scanf( " %f", &temp_nota );
        fflush( stdin );
        new_alumns.notas[i] = temp_nota;
    }

    return new_alumns;
}

void print_struc( Alumno p_alu[MAX_ALUMNS] )
{
    for( int i = 0; i < MAX_ALUMNS; i++)
    {
        printf( "Alumn (%d-%d) \n\n", i+1, MAX_ALUMNS );
        printf( "Name: %s \n", p_alu[i].nombre );
        printf( "Last name: %s \n", p_alu[i].apellido );
        printf( "Age: %d \n", p_alu[i].edad );

        for( int j = 0; j < MAX_NOTES; j++)
        {
            printf( "Note: %.2f(%d-%d) \n", p_alu[i].notas[j], j+1, MAX_NOTES );
        }
    }
}

void print_avg( Alumno p_avg_alu[MAX_ALUMNS] )
{
    for( int i = 0; i < MAX_ALUMNS; i++ )
    {
        float sum_avg = 0;
        float avg = 0;

        for( int j = 0; j < MAX_NOTES; j++)
        {
            sum_avg += p_avg_alu[i].notas[j];
        }

        avg = sum_avg / MAX_NOTES;

        if( avg > 7.0 ) printf( "%s %s %.2f \n", p_avg_alu[i].nombre, p_avg_alu[i].apellido, avg );
    }
}

void print_fails( Alumno p_fail_alu[MAX_ALUMNS] )
{
    int count_fails = 0;

    for( int i = 0; i < MAX_ALUMNS; i++ )
    {
        bool have_fails = false;

        for( int j = 0; j < MAX_NOTES; j++)
        {
            if( p_fail_alu[i].notas[j] <= 3.0 && !have_fails )
            {
                count_fails++;
                have_fails = true;
            }
        }
    }

    printf( "The amount of fails alumns is: %d \n", count_fails );
}
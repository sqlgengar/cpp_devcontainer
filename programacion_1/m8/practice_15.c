#include <stdio.h>
#include <string.h>

#define MAX_REGISTERS 2
#define MAX_BUFF 500

typedef enum
{
    MALE =      1,
    FEMALE =    2
} Genders;

typedef struct
{
    char name[MAX_BUFF];
    Genders gender;
    int age;
    char date_last_pay[MAX_BUFF];
} Partners;

void execute();
void init_struct( Partners* );
void load_data( Partners* );

int main()
{
    execute();
    return 0;
}

void execute()
{
    Partners data_partners[MAX_REGISTERS];
    init_struct( data_partners );

    load_data( data_partners );
}

void init_struct( Partners* data )
{
    for( int i = 0; i < MAX_REGISTERS; i++ )
    {
        strcpy( data[i].name,           "\0" );
        data[i].gender =                0;
        data[i].age =                   0;
        strcpy( data[i].date_last_pay,  "\0" );
    }
}

void load_data( Partners* data )
{
    char temp_string[MAX_BUFF] =    "\0";
    int temp_int =                  0;
    Genders temp_gender =           0;

    for( int i = 0; i < MAX_REGISTERS; i++ )
    {
        printf( "Ingerese el nombre del socio: \n" );
        scanf( " %s", temp_string );
        fflush( stdin );
        strcpy( data[i].name, temp_string );

        printf( "Ingerese el nombre del socio: \n" );
        printf( "1) Masculino \n" );
        printf( "2) Femenino \n" );
        scanf( " %d", &temp_gender );
        fflush( stdin );
        data[i].gender = temp_gender;

        printf( "Ingrese la edad: \n" );
        scanf( " %d", &temp_int );
        fflush( stdin );
        data[i].age = temp_int;

        printf( "Ingrese la fecha del ultimo pago: (DD/MM/AAAA) \n" );
        scanf( " %s", temp_string );
        fflush( stdin );
        strcpy( data[i].date_last_pay, temp_string );
    }
}
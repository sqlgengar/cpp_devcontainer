#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTES 2

enum types
{
    FILE_NUMBER =   0,
    NOTES =         1
};

typedef struct
{
    int file_number;
    int *notes[MAX_NOTES];

} Students;

void load_data( int*, int );
void wirte_file( char*, int, int, int );

int main()
{
    Students student;
    char *path = "./examples/m8/_files/alumnos.txt";
    int is_file = -1;

    do
    {
        printf( "enter file number of student or (-1) for exit \n" );

        load_data( &student.file_number, FILE_NUMBER );

        if( student.file_number == -1 ) continue;
        
        for( int i = 0; i < MAX_NOTES; i++ )
        {
            printf( "enter the note %d of %d for student \n", i+1, MAX_NOTES );

            load_data( &student.notes[i], NOTES );

        }        

    }while( student.file_number != -1 );

    printf( "%d legajo \n", student.file_number );
    printf( "%d nota \n", student.notes[0] );
    
    return 0;

}

void load_data( int *value, int type )
{
    int temp;

    switch( type )
    {
        case FILE_NUMBER:

            scanf( " %d", &temp );
            fflush( stdin );

            if( temp == -1 ) return;

            (*value) = temp;

        break;
    
        case NOTES:

            scanf( " %d", &temp );
            fflush( stdin );

            (*value) = temp;

        break;

    }

}
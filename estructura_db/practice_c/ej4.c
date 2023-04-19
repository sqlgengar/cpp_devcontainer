#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    char ch;
    char *path = "./estructura_db/practice_c/_files/texto99.txt";

    if( ( file = fopen( path, "w" ) ) == NULL )
    {
        printf( "\n\n***El archivo %s no pudo abrirse***\n", path );
    }
    else
    {
        printf( "\n\nIngrese caracteres hasta [Enter]" );
        
        while( ( ch = getchar() ) != '\n' )
        {
            fputc( ch, file );
        }
    }

    fclose( file );
    return 0;
}
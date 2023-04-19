#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void create_log( char*, char*, char* );

int main()
{
	char *current_date;
	char *text = 	"Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit.";
	char *path = 	"./examples/m8/_files/debug.log";
	time_t now = 	time(NULL);

	/*formatear fecha*/
	current_date = 	asctime( localtime( &now ) );
	current_date[strcspn( current_date, "\n" )] = 0;

	create_log( text, current_date, path );

	return 0;

}

void create_log( char *text, char *date, char *path )
{
	FILE *file;
	
	file = fopen( path, "a" );

	if( file == NULL )
	{
		printf( "fail to open file" );

		exit(EXIT_FAILURE);

	}

	fprintf( file, "%s %s \n", date, text );

	fclose( file );

}
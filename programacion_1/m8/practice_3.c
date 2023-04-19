#include<stdio.h>
#include<stdlib.h>

int count_vocals( FILE * );

int main()
{
	FILE *file;
	char *path = 		"./examples/m8/_files/lorem.txt";
	int total_vocals = 	0;

	file = fopen( path, "r" );

	if( file == NULL )
	{
		printf( "fail to open %s", path );

		exit(EXIT_FAILURE);

	}

	total_vocals = count_vocals( file );

	printf( "The total of vocals in files is: %d \n", total_vocals );

	fclose( file );
	return 0;

}

int count_vocals( FILE *file )
{
	char temp_character;
	int count = 0;

	while( !feof( file ) )
	{
		temp_character = fgetc( file );

		switch( temp_character )
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': count++;
			break;

			default:
			break;

		}

	}

	return count;

}
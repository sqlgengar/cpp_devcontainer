#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *file;
	char *path = "./examples/m8/_files/lorem.txt";

	file = fopen( path, "r" );

	if( file == NULL )
	{
		printf( "fail to open %s", path );

		exit(EXIT_FAILURE);

	}

	fclose( file );

	return 0;

}
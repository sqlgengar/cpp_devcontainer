#include<stdio.h>
#include<stdlib.h>

#define MAX_CHARS 500

int main(){

	FILE *file;
	char *path = "./examples/m8/_files/pro1.txt";
	char data[MAX_CHARS];
	char *temp_data;

	file = fopen( path, "r" );

	if( file == NULL )
	{
		printf( "fail to open %s", path );

		exit(EXIT_FAILURE);

	}

	while( ( fgets( data, MAX_CHARS, file ) ) != NULL ){

		printf( "%s", data );

	}

	fclose( file );

	return 0;

}
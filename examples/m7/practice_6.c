#include <stdio.h>
#include <string.h>
#define LENGTH_NAME 50 //max length for tree names

typedef enum{ SAUSE = 1, PINO, MIMOSA } Category;

typedef struct{

	char name[LENGTH_NAME];
	Category type;
	unsigned long long int amount_leafs;

} Trees;

Trees init();
void get_tree( Trees );

int main(){

	Trees current_tree;

	current_tree = init();
	get_tree( current_tree );

	printf( "script done \n" );

	return 0;

}

Trees init(){

	Trees new_tree;

	printf( "Enter a name for the tree: \n");
	fgets( new_tree.name, LENGTH_NAME, stdin );
	fflush( stdin );

	printf( "Enter a type of tree \n");
	printf( "SAUSE  \t -> 1 \n");
	printf( "PINO   \t -> 2 \n");
	printf( "MIMOSA \t -> 3 \n");
	scanf( " %d", &new_tree.type );

	printf( "Enter the amount of leafs: \n");
	scanf( " %llu", &new_tree.amount_leafs );
	fflush( stdin );
	
	return new_tree;

}

void get_tree( Trees tree ){

	switch( tree.type ){


		case SAUSE:
			printf( "Tree %s", tree.name );
			printf( "Type: Sause \n" );
			printf( "Amount leafs: %llu \n", tree.amount_leafs );
		break;

		case PINO:
			printf( "Tree %s \n", tree.name );
			printf( "Type: Pino \n" );
			printf( "Amount leafs: %llu \n", tree.amount_leafs );
		break;

		case MIMOSA:
			printf( "Tree %s \n", tree.name );
			printf( "Type: Mimosa \n" );
			printf( "Amount leafs: %llu \n", tree.amount_leafs );
		break;
	}

}

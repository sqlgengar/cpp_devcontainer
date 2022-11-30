#include <stdio.h>

int main(){

	int ventas_cola		,
	    ventas_naranja	,
	    ventas_limonada	,
	    precio_cola		,
	    precio_naranja 	,
	    precio_limonada	,
	    total_cola		,
	    total_naranja	,
	    total_limonada	;
	
	printf( "ingresar la venta de cola: \n" 	);

	scanf( "%i", &ventas_cola 	);
	fflush( stdin );

	printf( "ingresar la venta de naranja: \n" 	);

        scanf( "%i", &ventas_naranja 	);
        fflush( stdin );

	printf( "ingresar la venta de limonada: \n" 	);

        scanf( "%i", &ventas_limonada 	);
        fflush( stdin );

	printf( "ingresar el precio de cola: \n" 	);

        scanf( "%i", &precio_cola 	);
        fflush( stdin );

	printf( "ingresar el precio de naranja: \n" 	);

        scanf( "%i", &precio_naranja 	);
        fflush( stdin );

	printf( "ingresar el precio de limonada: \n" 	);

        scanf( "%i", &precio_limonada 	);
        fflush( stdin );

	total_cola 	= ventas_cola 		* precio_cola		;
	total_naranja 	= ventas_naranja 	* precio_naranja	;
	total_limonada 	= ventas_limonada 	* precio_limonada	;

	printf( "PRODUCTO \t VENTAS \t PRECIO \t TOTAL \n" );
	printf( "COLA     \t %i     \t %i     \t %i    \n", ventas_cola					, precio_cola		, total_cola 		);
	printf( "NARANAJA \t %i     \t %i     \t %i    \n", ventas_naranja				, precio_naranja	, total_naranja 	);
	printf( "LIMONADA \t %i     \t %i     \t %i    \n", ventas_limonada				, precio_limonada	, total_limonada 	);
	printf( "\t       \t \t     \t TOTAL  \t %i    \n", total_cola + total_naranja + total_naranja 							);

	return 0;

}

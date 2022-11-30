#include <stdio.h>
#include <math.h>


/*
 
   for this program, assume that triagle type is rectangule

 */

int main (){

	float triangle_base,
	      triangle_height;

	printf( "enter the base of the triangle in cm \n"   );

	scanf( "%f", &triangle_base   );
	fflush( stdin );

	printf( "enter the height of the triangle in cm \n" );
	
	scanf( "%f", &triangle_height );
	fflush( stdin );

	printf( "the perimeter of the triangle is %.2lfcm and its area is %.2fcm^2 \n" ,
	      pow( ( ( triangle_base * triangle_base ) + ( triangle_height * triangle_height ) ), 0.5 ) ,
	      ( triangle_base * triangle_height ) / 2.0 );

	return 0;
}

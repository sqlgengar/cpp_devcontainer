#include <stdio.h>

void main(){

	int a 	  = 10;
	float b   = 19.3;
	double d  = 64.8;
	char c    = 64;
	char h 	  = 'a';

	printf( "a + b float 	     %f\n" , a + b 	   );
	printf( "c + d double 	     %lf\n", c + d 	   );
	printf(	"(int)d + a int      %i\n" , (int)d + a    );
	printf( "d + b double 	     %lf\n", d + b 	   );
	printf( "(float) c + d float %f\n" , (float) c + d );
	printf( "h + 1 char 	     %c\n" , h + 1 	   );

}

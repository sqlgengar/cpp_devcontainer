#include <stdio.h>
#define valor 6

int main (){
	
	int 	var1, var2 = 1;
	float 	var3;

	var1 = 3 / 2 + 10 - 3;
	var3 = 3.0 / 2.0 + 10 - 3;
	
	printf( "%d -- %.2f\n"	, var1, var3 		 );
	printf( "%d\n"		, valor * 3 + 1 / 2 	 );
	printf( "%d\n"		, 5 + 2 - 1 > 5 	 );
	printf( "%d\n"		, 3 > 1 || valor * 2 < 1 );
	printf( "%d\n"		, 5 != 1 && valor > 2 	 );
	printf( "%d\n"		, var1 + var2 <= var3 	 );

	return 0;
}

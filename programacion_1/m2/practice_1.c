#include <stdio.h>

int main(){

	int a = 3,
	    b = 2,
	    c = 1,
	    d,
	    e;

	float m = 2.5,
	      n = 5.4,
	      r,
	      s;

	d = m;
	printf( "\t d=m \t\t | %d \n "           , d );

	d = n;
	printf( "\t d=n \t\t | %d \n "           , d );

	e = 3.7;
	printf( "\t e=3.7 \t\t | %d \n "         , e );

	d = a;
	printf( "\t d=a \t\t | %d \n "           , d );

	d = a + b;
	printf( "\t d=a+b \t\t | %d \n "         , d );

	d = a / b;
	printf( "\t d=a/b \t\t | %d \n "         , d );

	d = a % b;
	printf( "\t d=a%%b \t\t | %d \n "        , d );

	d = a % 2;
	printf( "\t d=a%%2 \t\t | %d \n "        , d );

	e = b / c;
	printf( "\t e=b/c \t\t | %d \n "         , e );

	e = c / b;
	printf( "\t e=c/b \t\t | %d \n "         , e );

	r = a + b;
	printf( "\t r=a+b \t\t | %.2f \n "       , r );

	r = a / b;
	printf( "\t r=a/b \t\t | %.2f \n "       , r );

	r = a / 2;
	printf( "\t r=a/2 \t\t | %.2f \n "       , r );

	r = a / 2.0;
	printf( "\t r=a/2.0 \t | %.2f \n "     , r );

	s = m + n;
	printf( "\t s=m+n \t\t | %.2f \n "       , s );

	s = 3 + 4 - 1;
	printf( "\t s=3+4-1 \t | %.2f \n "     , s );

	s = 3.0 + 4.0 - 1;
	printf( "\t s=3.0+4.0-1 \t | %.2f \n " , s );

	a = m;
	printf( "\t a=m \t\t | %d \n "           , a );

	a = m / 2;
	printf( "\t a=m/2 \t\t | %d \n "         , a );

	a = m / 2.0;
	printf( "\t a=m/2.0 \t | %d \n "       , a );

	a = 3.0 + 4.0 - 1;
	printf( "\t a=3.0+4.0-1 \t | %d \n "   , a );

	r = a + 1;
	printf( "\t r=a+1 \t\t | %.2f \n "       , r );

	r = a + 1.0;
	printf( "\t r=a+1.0 \t | %.2f \n "     , r );

	a++;
	printf( "\t a++ \t\t | %d \n "           , a );

	r++;
	printf( "\t r++ \t\t | %.2f \n "         , r );

	b--;
	printf( "\t b-- \t\t | %d \n "           , b );

	a += 5;
	printf( "\t a+=5 \t\t | %d \n "          , a );

	s *= 5;
	printf( "\t s*=5 \t\t | %.2f \n "        , s );

	printf( "\n SCRIPT DONE \n" );
	return 0;

}

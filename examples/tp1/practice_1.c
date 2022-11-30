#include <stdio.h>

void main(){
	int 	a = 3, b = 2, c = 1, d, e, resta;
	float 	m = 2.5, n = 5.4, r, s;

	d 	= m;
	printf( "1)  %i\n", d 		  	);

	d 	= n;
	printf( "2)  %i\n", d 		  	);

	e 	= 3.7;
	printf( "3)  %i\n", e 		  	);

	d 	= a;
	printf( "4)  %i\n", d 		  	);

	d 	= a + b;
	printf( "5)  %i\n", d 		  	);

	d 	= a / b;
	printf( "6)  %i\n", d 		  	);

	d 	= a % d;
	printf( "7)  %i\n", d 		  	);

	d 	= a % 2;
	printf( "8)  %i\n", d 	          	);

	e 	= b / c;
	printf( "9)  %i\n", e 	          	);

	e 	= c / b;
	printf( "10) %i\n", e 		  	);

	r 	= a + b;
	printf( "11) %f\n", r 		  	);

	r 	= a / b;
	printf( "12) %f\n", r 	          	);

	r 	= a / 2;
	printf( "13) %f\n", r 		  	);

	r       = a / 2.0;
	printf( "14) %f\n", r 		  	);

	s 	= m + n;
	printf( "15) %f\n", s 	          	);

	s 	= 3 + 4 - 1;
	printf( "16) %f\n", s 		  	);

	s 	= 3.0 + 4;
	printf( "17) %f\n", s 		  	);

	printf( "18) %i\n", resta = 0 - 1 	);

	a 	= m;
	printf( "19) %f\n", a 		  	);

	a 	= m / 2;
	printf( "20) %f\n", a 	          	);

	a 	= m / 2.0;
	printf( "21) %f\n", a 		  	);

	a 	= 3.0 + 4;
	printf( "22) %f\n", a 		  	);

	printf( "23) %i\n", resta = 0 - 1 	);

	r 	= a + 1;
	printf( "24) %f\n", r 		  	);

	r 	= a + 1.0;
	printf( "25) %f\n", r 		  	);

	a++;
	printf( "26) %f\n", a 		  	);

	r++;
	printf( "27) %f\n", r 		  	);

	b--;
	printf( "28) %i\n", b 		  	);

	a += 5;
	printf( "29) %f\n", a 		  	);

	s *= 5;
	printf( "30) %f\n", s 		  	);

	printf(	"Varialbe a Salida %i\n", a	);
	printf( "Varialbe b Salida %i\n", b     );
	printf( "Varialbe c Salida %i\n", c     );
	printf( "Varialbe d Salida %i\n", d     );
	printf( "Varialbe m Salida %f\n", m     );
	printf( "Varialbe n Salida %f\n", n     );
	printf( "Varialbe r Salida %f\n", r     );
	printf( "Varialbe s Salida %f\n", s     );

}

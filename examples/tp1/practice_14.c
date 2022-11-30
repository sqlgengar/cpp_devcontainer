#include <stdio.h>
#include <math.h>
#define leg_1 5
#define leg_2 6

int main (){

        printf( "the hypotenuse of the triangle is: %.2lfcm \n" ,
              pow( ( ( leg_1 * leg_1 ) + ( leg_2 * leg_2 ) ), 0.5 ) );

        return 0;
}	

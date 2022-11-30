#include<stdio.h>

int sub_r( int, int );
int div_r( int, int );

int main(){

    int dividend_number     = 0,
        dividing_number     = 0,
        remainder_result    = 0,
        quotient_result     = 0;

    printf( "Enter the dividend: \n" );
    scanf( " %d", &dividend_number );

    printf( "Enter the dividing: \n" );
    scanf( " %d", &dividing_number );

    remainder_result    = sub_r( dividend_number, dividing_number );
    quotient_result     = div_r( dividend_number, dividing_number );

    printf( "The remainder of operation is: %d \n", remainder_result );
    printf( "The quotient of operation is:  %d \n", quotient_result );

    return 0;

}

int sub_r( int dved_num , int dvin_num ){

    if( dved_num >= dvin_num ){

        return( sub_r( dved_num - dvin_num, dvin_num ) );

    }
    else{

        return dved_num;

    }

}

int div_r( int dved_num , int dvin_num ){

    if( dved_num < dvin_num ){

        return 0;        

    }
    else{
        
        return(  1 + sub_r( dved_num - dvin_num, dvin_num ) ); 

    }
    
}
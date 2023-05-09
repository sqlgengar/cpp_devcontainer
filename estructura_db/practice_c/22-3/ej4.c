/*
    Ejercicios de punteros:
    Realizar lo que se indica:
    1-  declarar las variables enteras a y b asignar 10 a 'a' y 20 a 'b'
    2-  declarar p y q como punteros a int
    3-  asignar a p las direccion de a
    4-  emitir el valor de a y su direccion
    5-  emitir la direccion contenida en p, el valor contenido en la dirreccion contenida en p, y la direccion de p
    6-  asigar a q la direccion de a
    7-  emitir la direccion contenida en q, el valor contenido en la direccion contenida en q y la direccion de q
    8-  sumarle 1 a la variable a usando el puntero p
    9-  volver a ejecutar 5 y 7
    10- copiar y ejecutar estas lineas:
        if( p==q ) printf( "P y Q contienen el mismo valor \n" );
        else printf( "P y Q contienen distinto valor \n" );

        if( (*p)==(*q) ) printf( "Los contenidos apuntados desde P y Q son iguales \n" );
        else printf( "Los contenidos apuntados desde P y Q son distintos \n" ); 
    11- asignar a q la dereccion de b
    12- modificar b mediante q que valga 11
    13- ejecutar de nuevo 10
    14- ejecutar de nuevo 5 y 7
*/

#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int *p;
    int *q;

    p = &a;

    printf( "%d %X \n", a, &a );

    printf( "%X %d %X \n", p, *p, &p );

    q = &a;

    printf( "%X %d %X \n", q, *q, &q );

    (*p)++;

    printf( "%X %d %X \n", p, *p, &p );
    printf( "%X %d %X \n", q, *q, &q );

    if( p==q ) printf( "P y Q contienen el mismo valor \n" );
    else printf( "P y Q contienen distinto valor \n" );

    if( (*p)==(*q) ) printf( "Los contenidos apuntados desde P y Q son iguales \n" );
    else printf( "Los contenidos apuntados desde P y Q son distintos \n" ); 

    q = &b;

    (*q) = 11;

    if( p==q ) printf( "P y Q contienen el mismo valor \n" );
    else printf( "P y Q contienen distinto valor \n" );
    if( (*p)==(*q) ) printf( "Los contenidos apuntados desde P y Q son iguales \n" );
    else printf( "Los contenidos apuntados desde P y Q son distintos \n" );

    printf( "%X %d %X \n", p, *p, &p );
    printf( "%X %d %X \n", q, *q, &q );

    return 0;
}
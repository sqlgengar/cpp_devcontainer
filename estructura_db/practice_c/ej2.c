//ejercicio 2
/*  a).Realizar las funciones mostrar
    b).Ordenar el vector por nombre de rubro en forma alfabetica
    c).Mostrar el vector ordenado
    d).Mostrar eñ rubro con un aumento del 20% en el precio de mayor a menor
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 5

typedef struct
{
    int cod_rubro;
    char nom_rub[25];
    float precio;
}registro;

void Mostrar(registro[m]);
void Ordenar(registro[m]);
void aumento_rubro(registro[m],float a [m]);

int main (){

registro rubro[m]={{1,"automotores",15.25},
                {2,"oficinas",12.46},
                {3,"enseñanza",8.34},
                {4,"servicios",10.54},
                {5,"profesionales",14.80}};

    //Mostrar(rubro);
    Ordenar(rubro);

    aumento_rubro(rubro,rubro.precio[m]);

return 0;
}

void Mostrar(registro rubro[m]){
int i;

    for(i=0;i<m;i++){
        printf("\t %d \n", rubro[i].cod_rubro);
        printf("\t %s \n", rubro[i].nom_rub);
        printf("\t %.2f \n", rubro[i].precio);
    }

}

void Ordenar(registro rubro[m]){
    int i=0;
    registro aux;
    while(i<4){
    if (strcmp(rubro[i].nom_rub, rubro[i+1].nom_rub) > 0){
        aux = rubro[i];
        rubro[i] = rubro[i+1];
        rubro[i+1]= aux;
    }
    i++;
    }
    Mostrar(rubro);
}

void aumento_rubro(registro rubro [m],float a [m]){
 int i;
 registro aux;
 while(i<4){
    if (a[i]<a[i+1]){
        aux = rubro[i];
        rubro[i] = rubro[i+1];
        rubro[i+1]= aux;
    }
    i++;
    }
    Mostrar(rubro);
}


#include <stdio.h>
#include <string.h>

void mostrarVotos(FILE *);
void pausa(void);
void cargarVotos(FILE *);

typedef struct
{
    int cod_zona;
    int num_lista;
    int votos;
} registro;

int main()
{
    FILE *binario;
    char v[10] = "votos.dat";
    // if ((binario = fopen(v, "rb+")) == NULL)
    // esto esta comentado para que cuando ejecuten no acumule y solo guarde lo ingresado en ese momento
    binario = fopen(v, "wb+");
    cargarVotos(binario);
    mostrarVotos(binario);
    fclose(binario);
    return 0;
}

void pausa(void)
{
    printf("\n\nPresione Enter para continuar...\n\n");
    fflush(stdin);
    getchar();
}

void cargarVotos(FILE *x)
{
    int numlista, codZona, flag; // numlista seria el numero de Lista y codZona el codigo de zona
    registro r; // este es el registro r donde se guardara lo cargado por teclado
    // COMPLETAR LA CARGA DE VOTOS
}

void mostrarVotos(FILE *x)
{
    int totalVotos[3] = {0}; // acumula la cantidad de votos por lista
    int totalZonas[5] = {0}; // Acumula el total de votos por zona
    int votosTotales = 0; // acumula el total de votos en general
    char nom_lista[][40] = {"Juan Luis Manzur", "Beatriz Elias de Perez", "Ricardo Argentino Bussi"};
    char nom_zona[][40] = {"Aguilares", "Bella Vista", "Famailla", "Graneros", "La Cocha"};
    float porcentaje;
    registro r;

    rewind(x);
    // fread(&r, sizeof(r), 1, x); // INSTRUCCION PARA LEER ARCHIVO
   // COMPLETAR EL MOSTRAR
}

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include<math.h>

void mostrar_binario(FILE *);
void mostrar_mensaje(FILE *);
void Convierte_a_Letra(char[]);
int error(char *);
void pausa(void);

int main(){
    FILE *archivo;
    char nom1[80] = "textoBinario.txt", cad[81]; // nombre físico del archivo
    system("cls");
    if ((archivo = fopen(nom1, "r")) == NULL)
        exit(error(nom1)); // crea el archivo para escritura y lectura;
    printf("\n El archivo %s se ha abierto satisfactoriamente", nom1);
    printf("\n Presione una tecla para visualizar el contenido del archivo:%s\n\n", nom1);
    pausa();
    system("cls");
    rewind(archivo);
    printf("\n El contenido del archivo %s es:\n\n", nom1);
    mostrar_binario(archivo);
    pausa();
    rewind(archivo);
    printf("\nMOSTRAMOS EL MENSAJE\n\n");
    mostrar_mensaje(archivo);
    printf("\n\n");
    pausa();
    fclose(archivo);
    return (0);
}

void mostrar_binario( FILE *x )
{
    char line[81];

    while( fgets( line, sizeof(line), x ) != NULL )
    {
        printf( "%s", line );
    }
}

void mostrar_mensaje( FILE *x )
{
    char line[81];
    int temp_max_chars = 0;

    while( fgets( line, sizeof(line), x ) != NULL )
    {
        temp_max_chars = strcspn( line, "\n" );
        line[ temp_max_chars ] = '\0';
        Convierte_a_Letra( line );
    }
}

void Convierte_a_Letra(char x[])
{
    char c = strtol( x, 0, 2 );
    printf( "%c", c );
}

int error(char *x){
    fprintf(stderr, "No se pudo abrir el archivo %s", x);
    return (1);
}

void pausa(){
    printf("\n>>> Presione Enter para continuar...\n");
    fflush(stdin);
    while (getchar() != '\n');
}
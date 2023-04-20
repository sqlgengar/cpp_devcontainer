#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<ctype.h>
#include <math.h>
#include<conio.h>


#define MAX_DESCRIPCION 80
#define p printf
#define s scanf

// Definici�n de la estructura Producto
typedef struct
{
    int codigo;
    char descripcion[MAX_DESCRIPCION];
    float precio;
    int signal;
} Producto;

int verifica(FILE *, char *);
void listarProductos(FILE *, char *);
void tecla(void);
void agregarProducto(FILE *);
void eliminarProducto(FILE *);
void modificarProducto(FILE *);
void EliminaLogiamente(FILE *);
int error(char *);
void linea(int);
int menprin(void);

int main()
{
    int op, flag;
    system("color 9f");
    FILE *archivo;
    char *nomarch = "productos.dat";

    do
    {
        op = menprin();
        switch (op)
        {
        case 1:
        {
            system("cls");
            flag=verifica(archivo,nomarch);
            if (flag == 0)
            {
                p("\n EL ARCHIVO %s NO EXISTE SU APERTURA SERa DE ESCRITURA!! ", nomarch);
                archivo = fopen(nomarch, "wb+");
            }
            else
            {
                p("\n EL ARCHIVO %s EXISTE SU APERTURA SER%c DE LECTURA-ESCRITURA!! ", nomarch, 181);
                archivo = fopen(nomarch, "rb+");
            }
            agregarProducto(archivo);
            fclose(archivo);
            break;
        }
        case 2:
           {
               // Elimina ficamente el registro del archivo
               system("cls");
                flag = verifica(archivo, nomarch);
                if (flag == 0)
                {
                    p("\n NO SE PUEDEN PROCESAR LOS PRODUCTOS PORQUE EL ARCHIVO %s NO EXISTE!!!!", nomarch);
                    getch();
                }
                else
                {
                    archivo = fopen(nomarch, "rb+");
                    eliminarProductoFisicamente(archivo);
                    fclose(archivo);
                }
           }
            break;

        case 3:
        {
            // modifica el registro en el archivo
            system("cls");
            flag = verifica(archivo, nomarch);
            if (flag == 0)
            {
                p("\n NO SE PUEDEN PROCESAR LOS PRODUCTOS PORQUE EL ARCHIVO %s NO EXISTE!!!!", nomarch);
                getch();
            }
            else
            {
                archivo = fopen(nomarch, "rb+");
                modificarProducto(archivo);
                fclose(archivo);
            }
            break;
        }
        case 4:
        {
            // listamos los productos del archivo
            system("cls");
            flag = verifica(archivo, nomarch);
            if (flag == 0)
            {
                p("\n NO SE PUEDEN PROCESAR LOS PRODUCTOS PORQUE EL ARCHIVO %s NO EXISTE!!!!", nomarch);
                getch();
            }
            else
            {
                archivo = fopen(nomarch, "rb+");
                listarProductos(archivo, "PRODUCTOS");
                fclose(archivo);
            }
        }
        case 5:
        {
            // Elimina Logicamente un registro del archivo
            system("cls");
            flag = verifica(archivo, nomarch);
            if (flag == 0)
            {
                p("\n NO SE PUEDEN PROCESAR LOS PRODUCTOS PORQUE EL ARCHIVO %s NO EXISTE!!!!", nomarch);
                getch();
            }
            else
            {
                archivo = fopen(nomarch, "rb+");
                EliminaLogiamente(archivo);
                fclose(archivo);
            }
        }
        }
    } while (op < 6);
    p("\n\n \t\t***** PRESIONE UNA TECLA LA SALIR DEL PROGRAMA!!! *****");
    system("cls");
    return 0;
}
// Funcion para agregar un nuevo producto al archivo
void agregarProducto(FILE *x)
{

}

// Funcion para eliminar un producto del archivo fisicamente
void eliminarProducto(FILE *archivo)
{

}

// Funcion para modificar un producto del archivo
void modificarProducto(FILE *x)
{

}

// Funcion para Eliminar logicamente  un producto del archivo
void EliminaLogiamente(FILE *x)
{

}

// Funci�n para listar todos los productos del archivo
void listarProductos(FILE *x, char *msj)
{

}

int error(char *x)
{
    fprintf(stderr, "no se puede abrir el archivo %s", x);
    return (1);
}

void tecla(void)
{
    p("\n\nPRESIONE CUALQUIER TECLA PARA VOLVER AL MENU PRINCIPAL!!!");
    getch();
}
void linea(int x)
{
    int i;
    // p("\n");
    for (i = 1; i < x; i++)
        p("*");
    p("\n");
}

int menprin(void)
{
    int op;
    do
    {
        system("cls");
        printf("\n\t\t\t\t*****MENU PRINCIPAL DE PRODUCTOS *****\n\n");
        p("\n\n\t\t\t \t - Agregar producto                 \t <1>\n");
        p("\n\n\t\t\t \t - Eliminar Fisicamente un producto \t <2>\n");
        p("\n\n\t\t\t \t - Modificar producto               \t <3>\n");
        p("\n\n\t\t\t \t - Listar productos                 \t <4>\n");
        p("\n\n\t\t\t \t - Eliminar Logicamente             \t <5>\n");
        p("\n\n\t\t\t \t - Salir                            \t <6>\n");
        p("\n\n\n\t\t\t INGRESE OPCION: ");
        s("%d", &op);
    } while (op < 1 || op > 6);
    return (op);
} // CIERRA MENU

int verifica(FILE *x, char *y)
{
    int v;
    if ((x = fopen(y, "rb+")) == NULL)
        v = 0;
    else
        v = 1;
    return v;
}

// Función para eliminar un producto del archivo
void eliminarProductoFisicamente(FILE *archivo)
{

}

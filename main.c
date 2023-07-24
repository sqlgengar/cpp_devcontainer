#include <stdio.h>

#define MAX_CHARS_NAME 50
#define MAX_CHARS_ADDRESS 100

typedef struct
{
    char name[MAX_CHARS_NAME];
    char address[MAX_CHARS_ADDRESS];
    char gender[9];
    float credit;
} Customers;

void init();
/*FILE* open_file( char* );*/

int main()
{
    init();
    return 0;
}

void init()
{
    char* path_customers =          "/workspaces/cpp_devcontainer/programacion_1/m8/_files/clientes.txt";
    char* path_male_customers =     "/workspaces/cpp_devcontainer/programacion_1/m8/_files/varon.txt";
    char* path_female_customers =   "/workspaces/cpp_devcontainer/programacion_1/m8/_files/mujer.txt";
}
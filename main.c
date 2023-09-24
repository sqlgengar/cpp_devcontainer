#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data {
    int number;
    struct data* next;
} Node;

typedef struct {
    Node* head;
} List;

void execute();
List* show_menu(List*);
List* resolve_option(int, List*);
List* create_list(bool);
List* insert(List*, int, bool);
bool is_empty(List*, bool);
List* show_list(List*);
List* intersection(List*, List*);

int main() {
    execute();
    return 0;
}

void execute() {
    List* list1 = NULL;
    List* list2 = NULL;

    while (true) {
        list1 = show_menu(list1);
        list2 = show_menu(list2);
    }
}

List* show_menu(List* list) {
    int temp_option = -1;

    printf("\n\n");
    printf("Ingrese el numero de opcion:      \n");
    printf("Crear lista:                   (1)\n");
    printf("Insertar elemento en la lista: (2)\n");
    printf("Mostrar lista:                 (3)\n");
    printf("Calcular intersección:         (4)\n");
    printf("Salir:                         (5)\n");
    printf("\n\n");

    scanf(" %d", &temp_option);
    fflush(stdin);

    return resolve_option(temp_option, list);
}

List* resolve_option(int option, List* list) {
    int input_user_value = NULL;
    bool verbose = true;

    switch (option) {
        case 1:
            list = create_list(verbose);
            break;
        case 2:
            printf("Ingrese valor a insertar: ");
            scanf(" %d", &input_user_value);
            list = insert(list, input_user_value, verbose);
            break;
        case 3:
            list = show_list(list);
            break;
        case 4:
            // Calculate intersection
            if (list != NULL) {
                List* other_list = create_list(verbose);
                printf("Ingrese valores para la segunda lista. Finalice con -1:\n");
                int value;
                while (true) {
                    scanf(" %d", &value);
                    if (value == -1) break;
                    other_list = insert(other_list, value, verbose);
                }
                list = intersection(list, other_list);
                free(other_list);
            } else {
                printf("La primera lista está vacía. Crea una lista primero.\n");
            }
            break;
        case 5:
            exit(EXIT_SUCCESS);
            break;
    }

    return list;
}

List* create_list(bool is_verbose) {
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = NULL;

    if (is_verbose) printf("Se creó la lista %p\n", (void*)new_list);

    return new_list;
}

List* insert(List* list, int value, bool is_verbose) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->number = value;
    new_node->next = list->head;
    list->head = new_node;

    if (is_verbose) printf("Se insertó el valor %d en la lista\n", value);

    return list;
}

bool is_empty(List* list, bool is_verbose) {
    if (list->head != NULL) return false;

    if (is_verbose) printf("La lista está vacía\n");
    return true;
}

List* show_list(List* list) {
    bool verbose = true;

    if (is_empty(list, verbose)) return list;

    Node* current = list->head;

    printf("Contenido de la lista:\n");

    while (current != NULL) {
        printf("%d\n", current->number);
        current = current->next;
    }

    return list;
}

List* intersection(List* list1, List* list2) {
    bool no_verbose = false;
    List* result = create_list(no_verbose);

    Node* current1 = list1->head;
    while (current1 != NULL) {
        int value = current1->number;
        Node* current2 = list2->head;
        while (current2 != NULL) {
            if (current2->number == value) {
                result = insert(result, value, no_verbose);
                break;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    printf("Intersección calculada y almacenada en una nueva lista.\n");

    return result;
}

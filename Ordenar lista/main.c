#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

void visitar(void* dato){
    printf("%d ", *((int*) dato));
}

int main() {
    GList* lista = glist_crear();

    int* a = malloc(sizeof(int));
    *a = 6;
    int* b = malloc(sizeof(int));
    *b = 5;
    int* c = malloc(sizeof(int));
    *c = 4;
    int* d = malloc(sizeof(int));
    *d = 3;
    int* e = malloc(sizeof(int));
    *e = 2;
    int* f = malloc(sizeof(int));
    *f = 1;
    int* g = malloc(sizeof(int));
    *g = 0;

    printf("ESTA VACIA: (0 no 1 si) %d\n", glist_vacia(lista));

    lista = glist_agregar_inicio(lista, a, sizeof(int));

    printf("ESTA VACIA: (0 no 1 si) %d\n", glist_vacia(lista));
    
    lista = glist_agregar_inicio(lista, b, sizeof(int));
    lista = glist_agregar_inicio(lista, c, sizeof(int));
    lista = glist_agregar_final(lista, d, sizeof(int));
    lista = glist_agregar_final(lista, e, sizeof(int));
    lista = glist_agregar_final(lista, f, sizeof(int));

    // lista = glist_insertar(lista, 1, g, sizeof(int));
    // lista = glist_insertar(lista, 100, g, sizeof(int));
    lista = glist_insertar(lista, 4, g, sizeof(int));

    glist_recorrer(lista, visitar);

    glist_destruir(lista);

    return 0;
}
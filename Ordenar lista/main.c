#include "listas.h"
#include "ordenamientos.h"
#include <stdio.h>
#include <stdlib.h>

void visitar(void* dato){
    printf("%d ", *((int*) dato));
}

int menor_int(void* a, void* b) {
    return (*((int*) a)<*((int*) b));
}

int main() {
    GList* lista = glist_crear();

    int* a = malloc(sizeof(int));
    *a = 5;
    int* b = malloc(sizeof(int));
    *b = 1;
    int* c = malloc(sizeof(int));
    *c = 3;
    int* d = malloc(sizeof(int));
    *d = 4;
    int* e = malloc(sizeof(int));
    *e = 6;
    int* f = malloc(sizeof(int));
    *f = 2;

    lista = glist_agregar_inicio(lista, a, sizeof(int));
    lista = glist_agregar_inicio(lista, b, sizeof(int));
    lista = glist_agregar_inicio(lista, c, sizeof(int));
    lista = glist_agregar_inicio(lista, d, sizeof(int));
    lista = glist_agregar_inicio(lista, e, sizeof(int));
    lista = glist_agregar_inicio(lista, f, sizeof(int));

    // lista = glist_insertar(lista, 2, b, sizeof(int));

    glist_recorrer(lista, visitar);
    puts("");

    selection_sort(lista, menor_int);

    glist_recorrer(lista, visitar);

    glist_destruir(lista);

    return 0;
}
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

void* copia(void* dato){
    void* dato_copia = malloc(sizeof(int));
    *((int*)dato_copia) = *((int*)dato);
    return dato_copia;
}

void destruir(void* dato){
    free(dato);
}

int main() {
    GList* lista = glist_crear();

    int a = 5;
    lista = glist_agregar_inicio(lista, &a, copia);
    a = 1;
    lista = glist_agregar_inicio(lista, &a, copia);
    a = 3;
    lista = glist_agregar_inicio(lista, &a, copia);
    a = 4;
    lista = glist_agregar_inicio(lista, &a, copia);
    a = 6;
    lista = glist_agregar_inicio(lista, &a, copia);
    a = 2;
    lista = glist_agregar_inicio(lista, &a, copia);
    // lista = glist_insertar(lista, 2, b, sizeof(int));

    glist_recorrer(lista, visitar);
    puts("");

    selection_sort(lista, menor_int);

    glist_recorrer(lista, visitar);

    glist_destruir(lista, destruir);

    return 0;
}
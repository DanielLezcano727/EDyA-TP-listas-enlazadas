#ifndef __ORDENAMIENTOS_H__
#define __ORDENAMIENTOS_H__

#include <stddef.h>
#include "listas.h"

typedef int (*FuncionComparadora)(void *dato1, void *dato2);

void swap_nodes(GNodo *nodo1, GNodo *nodo2);

GNodo *busqueda_por_condicion(GNodo *nodo, FuncionComparadora compara);

void merge(GNodo* lista1, int cant_lista1, GNodo* lista2, int cant_lista2, GNodo* final_lista, FuncionComparadora compara);
void selection_sort(GList *lista, FuncionComparadora compara);
void insertion_sort(GList *lista, FuncionComparadora compara);
void mergesort(GList* lista, FuncionComparadora compara);

#endif

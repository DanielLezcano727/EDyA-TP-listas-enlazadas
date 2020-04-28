#ifndef __ORDENAMIENTOS_H__
#define __ORDENAMIENTOS_H__

#include <stddef.h>
#include "listas.h"

typedef int (*FuncionComparadora)(void *dato1, void *dato2);

void swap_nodes(GNodo *nodo1, GNodo *nodo2);

GNodo *busqueda_por_condicion(GNodo *nodo, FuncionComparadora compara);

void merge(GNodo* lista1, GNodo* final_lista1, GNodo* lista2, GNodo* final_lista2, FuncionComparadora compara);
void selection_sort(GList *lista, FuncionComparadora compara);
void insertion_sort(GList *lista, FuncionComparadora compara);
void mergesort(GList* lista, FuncionComparadora compara);

#endif

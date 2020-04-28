#ifndef __ORDENAMIENTOS_H__
#define __ORDENAMIENTOS_H__

#include <stddef.h>
#include "listas.h"

typedef int (*FuncionComparadora) (void *dato1, void *dato2);

GNodo *busqueda_por_condicion(GNodo *nodo, FuncionComparadora compara);

void merge(GNodo *lista1, int cantLista1, GNodo *lista2, int cantLista2, GNodo *finalLista, FuncionComparadora compara);
void merge_sort(GNodo *inicio, GNodo *fin, int largo, FuncionComparadora compara);
void selection_sort(GList *lista, FuncionComparadora compara);
void insertion_sort(GList *lista, FuncionComparadora compara);
void mergesort(GList *lista, FuncionComparadora compara);

#endif

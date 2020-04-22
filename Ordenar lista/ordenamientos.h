#ifndef __ORDENAMIENTOS_H__
#define __ORDENAMIENTOS_H__

#include <stddef.h>
#include "listas.h"

typedef int (*FuncionComparadora) (void*, void*);

void swap_nodes(GNodo*, GNodo*);
GNodo* busqueda_por_condicion(GNodo*, FuncionComparadora);
void merge(GNodo*, GNodo*, GNodo*, FuncionComparadora);
void shift_nodos(GNodo*, GNodo*);

void selection_sort(GList*, FuncionComparadora);
void insertion_sort(GList*, FuncionComparadora);
void merge_sort(GNodo*, GNodo*, int, FuncionComparadora);
void mergesort(GList*, FuncionComparadora);

#endif 
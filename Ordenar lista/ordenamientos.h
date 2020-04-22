#ifndef __ORDENAMIENTOS_H__
#define __ORDENAMIENTOS_H__

#include <stddef.h>
#include "listas.h"

typedef int (*FuncionComparadora) (void*, void*);

void swap_nodes(GNodo*, GNodo*);

GNodo* busqueda_por_condicion(GNodo*, FuncionComparadora);

void selection_sort(GList*, FuncionComparadora);

#endif 
#ifndef __ORDENAMIENTOS_H__
#define __ORDENAMIENTOS_H__

#include <stddef.h>
#include "listas.h"

typedef int (*FuncionComparadora) (void*, void*);

void swap(GNodo*, GNodo*);

GNodo* menor(GNodo*, FuncionComparadora);

GList* selection_sort(GList*, FuncionComparadora);

#endif 
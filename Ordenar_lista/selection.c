#include "ordenamientos.h"
#include <stdlib.h>

GNodo *busqueda_por_condicion(GNodo *nodos, FuncionComparadora compara) {
  GNodo *min = nodos;
  GNodo *temp = nodos;

  while (temp != NULL) {
    if (compara(temp->dato, min->dato) < 0)
      min = temp;
    temp = temp->sig;
  }

  return min;
}

void selection_sort(GList *lista, FuncionComparadora compara) {
  if (lista != NULL) {
    GNodo *temp = lista->inicio;
    while (temp != lista->fin) {
      swap_data(temp, busqueda_por_condicion(temp, compara));
      temp = temp->sig;
    }
  }
}

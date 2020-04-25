#include "ordenamientos.h"
#include <stdlib.h>

void swap_nodes(GNodo* nodoI, GNodo* nodoX) {
  void* aux = nodoI->dato;
  nodoI->dato = nodoX->dato;
  nodoX->dato = aux;
}

GNodo* busqueda_por_condicion(GNodo* nodos, FuncionComparadora compara) {
  GNodo* min = nodos;
  GNodo* temp = nodos;

  while(temp != NULL) {
    if(compara(temp->dato, min->dato) < 0) { // COMPARA: true si el primero > segundo
      min = temp;
    }
    temp = temp->sig;
  }

  return min;
}

void selection_sort(GList* lista, FuncionComparadora compara) {
  if(lista != NULL) {
    GNodo* temp = lista->inicio;

    while(temp != lista->fin) {
      swap_nodes(temp, busqueda_por_condicion(temp, compara));
      temp = temp->sig;
    }
  }
}
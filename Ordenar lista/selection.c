#include "ordenamientos.h"
#include <stdlib.h>

void swap(GNodo* nodoI, GNodo* nodoX) {
  void* aux = nodoI->dato;
  nodoI->dato = nodoX->dato;
  nodoX->dato = aux;
}

GNodo* busqueda_por_condicion(GNodo* nodos, FuncionComparadora compara) {
  GNodo* min = nodos;

  if(nodos != NULL) {
    GNodo* temp = nodos;

    while(temp != NULL) {
      if(compara(min->dato, temp->dato)) {
        min = temp;
      }
      temp = temp->sig;
    }
  }
  return min;
}

void selection_sort(GList* lista, FuncionComparadora compara) {
  if(lista != NULL && lista->inicio != NULL) {
    GNodo* temp = lista->inicio;

    while(temp != lista->fin) {
      swap(temp, busqueda_por_condicion(temp, compara));
      temp = temp->sig;
    }
  }
}
#include "ordenamientos.h"
#include <stdlib.h>

void swap(GNodo* prevI, GNodo* prevX, GList* lista) {
  if(prevX != NULL) {
    if(prevI == NULL) {
      GNodo* nodoX = prevX->sig;
      GNodo* nodoI = lista->inicio;
      GNodo* aux = nodoI->sig;

      prevX->sig = nodoI;
      lista->inicio = nodoX;
      nodoI->sig = nodoX->sig;
      nodoX->sig = aux;
    }
  }
}

GNodo* menor(GNodo* nodos, FuncionComparadora compara) {
  GNodo* min = nodos;
  GNodo* prevmin = NULL;

  if(nodos != NULL) {
    GNodo* temp = nodos;
    GNodo* prevtemp = NULL;

    while(temp != NULL) {
      if(compara(min->dato, temp->dato)) {
        min = temp;
        prevmin = prevtemp;
      }
      prevtemp = temp;
      temp = temp->sig;
    }
  }

  return prevmin;
}

// cambiar glist_destruir
// cambiar glist_agregar_
// cambiar swap para que cambie nodos


GList* selection_sort(GList* lista, FuncionComparadora compara) {
  if(lista != NULL && lista->inicio != NULL) {
    GNodo* temp = lista->inicio;
    GNodo* prevtemp = NULL;

    while(temp != lista->fin) {
      swap(prevtemp, menor(temp, compara), lista);
      prevtemp = temp;
      temp = temp->sig;
    }
  }

  return lista;
}


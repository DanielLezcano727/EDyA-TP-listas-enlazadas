#include "ordenamientos.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

GNodo* merge(GNodo *lista1, int cantLista1, GNodo *lista2, int cantLista2, GNodo *finalLista, FuncionComparadora compara) {
  GNodo *auxLista1 = lista1;
  GNodo *auxLista2 = lista2;
  GNodo *listaOrdenada = auxLista1;
  int contadorLista1 = 0, contadorLista2 = 0;

  if (compara(auxLista1->dato, auxLista2->dato) < 0) {
    auxLista1 = auxLista1->sig;
    contadorLista1++;
  } else {
    swap_data(auxLista1, auxLista2);
    GNodo *aux = auxLista1->sig;
    auxLista1 = auxLista2;
    auxLista2 = auxLista2->sig;
    auxLista1->sig = aux;
    contadorLista2++;
  }

  while (contadorLista1 < cantLista1 && contadorLista2 < cantLista2) {
    if (compara(auxLista1->dato, auxLista2->dato) <= 0) {
      listaOrdenada->sig = auxLista1;
      auxLista1 = auxLista1->sig;
      contadorLista1++;
    } else {
      listaOrdenada->sig = auxLista2;
      auxLista2 = auxLista2->sig;
      contadorLista2++;
    }
    listaOrdenada = listaOrdenada->sig;
  }

  if (contadorLista2 < cantLista2)
    listaOrdenada->sig = auxLista2;

  if (contadorLista1 < cantLista1) {
    for (listaOrdenada->sig = auxLista1; contadorLista1 < cantLista1; contadorLista1++)
      listaOrdenada = listaOrdenada->sig;
    listaOrdenada->sig = finalLista;
  }
  return listaOrdenada;
}

GNodo* dividir_lista(GNodo *inicio, GNodo *fin, int largo, FuncionComparadora compara) {
  if (largo > 1) {
    int medio = largo / 2;
    GNodo *nodo_medio = glist_devolver_nodo(inicio, medio + 1);
    dividir_lista(inicio, nodo_medio, medio, compara);
    dividir_lista(nodo_medio, fin, largo - medio, compara);
    return merge(inicio, medio, nodo_medio, largo - medio, fin, compara);
  }
  return NULL;
}

void merge_sort(GList *lista, FuncionComparadora compara) {
  if (lista != NULL && lista->inicio != lista->fin)
    lista->fin = dividir_lista(lista->inicio, NULL, glist_largo(lista), compara);
}

#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

GList *glist_crear() {
  GList *lista = malloc(sizeof(GList));
  lista->inicio = NULL;
  lista->fin = NULL;
  return lista;
}

void glist_destruir(GList *lista, Destruir d) {
  if (lista != NULL) {
    GNodo *temp;

    while (lista->inicio != NULL) {
      temp = lista->inicio;
      lista->inicio = lista->inicio->sig;
      d(temp->dato);
      free(temp);
    }
    free(lista);
  }
}

GList *glist_agregar_final(GList *lista, void *dato, Copiar cop) {
  if (lista != NULL) {
    GNodo *nuevo = malloc(sizeof(GNodo));
    nuevo->dato = cop(dato);
    nuevo->sig = NULL;

    if (lista->inicio == NULL)
      lista->inicio = nuevo;
    else
      lista->fin->sig = nuevo;

    lista->fin = nuevo;
  }

  return lista;
}

void glist_escribir_archivo(GList *lista, FuncionEscritura escribir, char *nombreSalida) {
  FILE *fSalida = fopen(nombreSalida, "w");
  for (GNodo *aux = lista->inicio; aux != NULL; aux = aux->sig)
    escribir(aux->dato, fSalida);
  fclose(fSalida);
}

int glist_largo(GList* lista){
  int largo = 0;
  for(GNodo *aux=lista->inicio; aux!=NULL;aux=aux->sig, largo++);
  return largo;
}

GNodo* glist_devolver_nodo (GNodo *inicio, int pos) {
  for (int i = 1; i < pos; i++, inicio = inicio->sig);
  return inicio;
}

void glist_destruir_sin_datos(GList* lista){
  if (lista != NULL) {
    GNodo *temp;

    while (lista->inicio != NULL) {
      temp = lista->inicio;
      lista->inicio = lista->inicio->sig;
      free(temp);
    }
    free(lista);
  }
}

void* no_copia(void* dato){
  return dato;
}

GList* glist_copia (GList* lista_original) {
  GList* copia = NULL;
  if(lista_original != NULL){
    copia = glist_crear();
    for (GNodo* aux=lista_original->inicio;aux!=NULL;aux=aux->sig)
      copia = glist_agregar_final(copia, aux->dato, no_copia);
  }
  return copia;
}

void swap_data(GNodo *nodo1, GNodo *nodo2) {
  void *aux = nodo1->dato;
  nodo1->dato = nodo2->dato;
  nodo2->dato = aux;
}
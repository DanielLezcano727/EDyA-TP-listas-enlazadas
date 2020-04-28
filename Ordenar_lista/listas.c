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

int glist_vacia(GList *lista) {
  return lista == NULL || lista->inicio == NULL;
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

GList *glist_agregar_inicio(GList *lista, void *dato, Copiar cop) {
  if (lista != NULL) {
    GNodo *nuevo = malloc(sizeof(GNodo));
    nuevo->dato = cop(dato);

    nuevo->sig = lista->inicio;
    lista->inicio = nuevo;

    if (lista->fin == NULL)
      lista->fin = nuevo;
  }

  return lista;
}

GList *glist_insertar(GList *lista, int pos, void *dato, Copiar cop) {
  if (lista != NULL) {
    GNodo *nuevo = malloc(sizeof(GNodo));
    nuevo->dato = cop(dato);

    if (lista->inicio == NULL) {
      nuevo->sig = NULL;
      lista->inicio = nuevo;
      lista->fin = nuevo;
    } else if (pos <= 1) {
      nuevo->sig = lista->inicio;
      lista->inicio = nuevo;
    } else {

      GNodo *temp = lista->inicio;
      GNodo *temp2;
      for (int i = 1; i < pos && temp != NULL; i++) {
        temp2 = temp;
        temp = temp->sig;
      }

      nuevo->sig = temp;
      if (temp == NULL) {
        lista->fin->sig = nuevo;
        lista->fin = nuevo;
      } else 
        temp2->sig = nuevo;
    }
  }

  return lista;
}

void glist_recorrer(GList *lista, FuncionVisitante visit) {
  for (GNodo *aux = lista->inicio; aux != NULL; aux = aux->sig)
    visit(aux->dato);
}

void glist_escribir_archivo(GList *lista, FuncionEscritura escribir, char *nombreSalida) {
  FILE *fSalida = fopen(nombreSalida, "w");
  for (GNodo *aux = lista->inicio; aux != NULL; aux = aux->sig)
    escribir(aux->dato, fSalida);
  fclose(fSalida);
}

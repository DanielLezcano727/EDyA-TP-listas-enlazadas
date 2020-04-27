#ifndef __GLIST_H__
#define __GLIST_H__

#include <stddef.h>
#include <stdio.h>

typedef void (*FuncionVisitante)(void *visit);
typedef void (*FuncionEscritura)(void *escribir, FILE *archivo);
typedef void (*Destruir)(void *dato);
typedef void* (*Copiar)(void *dato);

typedef struct _GNodo {
  void *dato;
  struct _GNodo *sig;
} GNodo;

typedef struct _GList {
  GNodo *inicio;
  GNodo *fin;
} GList;

GList *glist_crear();

void glist_destruir(GList *lista, Destruir d);

int glist_vacia(GList *lista);

GList *glist_agregar_final(GList *lista, void *dato, Copiar cop);

GList *glist_agregar_inicio(GList *lista, void *dato, Copiar cop);

GList *glist_insertar(GList *lista, int pos, void *dato, Copiar cop);

void glist_recorrer(GList *lista, FuncionVisitante visit);

void glist_escribir_archivo(GList *lista, FuncionEscritura visit, char *nombreSalida);

#endif

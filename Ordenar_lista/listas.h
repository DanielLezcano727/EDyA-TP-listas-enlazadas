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

/**
 * Crea una lista general inicializada a NULL
*/
GList *glist_crear();

/**
 * Libera la memoria ocupada por una lista general y sus datos mediante una funcion especifica
*/
void glist_destruir(GList *lista, Destruir d);

/**
 * Agrega un dato al final de la lista general copiandolo mediante una funcion especifica
*/
GList *glist_agregar_final(GList *lista, void *dato, Copiar cop);

/**
 * Escribe el contenido de una lista general en un archivo de nombre dado
*/
void glist_escribir_archivo(GList *lista, FuncionEscritura visit, char *nombreSalida);

/**
 * Devuelve el largo de una lista general
*/
int glist_largo(GList* lista);

/**
 * Dado un nodo inicio y una posicion devuelve el nodo que esta en la posicion correspondiente
*/
GNodo* glist_devolver_nodo(GNodo *inicio, int pos);

/**
 * Libera la memoria ocupada por una lista general sin liberar la ocupada
 * por sus datos
*/
void glist_destruir_sin_datos(GList* lista);

/**
 * Crea una lista general copiando las referencias de otra lista
*/
GList* glist_copia(GList* lista);

/**
 * Dados dos nodos intercambia los datos de estos
*/
void swap_data(GNodo *nodo1, GNodo *nodo2);

#endif

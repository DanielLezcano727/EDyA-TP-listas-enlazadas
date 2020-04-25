#ifndef __GLIST_H__
#define __GLIST_H__

#include <stddef.h>
#include <stdio.h>

typedef void (*FuncionVisitante) (void*);
typedef void (*FuncionEscritura) (void*, FILE*);
typedef void (*Destruir) (void*);
typedef void* (*Copiar) (void*);

typedef struct _GNodo {
  void * dato ;
  struct _GNodo * sig;
} GNodo;

typedef struct _GList {
  GNodo *inicio;
  GNodo *fin;
}GList;

GList* glist_crear();

void glist_destruir(GList*, Destruir);

int glist_vacia(GList*);

GList* glist_agregar_final(GList*, void*, Copiar);

GList* glist_agregar_inicio(GList*, void*, Copiar);

GList* glist_insertar(GList*, int, void*, Copiar);

void glist_recorrer(GList*, FuncionVisitante);

void glist_escribir_archivo(GList* lista, FuncionEscritura visit, char* nombreSalida);

#endif /* __GLIST_H__ */
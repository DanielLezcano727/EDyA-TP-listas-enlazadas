#ifndef __GLIST_H__
#define __GLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (void*);
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

void glist_destruir(GList*);

int glist_vacia(GList*);

GList* glist_agregar_final(GList*, void*, size_t);

GList* glist_agregar_inicio(GList*, void*, size_t);

GList* glist_insertar(GList*, int, void*, size_t);

void glist_recorrer(GList*, FuncionVisitante);

#endif /* __GLIST_H__ */
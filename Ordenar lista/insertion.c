#include "ordenamientos.h"
#include <stdlib.h>

void insertion_sort(GList* lista, FuncionComparadora compara){
  if(lista != NULL && lista->inicio != NULL){
    
    GNodo *insertar = lista->inicio->sig;
    lista->inicio->sig = NULL;
    GNodo *anterior, *aux, *nodoInsertar;
    while(insertar!=NULL){
      anterior = NULL;
      for(GNodo *listaAux=lista->inicio;listaAux != NULL && compara(listaAux->dato, insertar->dato) < 0; listaAux=listaAux->sig)
        anterior = listaAux;

      nodoInsertar = insertar;
      insertar=insertar->sig;
      
      if(anterior==NULL){
        aux = lista->inicio;
        lista->inicio = nodoInsertar;
        nodoInsertar->sig = aux;
      }else{
        aux = anterior->sig;
        anterior->sig = nodoInsertar;
        nodoInsertar->sig = aux;
      }
    }
  }
}

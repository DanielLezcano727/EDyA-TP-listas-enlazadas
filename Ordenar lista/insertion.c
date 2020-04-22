#include "ordenamientos.h"
#include <stdlib.h>

void insertion_sort(GList* lista, FuncionComparadora compara){
  if(lista != NULL){
    for(GNodo *aux = lista->inicio;aux != NULL;aux=aux->sig)
      for(GNodo *aux2=lista->inicio;aux2 != aux;aux2=aux2->sig)
        if(compara(aux2->dato, aux->dato) <= 0){
          void* dato_aux = aux2->dato;
          aux2->dato = aux->dato;
          aux->dato = dato_aux;
        }
  }
}

#include "ordenamientos.h"
#include <stdlib.h>

void insertion_sort(GList* lista, FuncionComparadora compara){
  if(lista != NULL){
    for(GNodo *aux = lista->inicio;aux != NULL;aux=aux->sig)
      for(GNodo *aux2=lista->inicio;aux2 != aux;aux2=aux2->sig)
        if(compara(aux->dato, aux2->dato) < 0){
          swap_nodes(aux, aux2);
        }
  }
}

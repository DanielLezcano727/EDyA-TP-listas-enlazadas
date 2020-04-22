#include "ordenamientos.h"
#include <stdlib.h>
#include <stdio.h>

GNodo* merge(GNodo* lista1,GNodo* ult_lista1, GNodo* lista2, GNodo* ult_lista2, FuncionComparadora compara){
    GNodo* temp1 = lista1;
    GNodo* temp2 = lista2;
    GNodo* nodo_a_cambiar;


    if(compara(temp1->dato, temp2->dato)){
        nodo_a_cambiar = temp1;
        temp1=temp1->sig;
    }else{
        nodo_a_cambiar = temp2;
        temp2=temp2->sig;
    }

    while(temp1 != ult_lista1 && temp2 != ult_lista2){
        if(compara(temp1->dato, temp2->dato)){
            nodo_a_cambiar->sig = temp1;
            temp1 = temp1->sig;
        }else{
            nodo_a_cambiar->sig = temp2;
            temp2 = temp2->sig;
        }
    }

    while(temp1 != ult_lista1){
        nodo_a_cambiar->sig = temp1;
        temp1=temp1->sig;
    }

    while(temp2 != ult_lista2){
        nodo_a_cambiar->sig = temp2;
        temp2=temp2->sig;
    }
    
    return nodo_a_cambiar;
}

int largo_lista(GNodo* inicio){
    int largo = 0;
    for(GNodo* aux = inicio; aux != NULL;aux=aux->sig, largo++);
    return largo;
}

GNodo* devolver_nodo(GNodo* inicio, int pos){
    for(int i=0; i<pos;i++, inicio=inicio->sig);
    return inicio;
}

void merge_sort(GNodo* inicio, GNodo* fin, int largo, FuncionComparadora compara){
    if(largo > 1){
        int medio = largo/2;
        GNodo* nodo_medio = devolver_nodo(inicio, medio-1);
        merge_sort(inicio, nodo_medio, medio-1, compara);
        merge_sort(nodo_medio->sig, fin, medio, compara);
        inicio = merge(inicio, nodo_medio->sig, nodo_medio->sig, fin->sig, compara);
    }
}

void mergesort(GList* lista, FuncionComparadora compara){
    if(lista!=NULL && lista->inicio != lista->fin){
        merge_sort(lista->inicio, lista->fin, glist_largo(lista), compara);
    }
}
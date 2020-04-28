#include "ordenamientos.h"
#include "listas.h"
#include "manejodatos.h"
#include <stdlib.h>
#include <stdio.h>

void merge(GNodo* lista1, int cant_lista1, GNodo* lista2, int cant_lista2, GNodo* final_lista, FuncionComparadora compara){
    GNodo* auxLista1 = lista1;
    GNodo* auxLista2 = lista2;
    GNodo* lista_ordenada = auxLista1;
    int contador_lista1=0, contador_lista2=0;

    if(compara(auxLista1->dato,auxLista2->dato) < 0){
        auxLista1 = auxLista1->sig;
        contador_lista1++;
    }else{
        swap_nodes(auxLista1, auxLista2);
        GNodo* aux = auxLista1->sig;
        auxLista1=auxLista2;
        auxLista2=auxLista2->sig;
        auxLista1->sig = aux;
        contador_lista2++;
    }

    while(contador_lista1 < cant_lista1 && contador_lista2 < cant_lista2){
        if(compara(auxLista1->dato, auxLista2->dato) <= 0){
            lista_ordenada->sig = auxLista1;
            auxLista1 = auxLista1->sig;
            contador_lista1++;
        }else{
            lista_ordenada->sig = auxLista2;
            auxLista2 = auxLista2->sig;
            contador_lista2++;
        }
        lista_ordenada=lista_ordenada->sig;
    }


    //SE PODRA PONER lista_ordenada ->sig = auxLista2;
    while(contador_lista2 < cant_lista2){
        lista_ordenada->sig = auxLista2;
        auxLista2 = auxLista2->sig;
        lista_ordenada=lista_ordenada->sig;
        contador_lista2++;
    }
    
    while(contador_lista1 < cant_lista1){
        lista_ordenada->sig = auxLista1;
        auxLista1 = auxLista1->sig;
        lista_ordenada=lista_ordenada->sig;
        contador_lista1++;
    }
    lista_ordenada->sig = final_lista;
}

GNodo* devolver_nodo(GNodo* inicio, int pos){
    for(int i=1; i<pos;i++, inicio=inicio->sig);
    return inicio;
}

void merge_sort(GNodo* inicio, GNodo* fin, int largo, FuncionComparadora compara){
    if(largo > 1){
        int medio = largo/2;
        GNodo* nodo_medio = devolver_nodo(inicio, medio + 1);
        merge_sort(inicio, nodo_medio, medio, compara);
        merge_sort(nodo_medio, fin, largo-medio, compara);
        merge(inicio, medio, nodo_medio, largo-medio, fin, compara);
    }
}

void mergesort(GList* lista, FuncionComparadora compara){
    if(lista!=NULL && lista->inicio != lista->fin){
        merge_sort(lista->inicio, NULL, glist_largo(lista), compara);

    }
}
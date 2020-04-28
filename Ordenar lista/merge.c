#include "ordenamientos.h"
#include "listas.h"
#include "manejodatos.h"
#include <stdlib.h>
#include <stdio.h>

void merge(GNodo* lista1, GNodo* final_lista1, GNodo* lista2, GNodo* final_lista2, FuncionComparadora compara){

    // printf("INICIO1 %s\n", ((Persona*)(lista1->dato))->nombre);
    // printf("FINAL1 %s\n", ((Persona*)(final_lista1->dato))->nombre);
    // printf("INICIO2 %s\n", ((Persona*)(lista2->dato))->nombre);
    // printf("FINAL2 %s\n", ((Persona*)(final_lista2->dato))->nombre);", ((Persona*)(final_lista1->dato))->nombre);
    // printf("INICIO2 %s\n", ((Persona*)(lista2->dato))->nombre);
    // printf("FINAL2 %s\n", ((Persona*)(final_lista2->dato))->nombre);

    GNodo* auxLista1 = lista1;
    GNodo* auxLista2 = lista2;
    GNodo* lista_ordenada = auxLista1;
    
    lista_ordenada=auxLista1;
    if(compara(auxLista1->dato,auxLista2->dato) > 0)
        swap_nodes(auxLista1, auxLista2);
        
    auxLista1=auxLista1->sig;
    while(auxLista1 != final_lista1 && auxLista2 != final_lista2){
        if(compara(auxLista1->dato, auxLista2->dato) <= 0){
            lista_ordenada->sig = auxLista1;
            auxLista1 = auxLista1->sig;
        }else{
            lista_ordenada->sig = auxLista2;
            auxLista2 = auxLista2->sig;
        }
        lista_ordenada=lista_ordenada->sig;
    }


    //SE PODRA PONER lista_ordenada ->sig = auxLista2;
    while(auxLista2!=final_lista2){
        lista_ordenada->sig = auxLista2;
        auxLista2 = auxLista2->sig;
        lista_ordenada=lista_ordenada->sig;
    }
    
    while(auxLista1!=final_lista1){
        lista_ordenada->sig = auxLista1;
        auxLista1 = auxLista1->sig;
        lista_ordenada=lista_ordenada->sig;
    }
    lista_ordenada->sig = final_lista2;
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
        printf("LISTA1 SIN ORDENAR\n");
        for(GNodo* aux = inicio; aux != nodo_medio; aux=aux->sig){
            printf("%s, ", ((Persona*)(aux->dato))->nombre);
        }
        printf("\n");
        printf("LISTA2 SIN ORDENAR\n");
        for(GNodo* aux = nodo_medio; aux != fin; aux=aux->sig){
            printf("%s, ", ((Persona*)(aux->dato))->nombre);
        }
        printf("\n");
        merge(inicio, nodo_medio, nodo_medio, fin, compara);

        printf("LISTA ORDENADA\n");
        for(GNodo* aux = inicio; aux != fin; aux=aux->sig){
            printf("%s, ", ((Persona*)(aux->dato))->nombre);
        }
        printf("\n");
        printf("\n");
    }
}

void mergesort(GList* lista, FuncionComparadora compara){
    if(lista!=NULL && lista->inicio != lista->fin){
        merge_sort(lista->inicio, NULL, glist_largo(lista), compara);

    }
}
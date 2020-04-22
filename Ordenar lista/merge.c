#include "ordenamientos.h"
#include <stdlib.h>
#include <stdio.h>

void merge(GNodo* nodoX, GNodo* nodoY, GNodo* ultimo, FuncionComparadora compara) {
    GNodo* left = nodoX;
    GNodo* aux = nodoY;
	GNodo* right;

	while(left != ultimo) {
        if(left == aux) {
            aux = aux->sig;
        }
		right = aux;
		while(right != ultimo->sig){
			if(compara(right->dato, left->dato)) {
				shift_nodos(left, right);
                right = right->sig;
			}else {
                right = right->sig;
            }
		}
		left = left->sig;
	}
}

void shift_nodos(GNodo* inicio, GNodo* objetivo) {
	GNodo* temp = inicio;

	while(temp != objetivo) {
		swap_nodes(temp, objetivo);
		temp = temp->sig;
	}
}

int largo_lista(GNodo* inicio){
    int largo = 0;
    for(GNodo* aux = inicio; aux != NULL;aux=aux->sig, largo++);
    return largo;
}

GNodo* devolver_nodo(GNodo* inicio, int pos){
    for(int i=1; i<pos;i++, inicio=inicio->sig);
    return inicio;
}

void merge_sort(GNodo* inicio, GNodo* fin, int largo, FuncionComparadora compara){
    if(largo > 1){
        int medio = largo/2;
        GNodo* nodo_medio = devolver_nodo(inicio, medio-1);
        merge_sort(inicio, nodo_medio, medio-1, compara);
        merge_sort(nodo_medio->sig, fin, medio, compara);
        merge(inicio, nodo_medio, fin, compara);
    }
}

void mergesort(GList* lista, FuncionComparadora compara){
    if(lista!=NULL && lista->inicio != lista->fin){
        merge_sort(lista->inicio, lista->fin, glist_largo(lista), compara);
    }
}
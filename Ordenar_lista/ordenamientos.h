#ifndef __ORDENAMIENTOS_H__
#define __ORDENAMIENTOS_H__

#include <stddef.h>
#include "listas.h"

typedef int (*FuncionComparadora) (void *dato1, void *dato2);

/**
 * Divide recursivamente la lista en sub-listas hasta llegar a listas de largo 1
*/
GNodo* dividir_lista(GNodo *inicio, GNodo *fin, int largo, FuncionComparadora compara);

/**
 * Dadas dos sublistas ordenadas y la cantidad de elementos de cada sublista, une las dos sublistas ordenandolas 
 * sobre la primer lista
*/
GNodo* merge(GNodo *lista1, int cantLista1, GNodo *lista2, int cantLista2, GNodo *finalLista, FuncionComparadora compara);

/**
 * Dada una lista general ejecuta el merge selection sort utilizando una funcion dada
 * como parametro para comparar los elementos
*/
void merge_sort(GList *lista, FuncionComparadora compara);

/**
 * Busca el elemento considerado menor para una condicion dada en una lista general
*/
GNodo *busqueda_por_condicion(GNodo *nodo, FuncionComparadora compara);

/**
 * Dada una lista general ejecuta el algoritmo selection sort utilizando una funcion dada
 * como parametro para comparar los elementos
*/
void selection_sort(GList *lista, FuncionComparadora compara);

/**
 * Dada una lista ejecuta el algoritmo insertion sort utilizando una funcion
 * obtenida como parametro para comparar los elementos
*/
void insertion_sort(GList *lista, FuncionComparadora compara);

#endif

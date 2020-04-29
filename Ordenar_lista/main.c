#include "listas.h"
#include "ordenamientos.h"
#include "manejodatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menor_nombre(void *persona1, void *persona2) {
  return strcmp_unsigned(((Persona*) persona1)->nombre, ((Persona*) persona2)->nombre);
}

int menor_edad(void *persona1, void *persona2) {
  return (((Persona*) persona1)->edad - ((Persona*) persona2)->edad);
}

void destruir_persona(void *persona) {
  free(((Persona*) persona)->nombre);
  free(((Persona*) persona)->lugarNacimiento);
  free((Persona*) persona);
}

void visitar_persona(void *persona, FILE *archivo) {
  Persona *p = (Persona*) persona;
  fprintf(archivo, "%s, %d, %s\n", p->nombre, p->edad, p->lugarNacimiento);
}

void visitar_persona_consola(void *persona) {
  Persona *p = (Persona*) persona;
  printf("%s, %d, %s\n", p->nombre, p->edad, p->lugarNacimiento);
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
    GList *lista = glist_crear();
    generar_lista_personas(argv[1], lista);
    char salida[30];

    GList *listaCopia = glist_copia(lista);
    strcpy(salida, argv[2]);
    ordenar(lista, selection_sort, menor_nombre, strcat(salida, "_selection1.txt"), visitar_persona);
    
    lista = glist_copia(listaCopia);
    strcpy(salida, argv[2]);
    ordenar(lista, selection_sort, menor_edad, strcat(salida, "_selection2.txt"), visitar_persona);
    
    lista = glist_copia(listaCopia);
    strcpy(salida, argv[2]);
    ordenar(lista, insertion_sort, menor_nombre, strcat(salida, "_insertion1.txt"), visitar_persona);
    
    lista = glist_copia(listaCopia);
    strcpy(salida, argv[2]);
    ordenar(lista, insertion_sort, menor_edad, strcat(salida, "_insertion2.txt"), visitar_persona);
    
    lista = glist_copia(listaCopia);
    strcpy(salida, argv[2]);
    ordenar(lista, merge_sort, menor_nombre, strcat(salida, "_merge1.txt"), visitar_persona);
    
    lista = glist_copia(listaCopia);
    strcpy(salida, argv[2]);
    ordenar(lista, merge_sort, menor_edad, strcat(salida, "_merge2.txt"), visitar_persona);

    glist_destruir(listaCopia, destruir_persona);
  }else
    printf("Ingrese los parametros correctamente.\n");
  return 0;
}

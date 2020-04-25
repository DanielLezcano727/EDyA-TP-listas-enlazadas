#include "listas.h"
#include "ordenamientos.h"
#include "manejodatos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int menor_int(void* a, void* b) {
//   return (*((int*) a)<*((int*) b));
// }

int menor_nombre(void* persona1, void* persona2){
  return strcmp_unsigned(((Persona*) persona1)->nombre, ((Persona*) persona2)->nombre);
}

// void* copia(void* dato){
//   Persona* dato_copia = malloc(sizeof(Persona));

//   int largo = strlen(((Persona*)dato)->nombre) + 1;
//   dato_copia->nombre = malloc(sizeof(largo));
//   strcpy_unsigned(dato_copia->nombre, ((Persona*)dato)->nombre);

//   largo = strlen(((Persona*)dato)->lugarNacimiento) + 1;
//   dato_copia->lugarNacimiento = malloc(sizeof(largo));
//   strcpy_unsigned(dato_copia->lugarNacimiento, ((Persona*)dato)->lugarNacimiento);

//   dato_copia->edad = ((Persona*)dato)->edad;
//   return (void*)dato_copia;
// }

void destruir(void* persona){
  free(((Persona*)persona)->nombre);
  free(((Persona*)persona)->lugarNacimiento);
  free((Persona*)persona);
}

void visitar(void* persona, FILE* archivo){
  Persona* p = (Persona*)persona;
  fprintf(archivo, "%s, %d, %s\n", p->nombre, p->edad, p->lugarNacimiento);
}

int main(int argc, char* argv[]) {
  if(argc == 3){
    GList *lista = glist_crear();
    generar_lista_personas(argv[1], lista);
    selection_sort(lista, menor_nombre);
    glist_escribir_archivo(lista, visitar, argv[2]);
    glist_destruir(lista, destruir);
  }
  return 0;
}
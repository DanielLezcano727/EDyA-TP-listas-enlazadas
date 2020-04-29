#include "manejodatos.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void strcpy_unsigned(unsigned char *copia, unsigned char *original) {
  int i;
  for (i = 0; original[i] != '\0'; i++)
    copia[i] = original[i];
  copia[i] = '\0';
}

int strlen_unsigned(unsigned char *str) {
  int largo;
  for (largo = 1; str[largo] != '\0'; largo++);
  return largo;
}

int strcmp_unsigned(unsigned char *cadena1, unsigned char *cadena2) {
  int i;
  for (i = 0; cadena1[i] != '\0' && cadena2[i] != '\0' && cadena1[i] == cadena2[i]; i++);

  return cadena1[i] - cadena2[i];
}

int strtok_unsigned(unsigned char* palabra, char delimitador){
  int i;
  for(i=0;palabra[i]!=delimitador && palabra[i] != '\0';i++);
  palabra[i]='\0';
  return i + 1;
}

void generar_persona(unsigned char *datos, Persona *persona) {
  int cant_mover = 0;

  for(int i=0;i<3; i++){
    cant_mover = strtok_unsigned(datos, ',');
    if(i==0)
      strcpy_unsigned(persona->nombre, datos);
    else if(i==1)
      persona->edad = atoi((char*)datos);
    else
      strcpy_unsigned(persona->lugarNacimiento, datos);
    datos += cant_mover + 1;
  }
}

void generar_lista_personas(char *nombreArchivo, GList *lista) {
  unsigned char buff[256];
  int i;

  FILE *fPersonas = fopen(nombreArchivo, "r");

  Persona *p = malloc(sizeof(Persona));

  p->lugarNacimiento = malloc(sizeof(unsigned char) * 256);
  p->nombre = malloc(sizeof(unsigned char) * 256);

  for (i = 0; fscanf(fPersonas, "%[^\n]\n", buff) != EOF; i++) {
    generar_persona(buff, p);
    lista = glist_agregar_final(lista, p, copiar_persona);
  }

  free(p->lugarNacimiento);
  free(p->nombre);
  free(p);

  fclose(fPersonas);
}

void *copiar_persona(void *persona) {
  Persona *datoCopia = malloc(sizeof(Persona));

  int largo = strlen_unsigned(((Persona *) persona)->nombre) + 1;
  datoCopia->nombre = malloc(sizeof(char) * largo);
  strcpy_unsigned(datoCopia->nombre, ((Persona *) persona)->nombre);

  largo = strlen_unsigned(((Persona *) persona)->lugarNacimiento) + 1;
  datoCopia->lugarNacimiento = malloc(sizeof(char) * largo);
  strcpy_unsigned(datoCopia->lugarNacimiento, ((Persona *) persona)->lugarNacimiento);

  datoCopia->edad = ((Persona *) persona)->edad;
  return (void *) datoCopia;
}

void ordenar(GList *lista, Ordenamiento algOrdenamiento, FuncionComparadora compara, char *nombreSalida, FuncionEscritura escribirDato) {
  algOrdenamiento(lista, compara);
  glist_escribir_archivo(lista, escribirDato, nombreSalida);
  glist_destruir_sin_datos(lista);
}
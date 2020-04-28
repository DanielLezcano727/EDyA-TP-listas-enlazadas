#include "manejodatos.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

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

void generar_persona(unsigned char *datos, Persona *individuo) {
  int i;
  int current = 0;
  int flag = 0;
  char aux[256];

  for (i = 0; datos[i] != '\0'; i++) {

    if (datos[i] != ',')
      switch (flag) {
      case 0:
        individuo->nombre[current++] = datos[i];
        break;
      case 1:
        aux[current++] = datos[i];
        break;
      case 2:
        individuo->lugarNacimiento[current++] = datos[i];
        break;
      }
    else {
      if (flag == 0)
        individuo->nombre[current] = '\0';
      else if (flag == 1) {
        aux[current] = '\0';
        individuo->edad = atoi(aux);
      }

      flag++;
      i++;
      current = 0;
    }
  }
  individuo->lugarNacimiento[current] = '\0';
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
    lista = glist_agregar_inicio(lista, p, copia);
  }

  free(p->lugarNacimiento);
  free(p->nombre);
  free(p);

  fclose(fPersonas);
}

void *copia(void *dato) {
  Persona *datoCopia = malloc(sizeof(Persona));

  int largo = strlen_unsigned(((Persona *) dato)->nombre) + 1;
  datoCopia->nombre = malloc(sizeof(char) * largo);
  strcpy_unsigned(datoCopia->nombre, ((Persona *) dato)->nombre);

  largo = strlen_unsigned(((Persona *) dato)->lugarNacimiento) + 1;
  datoCopia->lugarNacimiento = malloc(sizeof(char) * largo);
  strcpy_unsigned(datoCopia->lugarNacimiento, ((Persona *) dato)->lugarNacimiento);

  datoCopia->edad = ((Persona *) dato)->edad;
  return (void *) datoCopia;
}

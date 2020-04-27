#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcpy_unsigned(unsigned char *copia, unsigned char *original) {
  int i;
  for (i = 0; original[i] != '\0'; i++)
    copia[i] = original[i];
  copia[i] = '\0';
}

int strlen_unsigned(unsigned char str[]) {
  int largo;
  for (largo = 1; str[largo] != '\0'; largo++);
  return largo;
}

int leer_paises(char *nameFilePaises, unsigned char ***paises) {
  FILE *fPaises = fopen(nameFilePaises, "r");

  int arrayTam = INCREMENTO_PAISES;

  *paises = malloc(sizeof(unsigned char *) * arrayTam);

  unsigned char buff[MAX_BUFFER];
  int cantPaises;

  for (cantPaises = 0; fscanf(fPaises, "%[^\r\n]\r\n", buff) != EOF; cantPaises++) {
    if (cantPaises == arrayTam) {
      arrayTam += INCREMENTO_PAISES;
      *paises = realloc(*paises, sizeof(unsigned char *) * arrayTam);
    }
    (*paises)[cantPaises] = malloc(sizeof(unsigned char) * (strlen_unsigned(buff) + 1));
    strcpy_unsigned((*paises)[cantPaises], buff);
  }

  fclose(fPaises);

  return cantPaises;
}

int cant_personas(FILE * fPersonas) {
  int cantLineas;
  unsigned char buff[MAX_BUFFER];
  for (cantLineas = 0; fscanf(fPersonas, "%[^\r\n]\r\n", buff) != EOF; cantLineas++);
  fseek(fPersonas, 0, SEEK_SET);
  return cantLineas;
}

int *generar_numeros_aleatorios(int cantidad, int limite) {
  int *numeros = malloc(sizeof(int) * cantidad);

  for (int i = 0; i < cantidad; i++)
    numeros[i] = rand() % limite;

  return numeros;
}

void leer_persona(FILE * fPersonas, int posIni, int posFin, unsigned char *persona) {
  if (posFin == 0)
    fscanf(fPersonas, "%[^\r\n]\r\n", persona);
  for (int i = posIni; i < posFin; i++)
    fscanf(fPersonas, "%[^\r\n]\r\n", persona);
}

int comparar_enteros(const void *n1, const void *n2) {
  return *((int *) n1) - *((int *) n2);
}

void generar_resultado(char *nameFileSalida, char *nameFilePersonas, unsigned char **paises, int cantPaises, int cantPedida) {
  FILE *salida = fopen(nameFileSalida, "w");
  FILE *fPersonas = fopen(nameFilePersonas, "r");

  int *personasAleatorias = generar_numeros_aleatorios(cantPedida, cant_personas(fPersonas));
  qsort(personasAleatorias, cantPedida, sizeof(int), &comparar_enteros);

  unsigned char *persona = malloc(sizeof(char) * MAX_BUFFER);

  for (int i = 0, indice; i < cantPedida; i++) {
    indice = i == 0 ? 0 : personasAleatorias[i - 1];
    leer_persona(fPersonas, indice, personasAleatorias[i], persona);
    fprintf(salida, "%s, %d, %s\n", persona, rand() % 100 + 1, paises[rand() % cantPaises]);
  }

  free(persona);
  free(personasAleatorias);
  fclose(fPersonas);
  fclose(salida);
}

void destruir_paises(int cantidad, unsigned char **paises) {
  for (int i = 0; i < cantidad; i++)
    free(paises[i]);
  free(paises);
}

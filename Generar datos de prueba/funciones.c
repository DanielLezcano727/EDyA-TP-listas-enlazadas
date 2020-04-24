#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcpy_unsigned(unsigned char* copia, unsigned char* original){
  int i;
  for (i=0; original[i] != '\0'; i++)
    copia[i]=original[i];
  copia[i] = '\0';
}

int strlen_unsigned(unsigned char str[]){
  int largo;
  for (largo=1; str[largo] != '\0'; largo++);
  return largo;
}

int leer_paises(char* nombrePaises, unsigned char*** paises) {
  FILE* fpaises = fopen(nombrePaises, "r");

  int array_tam = INCREMENTO_PAISES;
  
  *paises = malloc(sizeof(unsigned char*) * array_tam);
  
  unsigned char buff[MAX_BUFFER];
  int cant_paises;

  for(cant_paises = 0; fscanf(fpaises, "%[^\r\n]\r\n", buff) != EOF; cant_paises++) {
    if (cant_paises == array_tam){
        array_tam += INCREMENTO_PAISES;
        *paises = realloc(*paises, sizeof(unsigned char*) * array_tam);
    }
    (*paises)[cant_paises] = malloc(sizeof(unsigned char) * (strlen_unsigned(buff) + 1));
    strcpy_unsigned((*paises)[cant_paises], buff);
  }

  fclose(fpaises);

  return cant_paises;
}

int cant_personas(FILE* entrada){
  int cant_lineas;
  unsigned char buff[MAX_BUFFER];
  for(cant_lineas=0;fscanf(entrada, "%[^\r\n]\r\n", buff) != EOF; cant_lineas++);
  fseek(entrada, 0, SEEK_SET);
  return cant_lineas;
}

int* generar_numeros_aleatorios(int cant_numeros, int limite){
  int* numeros = malloc(sizeof(int) * cant_numeros);
  for(int i=0;i<cant_numeros;i++){
    numeros[i] = rand() % limite;
  }
  return numeros;
}

void leer_persona(FILE* entrada, int cant_lect, int pos, unsigned char* persona){
  if(pos == 0)
    fscanf(entrada, "%[^\r\n]\r\n", persona);
  for(int i=cant_lect;i<pos;i++)
    fscanf(entrada, "%[^\r\n]\r\n", persona);
}

int comparar_enteros(const void *n1, const void *n2){
  return *((int*)n1) - *((int*)n2);
}

void generar_resultado(char* nombre_salida, char* nombre_personas, unsigned char** paises, int cant_paises, int cant_lineas){
  FILE* salida = fopen(nombre_salida, "w");
  FILE* fpersona = fopen(nombre_personas, "r");

  int* personas_aleatorias = generar_numeros_aleatorios(cant_lineas, cant_personas(fpersona));
  qsort(personas_aleatorias, cant_lineas, sizeof(int), &comparar_enteros);
  
  unsigned char* persona = malloc(sizeof(char)*MAX_BUFFER);
  
  for(int i=0, indice;i < cant_lineas; i++){
    indice = i == 0 ? 0 : personas_aleatorias[i-1];
    leer_persona(fpersona, indice, personas_aleatorias[i], persona);
    fprintf(salida, "%s, %d, %s\n", persona, rand() % 100 + 1, paises[rand() % cant_paises]);
  }

  free(persona);
  free(personas_aleatorias);
  fclose(fpersona);
  fclose(salida);
}

void destruir_paises(int cantPaises, unsigned char** paises) {
  for(int i = 0; i < cantPaises; i++) {
    free(paises[i]);
  }
  free(paises);
}
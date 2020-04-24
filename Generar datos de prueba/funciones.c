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

int leer_paises(char* nameFilePaises, unsigned char*** paises) {
  FILE* fpaises = fopen(nameFilePaises, "r");

  int array_tam = INCREMENTO_PAISES;
  
  *paises = malloc(sizeof(unsigned char*) * array_tam);
  
  unsigned char buff[MAX_BUFFER];
  int cantPaises;

  for(cantPaises = 0; fscanf(fpaises, "%[^\r\n]\r\n", buff) != EOF; cantPaises++) {
    if (cantPaises == array_tam){
        array_tam += INCREMENTO_PAISES;
        *paises = realloc(*paises, sizeof(unsigned char*) * array_tam);
    }
    (*paises)[cantPaises] = malloc(sizeof(unsigned char) * (strlen_unsigned(buff) + 1));
    strcpy_unsigned((*paises)[cantPaises], buff);
  }

  fclose(fpaises);

  return cantPaises;
}

int cant_personas(FILE* fpersonas){
  int cant_lineas;
  unsigned char buff[MAX_BUFFER];
  for(cant_lineas=0;fscanf(fpersonas, "%[^\r\n]\r\n", buff) != EOF; cant_lineas++);
  fseek(fpersonas, 0, SEEK_SET);
  return cant_lineas;
}

int* generar_numeros_aleatorios(int cantidad, int limite){
  int* numeros = malloc(sizeof(int) * cantidad);
  for(int i=0;i<cantidad;i++){
    numeros[i] = rand() % limite;
  }
  return numeros;
}

void leer_persona(FILE* fpersonas, int posIni, int posFin, unsigned char* persona){
  if(posFin == 0)
    fscanf(fpersonas, "%[^\r\n]\r\n", persona);
  for(int i=posIni;i<posFin;i++)
    fscanf(fpersonas, "%[^\r\n]\r\n", persona);
}

int comparar_enteros(const void *n1, const void *n2){
  return *((int*)n1) - *((int*)n2);
}

void generar_resultado(char* nameFileSalida, char* nameFilePersonas, unsigned char** paises, int cantPaises, int cantPedida){
  FILE* salida = fopen(nameFileSalida, "w");
  FILE* fpersonas = fopen(nameFilePersonas, "r");

  int* personas_aleatorias = generar_numeros_aleatorios(cantPedida, cant_personas(fpersonas));
  qsort(personas_aleatorias, cantPedida, sizeof(int), &comparar_enteros);
  
  unsigned char* persona = malloc(sizeof(char)*MAX_BUFFER);
  
  for(int i=0, indice;i < cantPedida; i++){
    indice = i == 0 ? 0 : personas_aleatorias[i-1];
    leer_persona(fpersonas, indice, personas_aleatorias[i], persona);
    fprintf(salida, "%s, %d, %s\n", persona, rand() % 100 + 1, paises[rand() % cantPaises]);
  }

  free(persona);
  free(personas_aleatorias);
  fclose(fpersonas);
  fclose(salida);
}

void destruir_paises(int cantidad, unsigned char** paises) {
  for(int i = 0; i < cantidad; i++) {
    free(paises[i]);
  }
  free(paises);
}
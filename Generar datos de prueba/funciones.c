#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcpy_unsigned(unsigned char* copia, unsigned char* original){
    int i;
    for(i=0;original[i] != '\0';i++)
        copia[i]=original[i];
    copia[i]='\0';
}

int strlen_unsigned(unsigned char str[]){
    int largo;
    for(largo=1;str[largo] != '\0';largo++);
    return largo;
}

int leer_paises(char* nombrePaises, unsigned char*** paises) {
  FILE* fpaises = fopen(nombrePaises, "r");
  *paises = malloc(sizeof(unsigned char*) * INCREMENTO_PAISES);
  int array_tam = INCREMENTO_PAISES;
  unsigned char buff[MAX_BUFFER];
  int i;

  for(i = 0; fscanf(fpaises, "%[^\r\n]\r\n", buff) != EOF; i++) {
    if (i == array_tam){
        array_tam += INCREMENTO_PAISES;
        *paises = realloc(*paises, sizeof(unsigned char*) * array_tam);
    }
    (*paises)[i] = malloc(sizeof(unsigned char) * (strlen_unsigned(buff) + 1));
    strcpy_unsigned((*paises)[i], buff);
  }

  fclose(fpaises);

  return i;
}

char* leer_persona(FILE* entrada, int cant_lect, int pos){
  char* persona = malloc(sizeof(char) * 10);
  persona[0] = 'G';
  persona[1] = 'u';
  persona[2] = 'm';
  persona[3] = 'b';
  persona[4] = 'a';
  persona[5] = 'l';
  persona[6] = 'l';
  persona[7] = '\0';

  cant_lect = pos;
  fprintf(entrada, "%d\n", cant_lect);

  return persona;
}

void generar_resultado(char* nombre_salida, char* nombre_personas, unsigned char** paises, int cant_paises, int cant_lineas){
  FILE* salida = fopen(nombre_salida, "w");
  FILE* fpersona = fopen(nombre_personas, "r");
  // int* personas_aleatorias = generar_numeros_aleatorios(cant_lineas);
  int personas_aleatorias[] = {1};
  // personas_aleatorias = ordenar(personas_aleatorias);
  char* persona;
  for(int i=0;i < cant_lineas; i++){
    if(i != 0)
      persona = leer_persona(fpersona, personas_aleatorias[i-1], personas_aleatorias[i]);
    else
      persona = leer_persona(fpersona, 0, personas_aleatorias[i]);
    fprintf(salida, "%s, %d, %s\n", persona, rand() % 100 + 1, paises[rand() % cant_paises]);
    free(persona);
  }

  fclose(fpersona);
  fclose(salida);
}

void destruir_paises(int cantPaises, unsigned char** paises) {
  for(int i = 0; i < cantPaises; i++) {
    free(paises[i]);
  }
  free(paises);
}
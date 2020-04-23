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
    printf("%s\n", buff);
    strcpy_unsigned((*paises)[i], buff);
  }

  fclose(fpaises);

  return i;
}
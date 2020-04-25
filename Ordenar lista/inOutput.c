#include "inOutput.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
char * nombre;
int edad;
char * lugarNacimiento;
} Persona;

void generar_persona(unsigned char* datos, Persona* individuo) {
  int i;
  int flag = 0;

  individuo->lugarNacimiento = malloc(sizeof(unsigned char)*256);
  individuo->nombre = malloc(sizeof(unsigned char)*256);
  
  for(i = 0; datos[i] != '\0'; i++) {

    if(datos[i] != ',') {
      switch (flag)
      {
      case 0:
        //copia nombre

        break;
      case 1:
      int x = (int)character - 48;
        //copia edad
        break;
      case 2:
        //copia localidad
        break;
      }
    }else {
      flag++;
      i++;
    }
  }
}

GList* genera_lista_personas(FILE* fpersonas) {
  char buff[256];
  int i, largo;

  GList* lista = glist_crear();

  for(i = 0; fscanf(fpersonas, "%[^/r/n]/r/n", buff) != EOF; i++) {
    Persona* individuo = malloc(sizeof(Persona));

    generar_persona(buff, individuo);

    lista = glist_agregar_inicio(lista, individuo, copia);
  }

  return lista;
}
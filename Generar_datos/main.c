#include "stdlib.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Los parametros para ejecutar el programa son:
 *   1 - El archivo donde se encuentran los nombres de las personas
 *   2 - El archivo donde se encuentran los nombres de los paises
 *   3 - La cantidad de personas aleatorias que se quieren generar
 *   4 - El archivo de salida
 */
int main(int argc, char *argv[]) {
  if (argc == 5) {
    srand(time(NULL));
    unsigned char **paises = NULL;
    int cantPaises = leer_paises(argv[2], &paises);
    generar_resultado(argv[4], argv[1], paises, cantPaises, atoi(argv[3]));
    destruir_paises(cantPaises, paises);
  }else
    printf("Ingrese los parametros correctamente.\n ./programa nombre_personas.txt nombre_paises.txt cant_personas salida.txt");
  

  return 0;
}

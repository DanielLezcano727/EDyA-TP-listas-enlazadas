#include "stdlib.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc == 5) {
    srand(time(NULL));
    unsigned char **paises = NULL;
    int cantPaises = leer_paises(argv[2], &paises);
    generar_resultado(argv[4], argv[1], paises, cantPaises, atoi(argv[3]));
    destruir_paises(cantPaises, paises);
  }else
    printf("Ingrese los parametros correctamente.\n");
  

  return 0;
}

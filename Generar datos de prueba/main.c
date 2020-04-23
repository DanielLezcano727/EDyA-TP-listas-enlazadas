#include "stdlib.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if(argc == 3){
    unsigned char** paises = NULL;
    int cant_paises = leer_paises(argv[2], &paises);
  }

  return 0;
}
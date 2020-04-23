#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

#include <stddef.h>
#include <stdio.h>

// #define CANT_INICIAL_PAISES 50
#define INCREMENTO_PAISES 50
#define MAX_BUFFER 256

void strcpy_unsigned(unsigned char*, unsigned char*);
int strlen_unsigned(unsigned char[]);

int leer_paises(char*, unsigned char***);
void destruir_paises(int, unsigned char**);

char* leer_persona(FILE*, int, int);
void generar_resultado(char*, char*, unsigned char** , int, int);

#endif
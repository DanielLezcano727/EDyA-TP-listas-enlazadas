#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

#include <stddef.h>
#include <stdio.h>

// #define CANT_INICIAL_PAISES 50
#define INCREMENTO_PAISES 50
#define MAX_BUFFER 256

void strcpy_unsigned(unsigned char* copia, unsigned char* original);
int strlen_unsigned(unsigned char str[]);

int cant_personas(FILE* fpersonas);
int* generar_numeros_aleatorios(int cantidad, int limite);
int leer_paises(char* nameFilePaises, unsigned char*** paises);
void destruir_paises(int cantidad, unsigned char** paises);

void leer_persona(FILE* fpersonas, int posIni, int posFin, unsigned char* persona);
void generar_resultado(char* nameFileSalida, char* nameFilePersonas, unsigned char** paises, int cantPaises, int cantPedida);

#endif
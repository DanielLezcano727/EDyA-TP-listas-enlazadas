#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

#include <stddef.h>
#include <stdio.h>

#define INCREMENTO_PAISES 50
#define MAX_BUFFER 256

/**
 * Comportamiento adaptado de strcpy para unsigned char
*/
void strcpy_unsigned(unsigned char *copia, unsigned char *original);

/**
 * Comportamiento adaptado de strlen para unsigned char
*/
int strlen_unsigned(unsigned char str[]);

/**
 * Dado un archivo devuelve la cantidad de lineas que posee
*/
int cant_personas(FILE * fPersonas);

/**
 * Genera una lista de (cantidad) numeros aleatorios (<= maximo limite)
*/
int *generar_numeros_aleatorios(int cantidad, int limite);

/**
 * Dado un archivo con nombres de paises genera una lista con dichos 
 * nombres en el array que se pasa como parametro
*/
int leer_paises(char *nameFilePaises, unsigned char ***paises);

/**
 * Libera la memoria del array que contiene a los nombres de los paises
*/
void destruir_paises(int cantidad, unsigned char **paises);

/**
 * Lee del archivo que tiene los nombres de las personas desde la posicion 
 * inicial a la posicion final y guarda en persona la ultima persona leida
*/
void leer_persona(FILE * fPersonas, int posIni, int posFin, unsigned char *persona);

/**
 * Dado un archivo con nombres de personas y una lista de paises genera
 * personas aleatorias y las escribe en un archivo de salida de nombre dado 
*/
void generar_resultado(char *nameFileSalida, char *nameFilePersonas, unsigned char **paises, int cantPaises, int cantPedida);

#endif

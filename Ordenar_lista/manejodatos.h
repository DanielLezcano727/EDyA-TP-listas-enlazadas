#ifndef __MANEJODATOS_H__
#define __MANEJODATOS_H__

#include <stddef.h>
#include "listas.h"

typedef struct {
  unsigned char *nombre;
  int edad;
  unsigned char *lugarNacimiento;
} Persona;

typedef int (*FuncionComparadora) (void *dato1, void *dato2);
typedef void (*Ordenamiento) (GList* lista, FuncionComparadora compara);

/**
 * Comportamiento adaptado de strcpy para unsigned char
*/
void strcpy_unsigned(unsigned char *copia, unsigned char *original);

/**
 * Comportamiento adaptado de strlen para unsigned char
*/
int strlen_unsigned(unsigned char *str);

/**
 * Comportamiento adaptado de strcmp para unsigned char
*/
int strcmp_unsigned(unsigned char *cadena1, unsigned char *cadena2);

/**
 * Dada un array de caracteres y un delimitador cambia la primera ocurrencia del delimitador 
 * por un terminador y devuelve la cantidad de caracteres que hay entre el inicio y el delimitador
*/
int strtok_unsigned(unsigned char* palabra, char delimitador);

/**
 * Asigna los datos de una persona dados en char* a una estructura del tipo Persona
*/
void generar_persona(unsigned char *datos, Persona *persona);

/**
 * Dado un archivo con personas y sus datos genera una lista de personas con dichos datos
*/
void generar_lista_personas(char *nombreArchivo, GList *lista);

/**
 * Dada una persona crea una variable de tipo Persona y copia sus datos a la nueva variable
*/
void *copiar_persona(void *persona);

/**
 * Ordena una lista general con un algoritmo de ordenamiento recibido como parametro y 
 * escribe los resultados en un archivo cuyo nombre tambien se recibe como parametro
*/
void ordenar(GList *lista, Ordenamiento ordena, FuncionComparadora compara, char *nombreSalida, FuncionEscritura escribirDato);

#endif

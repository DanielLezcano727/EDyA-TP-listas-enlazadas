#ifndef __MANEJODATOS_H__
#define __MANEJODATOS_H__

#include <stddef.h>
#include <stdio.h>
#include "listas.h"

typedef struct {
  unsigned char* nombre;
  int edad;
  unsigned char* lugarNacimiento;
} Persona;

void* copia(void* dato);

int strlen_unsigned(unsigned char* str);

void strcpy_unsigned(unsigned char* copia, unsigned char* original);

int strcmp_unsigned(unsigned char* cadena1, unsigned char* cadena2);

void generar_lista_personas(char* nombreArchivo, GList* lista);

void generar_persona(unsigned char* datos, Persona* individuo);

#endif
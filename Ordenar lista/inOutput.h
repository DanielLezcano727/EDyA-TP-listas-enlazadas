#ifndef __INOUTPUT_H__
#define __INOUTPUT_H__

#include <stddef.h>
#include <stdio.h>
#include "listas.h"

typedef struct {
char * nombre;
int edad;
char * lugarNacimiento;
} Persona;

GList* generar_lista_personas(FILE* fpersonas);

void generar_persona(unsigned char* datos, Persona* individuo);

#endif /* __INOUTPUT_H__ */
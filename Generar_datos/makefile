FUNCIONES = funciones
SALIDA = main
ARCHIVO_NOMBRES = nombres1.txt
ARCHIVO_PAISES = paises.txt
PROGRAMA_SALIDA = main
FILE_SALIDA = entrada.txt

build: all
	@echo "Ingrese la cantidad de personas: "; \
    read CANT; \
	./$(PROGRAMA_SALIDA) $(ARCHIVO_NOMBRES) $(ARCHIVO_PAISES) $$CANT $(FILE_SALIDA)
	make clean

all: $(FUNCIONES).o main

$(FUNCIONES).o: $(FUNCIONES).c $(FUNCIONES).h
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(FUNCIONES).c

main: $(FUNCIONES).o main.c
	gcc -Wall -Wextra -Werror -std=c99 -g -o $(PROGRAMA_SALIDA) main.c $(FUNCIONES).o

clean:
	rm *.o
	
clean_all:
	rm *.o main
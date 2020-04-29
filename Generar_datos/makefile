FUNCIONES = funciones
SALIDA = main
ARCHIVO_NOMBRES = nombres1.txt
ARCHIVO_PAISES = paises.txt

build: all
	@echo "Ingrese la cantidad de personas: "; \
    read CANT; \
	./main $(ARCHIVO_NOMBRES) $(ARCHIVO_PAISES) $$CANT entrada.txt
	mv entrada.txt ./../Ordenar_lista/
	make clean

all: $(FUNCIONES).o main

$(FUNCIONES).o: $(FUNCIONES).c $(FUNCIONES).h
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(FUNCIONES).c

main: $(FUNCIONES).o main.c
	gcc -Wall -Wextra -Werror -std=c99 -g -o $(SALIDA) main.c $(FUNCIONES).o

clean:
	rm *.o
	
clean_all:
	rm *.o main
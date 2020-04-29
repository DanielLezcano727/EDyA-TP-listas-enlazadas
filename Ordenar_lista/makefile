ESTRUCTURA = listas
ORDENAMIENTO1 = selection
ORDENAMIENTO2 = insertion
ORDENAMIENTO3 = merge
ORDENAMIENTO_H = ordenamientos
DATA = manejodatos
FILE_ENTRADA = entrada.txt
FILE_SALIDA = salida
PROGRAMA_SALIDA = main

build: all
	cd ./../Generar_datos/ && make build; mv $(FILE_ENTRADA) ./../Ordenar_lista/
	./main $(FILE_ENTRADA) $(FILE_SALIDA)
	make clean

all: $(ESTRUCTURA).o $(ORDENAMIENTO1).o $(ORDENAMIENTO2).o $(ORDENAMIENTO3).o $(DATA).o main

$(ESTRUCTURA).o: $(ESTRUCTURA).h $(ESTRUCTURA).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ESTRUCTURA).c

$(ORDENAMIENTO1).o: $(ORDENAMIENTO_H).h $(ORDENAMIENTO1).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ORDENAMIENTO1).c

$(ORDENAMIENTO2).o: $(ORDENAMIENTO_H).h $(ORDENAMIENTO2).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ORDENAMIENTO2).c

$(ORDENAMIENTO3).o: $(ORDENAMIENTO_H).h $(ORDENAMIENTO3).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ORDENAMIENTO3).c

$(DATA).o: $(DATA).h $(DATA).c $(ESTRUCTURA).o
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(DATA).c

main: $(ESTRUCTURA).o $(ORDENAMIENTO1).o $(ORDENAMIENTO2).o $(ORDENAMIENTO3).o $(DATA).o main.c
	gcc -Wall -Wextra -Werror -std=c99 -g -o $(PROGRAMA_SALIDA) main.c $(ESTRUCTURA).o $(ORDENAMIENTO1).o $(ORDENAMIENTO2).o $(ORDENAMIENTO3).o $(DATA).o

clean:
	rm *.o

clean_all:
	rm *.o main $(FILE_ENTRADA)* $(FILE_SALIDA)* vgcore*
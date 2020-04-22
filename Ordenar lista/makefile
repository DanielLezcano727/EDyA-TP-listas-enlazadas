ESTRUCTURA = listas
ORDENAMIENTO1 = selection
ORDENAMIENTO_H = ordenamientos
SALIDA = main

all: $(ESTRUCTURA).o main

$(ESTRUCTURA).o: $(ESTRUCTURA).h $(ESTRUCTURA).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ESTRUCTURA).c

$(ORDENAMIENTO1).o: $(ORDENAMIENTO_H).h $(ORDENAMIENTO1).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ORDENAMIENTO1).c

main: $(ESTRUCTURA).o $(ESTRUCTURA).h $(ORDENAMIENTO1).o $(ORDENAMIENTO_H).h main.c
	gcc -Wall -Wextra -Werror -std=c99 -g -o $(SALIDA) main.c $(ESTRUCTURA).o $(ORDENAMIENTO1).o

clean:
	rm *.o main
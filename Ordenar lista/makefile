ESTRUCTURA = listas
ORDENAMIENTO1 = selection
ORDENAMIENTO2 = insertion
ORDENAMIENTO3 = merge
ORDENAMIENTO_H = ordenamientos
SALIDA = main

all: $(ESTRUCTURA).o $(ORDENAMIENTO1).o $(ORDENAMIENTO2).o $(ORDENAMIENTO3).o main

$(ESTRUCTURA).o: $(ESTRUCTURA).h $(ESTRUCTURA).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ESTRUCTURA).c

$(ORDENAMIENTO1).o: $(ORDENAMIENTO_H).h $(ORDENAMIENTO1).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ORDENAMIENTO1).c

$(ORDENAMIENTO2).o: $(ORDENAMIENTO_H).h $(ORDENAMIENTO2).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ORDENAMIENTO2).c

$(ORDENAMIENTO3).o: $(ORDENAMIENTO_H).h $(ORDENAMIENTO3).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ORDENAMIENTO3).c

main: $(ESTRUCTURA).o $(ESTRUCTURA).h $(ORDENAMIENTO1).o $(ORDENAMIENTO_H).h $(ORDENAMIENTO2).c $(ORDENAMIENTO3).c main.c
	gcc -Wall -Wextra -Werror -std=c99 -g -o $(SALIDA) main.c $(ESTRUCTURA).o $(ORDENAMIENTO1).o $(ORDENAMIENTO2).o $(ORDENAMIENTO3).o

clean:
	rm *.o main
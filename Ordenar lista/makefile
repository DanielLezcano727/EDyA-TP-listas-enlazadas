ESTRUCTURA = listas
ORDENAMIENTO1 = selection
SALIDA = main

all: $(ESTRUCTURA).o $(ORDENAMIENTO1).o main

$(ESTRUCTURA).o: $(ESTRUCTURA).h $(ESTRUCTURA).c
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(ESTRUCTURA).c

$(ORDENAMIENTO1).o: $(ORDENAMIENTO1).h $(ORDENAMIENTO1).c
  gcc -Wall -Wextra -Werror -std=c99 -g -c $(ORDENAMIENTO1).c

main: $(ESTRUCTURA).o $(ESTRUCTURA).h $(ORDENAMIENTO1).o $(ESTRUCTURA).h main.c
  gcc -Wall -Wextra -Werror -std=c99 -g -o $(SALIDA) main.c $(ESTRUCTURA).o $(ORDENAMIENTO1).o

clean:
	rm *.o
FUNCIONES = funciones
SALIDA = main

all: $(FUNCIONES).o main

$(FUNCIONES).o: $(FUNCIONES).c $(FUNCIONES).h
	gcc -Wall -Wextra -Werror -std=c99 -g -c $(FUNCIONES).c

main: $(FUNCIONES).o main.c
	gcc -Wall -Wextra -Werror -std=c99 -g -o $(SALIDA) main.c $(FUNCIONES).o

clean:
	rm *.o main
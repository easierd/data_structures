.PHONY: clean
GCC_OPTIONS = -Wall -Wextra -fsanitize=address

bst.o: bst.c bst.h
	gcc -c $(GCC_OPTIONS) bst.c

main: main.c bst.o
	gcc -o main $(GCC_OPTIONS) main.c bst.o

debug: GCC_OPTIONS += -g
debug: main
	gdb ./main

clean:
	rm main *.o

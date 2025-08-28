GCC_OPTIONS = -Wall -Wextra -fsanitize=address

bin_tree.o: bin_tree.c
	gcc -c $(GCC_OPTIONS) bin_tree.c

main: main.c bin_tree.o
	gcc -o main $(GCC_OPTIONS) bin_tree.o main.c

clean:
	rm -rf *.o main

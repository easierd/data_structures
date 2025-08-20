stack.o: stack.c
	gcc -c -Wall -Wextra -fsanitize=address stack.c

main: stack.o main.c
	gcc -o main -Wall -Wextra -fsanitize=address main.c stack.o

clean:
	rm -rf main *.o

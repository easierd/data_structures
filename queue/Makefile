.PHONY: clean

queue.o: queue.c
	gcc -c -Wall -Wextra -fsanitize=address queue.c

main: queue.o main.c
	gcc -o main -Wall -Wextra -fsanitize=address main.c queue.o


clean:
	rm -rf main *.o

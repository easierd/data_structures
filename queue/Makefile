.PHONY: clean
CFLAGS = -Wall -Wextra -fsanitize=address

queue.o: queue.c queue.h
	gcc $(CFLAGS) -c queue.c

main.o: main.c queue.h
	gcc ${CFLAGS} -c main.c

main: main.o queue.o
	gcc ${CFLAGS} -o main main.o queue.o


clean:
	rm -rf main *.o

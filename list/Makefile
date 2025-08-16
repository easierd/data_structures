.PHONY: clean

linked_list.o: singly_linked_list/linked_list.c
	gcc -c -Wall -Wextra -fsanitize=address singly_linked_list/linked_list.c

sll: main.c linked_list.o
	gcc -o sll -Wall -Wextra -fsanitize=address main.c linked_list.o

clean:
	rm sll *.o

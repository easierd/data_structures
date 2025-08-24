.PHONY: clean

linked_list.o: singly_linked_list/linked_list.c
	gcc -c -Wall -Wextra -fsanitize=address singly_linked_list/linked_list.c

doubly_linked_list.o: doubly_linked_list/list.c
	gcc -c -Wall -Wextra -fsanitize=address doubly_linked_list/list.c -o doubly_linked_list.o

sll: main.c linked_list.o
	gcc -o sll -Wall -Wextra -fsanitize=address main.c linked_list.o

dll: main.c doubly_linked_list.o
	gcc -o dll -Wall -Wextra -fsanitize=address main.c doubly_linked_list.o

clean:
	rm sll *.o

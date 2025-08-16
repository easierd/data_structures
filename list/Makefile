.PHONY: clean

linked_list.o: linked_list.c
	gcc -c -Wall -Wextra -fsanitize=address linked_list.c


sll: main.c linked_list.o
	gcc -o sll -Wall -Wextra -fsanitize=address main.c linked_list.o


clean:
	rm sll *.o

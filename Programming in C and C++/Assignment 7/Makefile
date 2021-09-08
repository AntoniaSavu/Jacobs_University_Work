all: main

CC=gcc

CFLAGS=-c -Wall


main: linked_list.o use_linked_list.o
	$(CC) -o main linked_list.o use_linked_list.o

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) linked_list.c

use_linked_list.o: use_linked_list.c
	$(CC) $(CFLAGS) use_linked_list.c

clean:
	rm -f main *.o

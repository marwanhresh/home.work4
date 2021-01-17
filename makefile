CC = gcc -g
AR = ar -rcs
FLAGS = -Wall -fPIC

all: frequency
frequency: tree.o main.o
	$(CC) $(FLAGS) -o frequency tree.o main.o
tree.o: tree.c tree.h
	$(CC) $(FLAGS) -c tree.c
main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all frequency

clean:
	rm -f *.o *.a *.so frequency
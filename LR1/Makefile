CC = gcc
CFLAGS = -Wall -Wextra -O2
LIBS = -lm

all: program

program: main.o matrix.o
	$(CC) $(CFLAGS) main.o matrix.o -o program $(LIBS)

main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

clean:
	rm -f *.o program
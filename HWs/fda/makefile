CC=gcc
CFLAGS=-g -Wall


main: fda.o
	$(CC) $(CFLAGS) fda.o main.c -o main

fda.o: fda.c fda.h
	$(CC) $(CFLAGS) -c fda.c

clean:
	rm -f fda.o main
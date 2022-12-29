CC=gcc
CFLAGS=-g -Wall
OBJFLAGS=-g -Wall -c

targets = heap grand integrate integers scrabble

all: $(targets)

scrabble: scrabble.c 
	$(CC) $(CFLAGS) $@.c -o $@

heap: heap.c
	$(CC) $(CFLAGS) $@.c -o $@

random: random.c random.h
	$(CC) $(OBJFLAGS) $@.c 

grand: grand.c random.o
	$(CC) $(CFLAGS) $@.c random.o -o $@

integrate: integrate.c 
	$(CC) $(CFLAGS) $@.c -lm -o $@

integers: integers.c 
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm *.o $(targets)
 

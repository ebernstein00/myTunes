ifeq($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o linkedlist.o tunes.o
	$(CC) -o program main.o linkedlist.o tunes.o

main.o: main.c listfunctions.h tunes.h
	$(CC) -c main.c

tunes.o: tunes.c tunes.h listfunctions.h
	$(CC) -c tunes.c

linkedlist.o: linkedlist.c listfunctions.h
	$(CC) -c linkedlist.c

run:
	./program

clean:
	rm *.o
	rm *~

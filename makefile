all: main.o linkedlist.o
	gcc -o program main.o linkedlist.o

main.o: main.c listfunctions.h
	gcc -c main.c

funcs.o: linkedlist.c listfunctions.h
	gcc -c linkedlist.c

run:
	./program

clean:
	rm *.o
	rm *~

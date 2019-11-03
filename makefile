all: main.o linkedlist.o tunes.o
	gcc -o program main.o linkedlist.o tunes.o

main.o: main.c listfunctions.h tunes.h
	gcc -c -g main.c

tunes.o: tunes.c tunes.h listfunctions.h
	gcc -c -g tunes.c

linkedlist.o: linkedlist.c listfunctions.h
	gcc -c -g linkedlist.c



run:
	./program

clean:
	rm *.o
	rm *~

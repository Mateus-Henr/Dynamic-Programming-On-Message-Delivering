all:
	gcc -o main src/functions.c src/travel.c src/test.c
	./main

clean:
	rm all main
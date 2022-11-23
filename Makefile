all:
	gcc -o main src/file.c src/matrix.c src/travel.c src/main.c
	./main

clean:
	rm all main
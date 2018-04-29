all: program


program: build/main.o build/layout.o build/output.o build/move.o bin
	gcc -Wall -Werror build/main.o build/layout.o build/output.o build/move.o -o bin/program

build/main.o: src/main.c build
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/layout.o: src/layout.c build
	gcc -Wall -Werror -c src/layout.c -o build/layout.o

build/output.o: src/output.c build
	gcc -Wall -Werror -c src/output.c -o build/output.o

build/move.o: src/move.c build
	gcc -Wall -Werror -c src/move.c -o build/move.o

build:
	mkdir build

bin:
	mkdir bin

.PHONY: clean

clean:
	rm -rf bin build

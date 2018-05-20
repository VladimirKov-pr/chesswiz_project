all: program

program: build/main.o build/layout.o build/output.o build/move.o bin
	gcc -Wall -Werror build/main.o build/layout.o build/output.o build/move.o -lm -o bin/program

test: build/main_test.o build/layout.o build/move.o bin
	gcc build/main_test.o build/layout.o build/move.o -lm -o bin/test

build/main.o: src/main.c build
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/main_test.o: test/main.c
	gcc -I thirdparty -I src -c test/main.c -o build/main_test.o

build/layout.o: src/layout.c
	gcc -c src/layout.c -o build/layout.o

build/move.o: src/move.c
	gcc -c src/move.c -o build/move.o

build/output.o: src/output.c build
	gcc -Wall -Werror -c src/output.c -o build/output.o

build:
	mkdir build

bin:
	mkdir bin

.PHONY: clean

clean:
	rm -rf bin build

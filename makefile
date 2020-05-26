.PHONY: clean
all: ./bin/main ./bin/test
test: ./bin/test


./bin/test: ./build/test/main.o ./build/test/test_func.o ./build/src/func.o 
	gcc -Wall -I src -Werror -o ./bin/test ./build/test/main.o ./build/src/func.o ./build/test/test_func.o -lm
	./bin/test

./bin/main: ./build/src/main.o ./build/src/func.o
	gcc -Wall -Werror -o ./bin/main build/src/main.o ./build/src/func.o -lm

./build/src/main.o: ./src/main.c
	gcc -c -o ./build/src/main.o ./src/main.c -lm

./build/src/func.o: ./src/func.c
	gcc -c -o  ./build/src/func.o ./src/func.c -lm

./build/test/main.o: ./test/main.c
	gcc -c -Wall -I src -o ./build/test/main.o ./test/main.c -lm

./build/test/test_func.o: ./test/test_func.c
	gcc -c -Wall -I src -o  ./build/test/test_func.o ./test/test_func.c -lm


clean:
	rm -rf ./bin/* ./build/src/*o ./build/test/*o
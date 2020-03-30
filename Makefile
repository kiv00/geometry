DEPS = area.h
DEPS = perimeter.h

main.exe: src\main.c
	gcc -Wall -Werror -o main.exe src\main.c -lm
	gcc -I thirdparty src -c test/board_test.c -o build/test/board_test.o
clean:
	rm -rf *o hello
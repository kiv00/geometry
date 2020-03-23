DEPS = area.h
DEPS = perimeter.h

main.exe: src\main.c
	gcc -Wall -Werror -o main.exe src\main.c -lm

clean:
	rm -rf *o hello
HEADER = area.h
HEADER = perimeter.h

main.exe: main.c
	gcc -Wall -Werror -o main.exe main.c -lm

clean:
	rm -rf *o hello
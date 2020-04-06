DEPS = area.h
DEPS = perimeter.h
main.exe: src\main.c
	gcc -Wall -Werror -o main.exe src\main.c -lm

all: test

remake: clean all

%.o: %.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<

test: main.o ctest.h mytests.o
	$(CC) $(LDFLAGS) main.o mytests.o -o test
clean:
	rm -rf *o hello
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDLIBS = -lncurses

tetris: src/main.c
	$(CC) $(CFLAGS) -o tetris src/main.c $(LDLIBS)

clean:
	rm -f tetris src/*.o

.PHONY: clean

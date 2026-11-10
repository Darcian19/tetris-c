CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDLIBS = -lncurses

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

tetris: $(OBJ)
	$(CC) $(CFLAGS) -o tetris $(OBJ) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f tetris src/*.o

.PHONY: clean

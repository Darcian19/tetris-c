CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS = -lncurses

SRCS = src/main.c src/board.c
OBJS = $(SRCS:.c=.o)
TARGET = tetris

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

src/%.o: src/%.c include/tetris.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 

.PHONY: all clean 

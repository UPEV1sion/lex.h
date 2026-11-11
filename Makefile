CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c11 -ggdb

.PHONY: lex expected all test

all: lex expected

lex: main.c lex.h
	$(CC) $(CFLAGS) -o $@ $^

expected: expected.c lex.h
	$(CC) $(CFLAGS) -o $@ $^

test: lex
	./lex test/*.c

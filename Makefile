CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -ggdb -pedantic -std=c11

all: lex

keywords.h: keywords.gperf
	gperf --initializer-suffix=",0" $^ --output-file=$@

lex: main.c lex.h
	$(CC) $(CFLAGS) -o $@ $^

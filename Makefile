CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -pedantic -std=c11

all: lex

keywords.h: keywords.gperf
	gperf --initializer-suffix=",0" $^ --output-file=$@

lex: main.c
	$(CC) $(CFLAGS) -o $@ $^

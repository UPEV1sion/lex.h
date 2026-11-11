CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c11 -ggdb

.PHONY: test expected all run_tests

all: test

test: test.c ../lex.h clang_mapping.h
	$(CC) $(CFLAGS) -o $@ $^

clang_mapping.h: clang_mapping.gperf
	gperf -H clang_hash -W clang_wordlist --constants-prefix=CLANG_ --initializer-suffix=,0 --output-file=$@ $^

run_tests: test
	./test tests/*.c

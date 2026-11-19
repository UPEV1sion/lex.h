CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c11 -ggdb

.PHONY: test expected all run_tests

all: lex.h

tests/test: tests/test.c lex.h tests/clang_mapping.h
	$(CC) $(CFLAGS) -o $@ $^

keywords.h: keywords.gperf
	gperf --initializer-suffix=,0 keywords.gperf | sed '/#line.*/d' > $@ # remove the #line directives because it poisons the error messages

lex.h: lex.h.m4 keywords.h
	m4 -P $< > $@

tests/clang_mapping.h: tests/clang_mapping.gperf
	gperf --initializer-suffix=,0 --output-file=$@ $^

run_tests: tests/test
	tests/test tests/tests/*.c

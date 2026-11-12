CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c11 -ggdb

TEST_SRCS := $(wildcard tests/*.c)
TEST_EXPECTED := $(TEST_SRCS:.c=.c.expected)

.PHONY: test expected all run_tests

all: test

test: test.c ../lex.h clang_mapping.h
	$(CC) $(CFLAGS) -o $@ $^

clang_mapping.h: clang_mapping.gperf
	gperf -H clang_hash -W clang_wordlist --constants-prefix=CLANG_ --initializer-suffix=,0 --output-file=$@ $^

tests/%.c.expected: tests/%.c
	clang -cc1 -dump-tokens -Wno-comments $^ 2> $@

run_tests: test $(TEST_EXPECTED)
	./test tests/*.c

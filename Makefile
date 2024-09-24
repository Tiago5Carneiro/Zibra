CC = gcc
CFLAGS = -Wall -g -Iinclude
LDFLAGS =

all: folders compiler

folders:
	@mkdir -p src include obj bin tmp

compiler : bin/compiler

bin/compiler: obj/main.o obj/parser.o obj/tree.o
	$(CC) $(LDFLAGS) $^ -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f obj/* tmp/* bin/*
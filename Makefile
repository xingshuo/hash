CFLAGS = -g3 -O0 -Wall
SRC = src

test.a: test.c $(SRC)/hash.c
	gcc $(CFLAGS) $^ -o $@ -I$(SRC)

run: | test.a
	./test.a

clean:
	rm test.a
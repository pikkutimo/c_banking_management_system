CC = clang
CFLAGS = -g -Wall

bms:
	$(CC) $(CFLAGS) src/*.c -lncurses -o bms -I includes

test:
	$(CC) $(CFLAGS) tests/*.c munit/* -I includes

clean:
	rm -f bms test
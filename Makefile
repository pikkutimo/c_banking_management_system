CC = clang
CFLAGS = -g -Wall

bms:
	$(CC) $(CFLAGS) src/*.c -lncurses -o bms -I includes

test:
	$(CC) $(CFLAGS) tests/*.c munit/*.c -I includes -I munit


clean:
	rm -f bms test
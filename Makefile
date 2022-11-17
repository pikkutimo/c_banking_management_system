CC = clang
CFLAGS = -g -Wall

bms:
	$(CC) $(CFLAGS) src/*.c -lncurses -o bms -I includes

clean:
	rm -f bms
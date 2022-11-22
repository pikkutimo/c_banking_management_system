CC = clang
CFLAGS = -g -Wall

bms:
	$(CC) $(CFLAGS) src/*.c -lncurses -o bms -I includes

test:
	$(CC) $(CFLAGS) tests/*c src/bms_utils.c -o test -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit -I includes


clean:
	rm -f bms test
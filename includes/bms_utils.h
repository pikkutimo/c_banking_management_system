#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

typedef struct {
    char id[11];
    char name[32];
    char email[32];
    time_t date_of_birth;
} person;

typedef struct {
    char account_no[12];
    char owner[11];
    char balance[16];
    time_t date_of_creation;
} account;

typedef struct {
    time_t transaction_time;
    char sender[12]; // account no
    char receiver[12];
    char transaction_value[16];
    char signee[11]; // who initated this transfer?
} transaction;

time_t create_timestamp(int year, int month, int wday, int hour, int min, int sec, int isdst);
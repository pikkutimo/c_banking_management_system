#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

// DESIGN:
// * User interface will be done with curses
// * Represent numbers with strings, use numbers only in calculations
// * The persons-file will contain every client
// * The accounts-file will contain every account in the bank
// * The ledger-file will contain every transactions of the bank
// * The two former files are read into memory on start and saved on exit
// * On the other hand every transaction is added to the ledger immediately 
// 
// IDEAS?
// * External SQL?

struct person {
    char id[10];
    char name[32];
    char email[32];
    time_t date_of_birth;
};

struct account {
    char account_no[12];
    char owner[10];
    char balance[15];
    time_t date_of_creation;
};

struct transaction {
    time_t transaction_time;
    char sender[12]; // account no
    char receiver[12];
    char transaction_value[15];
    char signee[10]; // who initated this transfer?
};

int main(int argc, char *argv[]) {
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    getch();
    return 0;
}
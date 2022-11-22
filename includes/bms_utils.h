#ifndef BMS_UTILS_H
#define BMS_UTILS_H

#include <stdio.h>
#include <stdlib.h>
// #include <ncurses.h>
#include <time.h>

struct Person{
    char id[11];
    char name[32];
    char email[32];
    time_t date_of_birth;
    // struct person *next;
};

struct Account{
    char account_no[12];
    char owner[11];
    char balance[16];
    time_t date_of_creation;
    // struct account *next;
};

struct Transaction{
    time_t transaction_time;
    char sender[12]; // account no
    char receiver[12];
    char transaction_value[16];
    char signee[11]; // who initated this transfer?
    // struct transaction *next;
};

struct List{
    void *data;
    struct Node *next;
}

// const char *persons_file_name = "persons.dat";
// const char *accounts_file_name = "accounts.dat";
// const char *ledger_file_name = "ledger.dat";

time_t create_timestamp(int year, int month, int weekday, int hour, int min, int sec, int isdst);
void write_to_file(char * filename, ...);
// struct person* create_client_list();
// struct account* create_account_list();
// struct transaction* create_transaction_list();
void push(struct List *current, void *new_data);
struct Person* create_client(char *id, char *name, char *email, int year, int month, int weekday);

#endif
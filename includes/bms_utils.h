#ifndef BMS_UTILS_H
#define BMS_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Person{
    char id[11];
    char name[32];
    char email[32];
    time_t date_of_birth;
};

// struct Account{
//     char account_no[12];
//     char owner[11];
//     char balance[16];
//     time_t date_of_creation;

// struct Transaction{
//     time_t transaction_time;
//     char sender[12]; // account no
//     char receiver[12];
//     char transaction_value[16];
//     char signee[11]; // who initated this transfer?
// };

struct Clients {
    struct Clients *next;
    struct Person client;
};

time_t create_timestamp(int year, int month, int weekday, int hour, int min, int sec, int isdst);
struct Person *create_client(char *id, char *name, char *email, int year, int month, int weekday);
void insertClient(struct Clients **current, struct Person *person);
void printClients(struct Clients *current);

#endif
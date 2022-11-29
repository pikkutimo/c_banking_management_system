#ifndef BMS_UTILS_H
#define BMS_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Person{
    char id[15];
    char name[32];
    char email[32];
    time_t date_of_birth;
};

struct Account{
    char account_no[12];
    char owner[11];
    char balance[16];
    time_t date_of_creation;
};

struct Transaction{
    char sender[12]; // account no
    char receiver[12];
    char amount[16];
    time_t date_of_transaction;
};

/* A linked list node */
struct Node { 
// Any data type can be stored in this node 
    void  *data; 
    struct Node *next;
    struct Node *previous;
}; 

time_t create_timestamp(int year, int month, int weekday, int hour, int min, int sec, int isdst);
struct Person *create_client(char *id, char *name, char *email, int year, int month, int weekday);
struct Account* create_account(char *acc_no, char *owner_id);
struct Transaction* create_transaction(char *sender, char *receiver, char *amount);
void printList(struct Node *node, void (*fptr)(void *));
void printNode(struct Node *node, void (*fptr)(void *));
void printClient(void *data);
void printAccount(void *data);
void printTransaction(void *data);
void insert_head(struct Node** head_ref, struct Node** tail_ref, void *new_data, size_t data_size);
void insert_tail(struct Node** head_ref, struct Node** tail_ref, void *new_data, size_t data_size);
void insert_middle(struct Node **tail_ref, struct Node *previous_node, void *new_data, size_t data_size);
void delete_node(struct Node **head_ref, struct Node **tail_ref, struct Node *node_to_delete);
int compareNames(const struct Person *a, const struct Person *b);
int compareDate(const struct Transaction *a, const struct Transaction *b);
void middle(struct Node* source, struct Node** frontRef, struct Node** backRef);
struct Node* SortedMerge(struct Node* a, struct Node* b, int (*compar)(const void*, const void*));
void MergeSort(struct Node** headRef, int (*compar)(const void*, const void*));
void clear_list(struct Node **head_ref, struct Node **tail_ref);


#endif
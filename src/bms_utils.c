#include "bms_utils.h"

time_t create_timestamp(int year, int month, int weekday, int hour, int min, int sec, int isdst) {
    struct tm str_time;
    str_time.tm_year = year - 1900;
    str_time.tm_mon = month; // Starts from 0 ?
    str_time.tm_mday = weekday;
    str_time.tm_hour = hour;
    str_time.tm_min = min;
    str_time.tm_sec = sec;
    str_time.tm_isdst = isdst;

    return mktime(&str_time);
}

void write_to_file(char * filename, ...) {
    // variadic function
    // 1. parameter is the filename
    // 2. parameter is the pointer to a struct pointer
    //

    printf("Not implemented yet.\n");
}

// Function to push data onto list
void push(struct List *current, struct List *first, void *new_data) {
    struct List *new_node = (struct List *) malloc(sizeof(struct List));
    if (new_node == NULL) {
        fprintf(stderr, "Couldn't allocate memory");
        exit(1);
    }

   new_node->data = new_data;
   new_node->next = NULL;

   if (first == NULL) {
    first = current = new_node;
   } else {
    current->next = new_node;
    current = current->next;
   }


    // Do we need to allocate memory for the node, if it has already been done elsewhere?
    // new_node->data = malloc(new_data_size);
   
}

void printList(struct List *first, void (*fptr)(void *)) {
    struct List *temp = (struct List *) malloc(sizeof(struct List));
    temp = first;
    while (temp != NULL)
    {
        (*fptr)(temp->data);
        temp = temp->next;
    }

    free(temp);
}

void printClients(void *client) {
    printf("%-12c", *(char *)client->id);
}

struct Person *create_client(char *id, char *name, char *email, int year, int month, int weekday) {
    struct Person *temp = (struct Person *)malloc(sizeof(struct Person));

    // time_t dob = create_timestamp(year, month, weekday, 0, 0, 0, 0);
    strcpy(temp->id, id);
    strcpy(temp->name, name);
    strcpy(temp->email, email);
    temp->date_of_birth = create_timestamp(year, month, weekday, 0, 0, 0, 0);

    return temp;
}
// struct person* create_client_list() {
//     struct person *current;
//     current = (struct person *)malloc(sizeof(struct person));
//     if (current == NULL) {
//         fprintf(stderr, "Couldn't allocate memory");
//         exit(1);
//     }

//     return current;
// }

// void clear_client_list(struct person *first) {
//     struct person *temp;

//     // free every item but the last
//     while (first->next != NULL) {
//         temp = first;
//         first = first->next;
//         free(temp);
//     }

//     free(first);
// }

// struct account* create_account_list() {
//     struct account *acc;
//     acc = (struct account *)malloc(sizeof(struct account));
//     if (acc == NULL) {
//         fprintf(stderr, "Couldn't allocate memory");
//         exit(1);
//     }

//     return acc;
// }

// void clear_account_list(struct account *first) {
//     struct account *temp;

//     // free every item but the last
//     while (first->next != NULL) {
//         temp = first;
//         first = first->next;
//         free(temp);
//     }

//     free(first);
// }

// struct transaction* create_transaction_list() {
//     struct transaction *item;
//     item = (struct transaction *)malloc(sizeof(struct transaction));
//     if (item == NULL) {
//         fprintf(stderr, "Couldn't allocate memory");
//         exit(1);
//     }

//     return item;
// }

// void clear_transaction_list(struct transaction *first) {
//     struct transaction *temp;

//     // free every item but the last
//     while (first->next != NULL) {
//         temp = first;
//         first = first->next;
//         free(temp);
//     }

//     free(first);
// }
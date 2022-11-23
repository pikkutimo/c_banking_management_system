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

struct Person* create_client(char *id, char *name, char *email, int year, int month, int weekday) {
    struct Person *temp = (struct Person *) malloc(sizeof(struct Person));
    snprintf(temp->id, sizeof(id), "%s", id);
    snprintf(temp->name, sizeof(name), "%s", name);
    snprintf(temp->email, sizeof(email), "%s", email);
    temp->date_of_birth = create_timestamp(year, month, weekday, 0, 0, 0, 0);

    return temp;
}

void insertClient(struct Clients **current, struct Person *person) {
    struct Clients *new_client = NULL;
    new_client = (struct Clients *) malloc(sizeof(struct Clients));
    if (new_client == NULL) {
        fprintf(stderr, "Can't allocate memory.\n");
        exit(1);
    }

    snprintf(new_client->client.id, sizeof(new_client->client.id), "%s", person->id);
    snprintf(new_client->client.name, sizeof(new_client->client.name), "%s", person->name);
    snprintf(new_client->client.email, sizeof(new_client->client.email), "%s", person->email);
    new_client->client.date_of_birth = person->date_of_birth;
    new_client->next = NULL;

    new_client->next = *current;
    *current = new_client;
}

void printClients(struct Clients *current) {
    if (current == NULL) {
        printf("The client list is empty.\n");
        return;
    }

    struct Clients *temp = current;
    int i = 0;

    while(temp) {
        i++;
        printf("%-15s\n", temp->client.id);
        temp = temp->next;    
    }

    printf("The list contains %d elements.\n", i);
}
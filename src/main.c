#include "bms_utils.h"
#include<string.h>


int main(int argc, char *argv[]) {

    // Create an array to write to file
    person **clients;
    clients = (person **) malloc(sizeof(person *) * 5);
    if (clients == NULL) {
        fprintf(stderr, "Couldn't allocate memory");
        exit(1);
    }

    int i = 0;

    for (; i < 5; i++) {
        clients[i] = (person *) malloc(sizeof(person) * 1);
        if (clients[i] == NULL) {
            fprintf(stderr, "Couldn't allocate memory for %d\n", i);
            exit(1);
        }
    }

    time_t dob1 = create_timestamp(1975, 2, 26, 0, 0, 0, 0);
    time_t dob2 = create_timestamp(1980, 3, 25, 0, 0, 0, 0);
    time_t dob3 = create_timestamp(1985, 4, 24, 0, 0, 0, 0);
    time_t dob4 = create_timestamp(1990, 5, 23, 0, 0, 0, 0);
    time_t dob5 = create_timestamp(1995, 6, 22, 0, 0, 0, 0);

    // clients[0] = (person *) malloc(sizeof(person) * 1);
    strcpy(clients[0]->id,"0000000001\0");
    strcpy(clients[0]->name,"Simo Vilen\0");
    strcpy(clients[0]->email,"pikkutimo@gmail.com\0");
    clients[0]->date_of_birth = dob1;

    // clients[1] = (person *) malloc(sizeof(person) * 1);
    strcpy(clients[1]->id,"0000000002\0");
    strcpy(clients[1]->name,"Timo Silen\0");
    strcpy(clients[1]->email,"pikkutimo@gmail.com\0");
    clients[1]->date_of_birth = dob2;

    // clients[2] = (person *) malloc(sizeof(person) * 1);
    strcpy(clients[2]->id,"0000000003\0");
    strcpy(clients[2]->name,"Simo Silen\0");
    strcpy(clients[2]->email,"pikkutimo@gmail.com\0");
    clients[2]->date_of_birth = dob3;

    // clients[3] = (person *) malloc(sizeof(person) * 1);
    strcpy(clients[3]->id,"0000000004\0");
    strcpy(clients[3]->name,"Toni Vilen\0");
    strcpy(clients[3]->email,"pikkutimo@gmail.com\0");
    clients[3]->date_of_birth = dob4;

    // clients[4] = (person *) malloc(sizeof(person) * 1);
    strcpy(clients[4]->id,"0000000005\0");
    strcpy(clients[4]->name,"Toni Silen\0");
    strcpy(clients[4]->email,"pikkutimo@gmail.com\0");
    clients[4]->date_of_birth = dob5;

    for (i = 0; i < 5; i++) {
        printf("PERSON %-15s%-32s%-32s%-30s\n", clients[i]->id, clients[i]->name, clients[i]->email, ctime(&clients[i]->date_of_birth));
    }

    for (i = 0; i < 5; i++) {
        free(clients[i]);
    }

    // free(clients);

}
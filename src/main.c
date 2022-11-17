#include "bms_utils.h"
#include<string.h>


int main(int argc, char *argv[]) {

    // const char *persons_file_name = "persons.dat";

    person *clients[5];

    time_t dob1 = create_timestamp(1975, 2, 26, 0, 0, 0, 0);

    strcpy(clients[0]->id,"0000000001\0");
    strcpy(clients[0]->name,"Timo Vilen\0");
    strcpy(clients[0]->email,"pikkutimo@gmail.com\0");
    clients[0]->date_of_birth = dob1;

    for (int i = 0; i < 1; i++) {
        printf("PERSON %-15s%-32s%-32s%-30s\n", clients[i]->id, clients[i]->name, clients[i]->email, ctime(&clients[i]->date_of_birth));
    }

    return 0;
}
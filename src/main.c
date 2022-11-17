#include "bms_utils.h"
#include<string.h>


int main(int argc, char *argv[]) {

    // const char *persons_file_name = "persons.dat";
    // const char *accounts_file_name = "accounts.dat";
    // const char *ledger_file_name = "ledger.dat";

    person *clients[5];
    // account **accounts;
    // transaction **ledger;

    // FILE *pfile;

    time_t dob1 = create_timestamp(1975, 2, 26, 0, 0, 0, 0);
    // time_t dob2 = create_timestamp(1985, 2, 26, 0, 0, 0, 0);
    // time_t dob3 = create_timestamp(1995, 2, 26, 0, 0, 0, 0);

    strcpy(clients[0]->id,"0000000001\0");
    strcpy(clients[0]->name,"Timo Vilen\0");
    strcpy(clients[0]->email,"pikkutimo@gmail.com\0");
    clients[0]->date_of_birth = dob1;

    for (int i = 0; i < 1; i++) {
        printf("PERSON %-15s%-32s%-32s%-30s\n", clients[i]->id, clients[i]->name, clients[i]->email, ctime(&clients[i]->date_of_birth));
    }

    

    // time_t doc = create_timestamp(2020, 0, 1, 0, 0, 0, 0);
    // account t_account = {"12345678912\0", "0000000000\0", "123.34", doc};

    // printf("ACCOUNT %-15s%-15s%-20s%-30s\n", t_account.account_no, t_account.owner, t_account.balance, ctime(&t_account.date_of_creation));

    // time_t dtot = create_timestamp(2022, 10, 16, 1, 30, 0, 0);
    // transaction trans = {dtot, "12345678912\0", "12345678912\0", "100.00", "0000000000\0"};

    // printf("TRANSACTION %-25s%-15s%-15s%-15s%-15s\n", ctime(&trans.transaction_time), trans.sender, trans.receiver, trans.transaction_value, trans.signee);

    return 0;
}
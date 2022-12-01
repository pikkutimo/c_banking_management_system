#include "bms_utils.h"


int main(int argc, char *argv[]) {

struct Node *client_head = NULL, *client_tail = NULL;
unsigned clients_size = sizeof(struct Person);

struct Person *client1 = create_client("000001001\0", "Alli Halonen\0", "alli@simo.com\0", 1975, 2, 1);
struct Person *client2 = create_client("000020001\0", "Bertta Permanto\0", "bertta@timo.com\0", 1965, 4, 23);
struct Person *client3 = create_client("000021001\0", "Caleb Kuolema\0", "caleb@simo.com\0", 1945, 2, 1);
struct Person *client4 = create_client("000220001\0", "Daavid Jauhiainen\0", "daavid@timo.com\0", 2020, 4, 23);

insert_head(&client_head, &client_tail, client3, clients_size);
insert_head(&client_head, &client_tail, client2, clients_size);
insert_head(&client_head, &client_tail, client1, clients_size);
insert_head(&client_head, &client_tail, client4, clients_size);

print_list(client_head, print_client);

merge_sort(&client_head, compare_names);
print_list(client_head, print_client);

struct Node *account_head = NULL, *account_tail = NULL;
unsigned accounts_size = sizeof(struct Account);

struct Account *account1 = create_account("1001001", "000001001");
struct Account *account2 = create_account("2001001", "000020001");
struct Account *account3 = create_account("3001001", "000021001");
struct Account *account4 = create_account("4001001", "000220001");

insert_head(&account_head, &account_tail, account1, accounts_size);
insert_head(&account_head, &account_tail, account2, accounts_size);
insert_head(&account_head, &account_tail, account3, accounts_size);
insert_head(&account_head, &account_tail, account4, accounts_size);

print_list(account_head, print_account);

struct Node *transaction_head = NULL, *transaction_tail = NULL;
unsigned transactions_size = sizeof(struct Account);

struct Transaction *tran1 = create_transaction("000001001", "000020001", 100);
struct Transaction *tran2 = create_transaction("000001001", "000020001", 100);
struct Transaction *tran3 = create_transaction("000020001", "000001001", 100);
struct Transaction *tran4 = create_transaction("000020001", "000001001", 100);

time_t date1 = create_timestamp(1999, 1, 2, 12, 34, 2, 0);
time_t date2 = create_timestamp(1979, 1, 2, 12, 34, 2, 0);
time_t date3 = create_timestamp(1939, 1, 2, 12, 34, 2, 0);

edit_transaction_date(tran1, date1);
edit_transaction_date(tran2, date2);
edit_transaction_date(tran3, date3);

struct Transaction *tran5 = create_transaction2(account1, account2, 1200);

insert_head(&transaction_head, &transaction_tail, tran1, transactions_size);
insert_head(&transaction_head, &transaction_tail, tran2, transactions_size);
insert_head(&transaction_head, &transaction_tail, tran3, transactions_size);
insert_head(&transaction_head, &transaction_tail, tran4, transactions_size);
insert_head(&transaction_head, &transaction_tail, tran5, transactions_size);

print_list(transaction_head, print_transaction);

merge_sort(&transaction_head, compare_date);
print_list(transaction_head, print_transaction);

clear_list(&client_head, &client_tail);
clear_list(&account_head, &account_tail);
clear_list(&transaction_head, &transaction_tail);


return 0;
}
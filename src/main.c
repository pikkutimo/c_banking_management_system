#include "bms_utils.h"


int main(int argc, char *argv[]) {

struct Node *client_head = NULL, *client_tail = NULL;
unsigned clients_size = sizeof(struct Person);
client_head = NULL;
client_tail = NULL;
struct Person *client1 = create_client("000001001\0", "Alli Halonen\0", "alli@simo.com\0", 1975, 2, 1);
struct Person *client2 = create_client("000020001\0", "Bertta Permanto\0", "bertta@timo.com\0", 1965, 4, 23);
struct Person *client3 = create_client("000021001\0", "Caleb Kuolema\0", "caleb@simo.com\0", 1945, 2, 1);
struct Person *client4 = create_client("000220001\0", "Daavid Jauhiainen\0", "daavid@timo.com\0", 2020, 4, 23);

insert_head(&client_head, &client_tail, client1, clients_size);
insert_head(&client_head, &client_tail, client2, clients_size);
insert_head(&client_head, &client_tail, client3, clients_size);
insert_head(&client_head, &client_tail, client4, clients_size);

printList(client_head, printClient);

clear_list(&client_head, &client_tail);


return 0;
}
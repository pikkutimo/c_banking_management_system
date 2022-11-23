#include "bms_utils.h"
#include<string.h>


int main(int argc, char *argv[]) {

struct Person *client1 = create_client("000000001\0", "Simo\0", "simo@simo.com\0", 1975, 2, 1);
struct Person *client2 = create_client("000000002\0", "Timo\0", "timo@timo.com\0", 2000, 4, 23);

struct List *current = NULL; 
struct List *first = NULL;
push(current, first, client1);

printList(first, printClients);

return 0;
}
#include "bms_utils.h"
#include<string.h>


int main(int argc, char *argv[]) {

struct Clients *current = NULL;
struct Person *client1 = create_client("1\0", "Simo\0", "simo@simo.com\0", 1975, 2, 1);
struct Person *client2 = create_client("25\0", "Timo\0", "timo@timo.com\0", 2000, 4, 23);

printf("3\n");
insertClient(&current, client1);
insertClient(&current, client2);
printClients(current);

return 0;
}
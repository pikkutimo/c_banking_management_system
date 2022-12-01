#include "bms_utils.h"

time_t create_timestamp(int year, int month, int weekday, int hour, int min, int sec, int isdst) {
    // These values should be validated accordingly
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
    // Let's leave this assert here and leave the input validation to the
    // function, where the name and email are provided.
    assert(strlen(name) > 0 && strlen(email) > 0);
    struct Person *temp = (struct Person *) malloc(sizeof(struct Person));
    strcpy(temp->id, id);
    strcpy(temp->name, name);
    strcpy(temp->email, email);
    temp->date_of_birth = create_timestamp(year, month, weekday, 0, 0, 0, 0);

    return temp;
}

struct Account* create_account(char *acc_no, char *owner_id) {
    assert(strlen(acc_no) > 0 && strlen(owner_id) > 0);
    struct Account *temp = (struct Account *) malloc(sizeof(struct Account));
    strcpy(temp->account_no, acc_no);
    strcpy(temp->owner, owner_id);
    temp->balance = 0;
    
    temp->date_of_creation = time(NULL);

    return temp;
}

struct Transaction* create_transaction(char *sender, char *receiver, uint64_t amount) {
    assert(strlen(sender) > 0 && strlen(receiver) > 0 && amount > 0);
    struct Transaction *temp = (struct Transaction *) malloc(sizeof(struct Transaction));
    strcpy(temp->sender, sender);
    strcpy(temp->receiver, receiver);
    temp->amount = amount;
    
    temp->date_of_transaction = time(NULL);

    return temp;
}

struct Transaction* create_transaction2(struct Account *sender, struct Account *receiver, 
                            uint64_t amount) {
    assert(strlen(sender->account_no) > 0 && strlen(receiver->account_no) > 0 && amount >= 0);
    struct Transaction *temp = (struct Transaction *) malloc(sizeof(struct Transaction));
    strcpy(temp->sender, sender->account_no);
    strcpy(temp->receiver, receiver->account_no);
    temp->amount = amount;
    
    temp->date_of_transaction = time(NULL);

    return temp;                           
    
}

void edit_transaction_date(struct Transaction *transaction, time_t new_date) {
    transaction->date_of_transaction = new_date;
}

void print_list(struct Node *node, void (*fptr)(void *)) { 
    if (node == NULL)
        printf("The list is empty, nothing to print.\n");
    while (node != NULL) { 
        (*fptr)(node->data); 
        node = node->next; 
    }
    printf("\n");
}

void print_node(struct Node *node, void (*fptr)(void *)) {
    if (node == NULL)
        printf("The node is empty, nothing to print.\n");
    else
        (*fptr)(node->data);
}

// Function to print a Data struct
void print_client(void *data) {
    struct Person temp = *(struct Person *)data;

    printf("%15s %32s %32s %20ld\n", 
    temp.id,
    temp.name,
    temp.email,
    temp.date_of_birth);
}

void print_account(void *data) {
    struct Account temp = *(struct Account *)data;

    printf("%-15s%-32s%-32ju%-20ld\n", 
    temp.account_no,
    temp.owner,
    temp.balance,
    temp.date_of_creation);
}

void print_transaction(void *data) {
    struct Transaction temp = *(struct Transaction *)data;

    printf("%-15s%-32s%-32ju%-20ld\n", 
    temp.sender,
    temp.receiver,
    temp.amount,
    temp.date_of_transaction);
}
// Function to add a node at the beginning of Double Linked List. 
// This function expects a pointer to the data to be added 
// and size of the data type. 
void insert_head(struct Node** head_ref, struct Node** tail_ref, void *new_data, size_t data_size) 
{ 
    // previous     current     next
    // -------      -------     -------
    // |     | ->   |     | ->  |     |
    // -------      -------     -------

    // Allocate memory for node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data  = malloc(data_size);
    if (new_node == NULL || new_node->data == NULL) {
        fprintf(stderr, "Couln't allocate memory.\n");
        exit(1);
    }    
     
    memcpy(new_node->data, new_data, data_size);
    // Alter the pointers accordingly 
    new_node->next = (*head_ref);
    new_node->previous = NULL;

    if (*(head_ref) != NULL) {
        (*head_ref)->previous = new_node;
    }

    (*head_ref) = new_node;

    if (*(tail_ref) == NULL)
        (*tail_ref) = new_node;
}

void insert_tail(struct Node** head_ref, struct Node** tail_ref, void *new_data, size_t data_size) 
{ 
    // Allocate memory for node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data  = malloc(data_size);
    if (new_node == NULL || new_node->data == NULL) {
        fprintf(stderr, "Couldn't allocate memory.\n");
        exit(1);
    }

    // Copy contents of new_data to newly allocated memory. 
    memcpy(new_node->data, new_data, data_size);

    new_node->next = NULL; 
    new_node->previous = (*tail_ref);
    (*tail_ref)->next = new_node;
    (*tail_ref) = new_node;

}
// Insert_middle inserts new node to be next from the previous node
void insert_middle(struct Node **tail_ref, struct Node *previous_node, void *new_data, size_t data_size) 
{ 
    if (previous_node == NULL) {
        fprintf(stderr, "The previous node can't be NULL.\n");
        return;
    }

    // Allocate memory for node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data  = malloc(data_size);
    // Copy contents of new_data to newly allocated memory.  
    memcpy(new_node->data, new_data, data_size);

    // Make the necessary alteration to the next and previous pointers of the new_node
    if (previous_node->next == NULL) {
        //the previous node is the tail
        new_node->next = NULL; 
        new_node->previous = (*tail_ref);
        (*tail_ref)->next = new_node;
        (*tail_ref) = new_node;
    } else {
        new_node->previous = previous_node;
        new_node->next = previous_node->next;
        previous_node->next = new_node;
    }

}

int get_list_lenght(struct Node *head_ref) {
    if (head_ref == NULL) {
        return 0;
    }

    struct Node *current = head_ref;
    int count = 0;

    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void delete_node(struct Node **head_ref, struct Node **tail_ref, struct Node *node_to_delete) {

    // If the node to be deleted is the head
    if (node_to_delete == *(head_ref)) {
       (*head_ref) = node_to_delete->next;
       (*head_ref)->previous = NULL; 
    } else if (node_to_delete == *(tail_ref)) {
        // If the node to be deleted is the tail
        (*tail_ref) = node_to_delete->previous;
        (*tail_ref)->next = NULL;
    } else {
        // If the node to be deleted is something else
       node_to_delete->previous->next = node_to_delete->next;
       node_to_delete->next->previous = node_to_delete->previous;
    }

    free(node_to_delete);
}

int compare_names(const void *a, const void *b) {
    struct Person *pa = (struct Person *)a;
    struct Person *pb = (struct Person *)b;
    
    return strcmp(pa->name, pb->name);
}

int compare_date(const void *a, const void *b) {
    struct Transaction *pa = (struct Transaction *)a;
    struct Transaction *pb = (struct Transaction *)b;

    return pa->date_of_transaction - pb->date_of_transaction;
}

void middle(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;
    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    // 'slow' is before the midpoint in the list, so split it in two at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

struct Node* sorted_merge(struct Node* a, struct Node* b, int (*compar)(const void*, const void*))
{
    struct Node* result = NULL;
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (compar(a->data, b->data) <= 0) {
        result = a;
        result->next = sorted_merge(a->next, b, compar);
    }
    else {
        result = b;
        result->next = sorted_merge(a, b->next, compar);
    }
    return (result);
}

// sorts the linked list by changing links
// recursive function that splits the list into smaller pieces,
// compares pairs and sends them to the function to be merged
void merge_sort(struct Node** headRef, int (*compar)(const void*, const void*)){
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;
    // Base case -- length 0 or 1
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    middle(head, &a, &b);
    merge_sort(&a, compar);
    merge_sort(&b, compar);
    *headRef = sorted_merge(a, b, compar);
}

void clear_list(struct Node **head_ref, struct Node **tail_ref) {
    struct Node *to_delete;

    while (*(head_ref) != NULL) {
        to_delete = (*head_ref);
        (*head_ref) = to_delete->next;
        free(to_delete->data);
        free(to_delete);
    }

    (*tail_ref) = (*head_ref);
}

// void handle_transaction(struct Transaction *transaction, struct Node *account_head) {
//     struct Node *current = account_head;
//     struct Account *current_account;

//     while(current != NULL) {
//         current_account = current->data;
//         if (strcmp(current_account->account_no, transaction->receiver) == 0) {
//             // Credit the current accout
//         } else if (strcmp(current_account->account_no, transaction->sender) == 0) {
//             // Debit the current account
//         }
//     } 
// }
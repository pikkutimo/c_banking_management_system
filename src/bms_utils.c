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
    // snprintf(temp->id, sizeof(id), "%s", id);
    // snprintf(temp->name, sizeof(name), "%s", name);
    // snprintf(temp->email, sizeof(email), "%s", email);
    strcpy(temp->id, id);
    strcpy(temp->name, name);
    strcpy(temp->email, email);
    temp->date_of_birth = create_timestamp(year, month, weekday, 0, 0, 0, 0);

    return temp;
}

struct Account* create_account(char *acc_no, char *owner_id) {
    struct Account *temp = (struct Account *) malloc(sizeof(struct Account));
    strcpy(temp->account_no, acc_no);
    strcpy(temp->owner, owner_id);
    strcpy(temp->balance, "0");
    
    temp->date_of_creation = time(NULL);

    return temp;
}

struct Transaction* create_transaction(char *sender, char *receiver, char *amount) {
    struct Transaction *temp = (struct Transaction *) malloc(sizeof(struct Transaction));
    strcpy(temp->sender, sender);
    strcpy(temp->receiver, receiver);
    strcpy(temp->amount, amount);
    
    temp->date_of_transaction = time(NULL);

    return temp;
}

void printList(struct Node *node, void (*fptr)(void *)) { 
    if (node == NULL)
        printf("The list is empty, nothing to print.\n");
    while (node != NULL) { 
        (*fptr)(node->data); 
        node = node->next; 
    }
    printf("\n");
}

void printNode(struct Node *node, void (*fptr)(void *)) {
    if (node == NULL)
        printf("The node is empty, nothing to print.\n");
    else
        (*fptr)(node->data);
}

// Function to print a Data struct
void printClient(void *data) {
    struct Person temp = *(struct Person *)data;

    printf("%15s %32s %32s %20ld\n", 
    temp.id,
    temp.name,
    temp.email,
    temp.date_of_birth);
}

void printAccount(void *data) {
    struct Account temp = *(struct Account *)data;

    printf("%-15s%-32s%-32s%-20ld\n", 
    temp.account_no,
    temp.owner,
    temp.balance,
    temp.date_of_creation);
}

void printTransaction(void *data) {
    struct Transaction temp = *(struct Transaction *)data;

    printf("%-15s%-32s%-32s%-20ld\n", 
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
    // Allocate memory for node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data  = malloc(data_size);
    if (new_node == NULL || new_node->data == NULL) {
        fprintf(stderr, "Couln't allocate memory.\n");
        exit(1);
    }    
     
    // Copy contents of new_data to newly allocated memory. 
    // Assumption: char takes 1 byte. 
    // int i; 
    // for (i=0; i<data_size; i++) 
    //     *(char *)(new_node->data + i) = *(char *)(new_data + i); 
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
    // Assumption: char takes 1 byte. 
    int i; 
    for (i=0; i<data_size; i++) 
        *(char *)(new_node->data + i) = *(char *)(new_data + i); 

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
    // Assumption: char takes 1 byte. 
    int i; 
    for (i=0; i<data_size; i++) 
        *(char *)(new_node->data + i) = *(char *)(new_data + i);

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

int compareNames(const struct Person *a, const struct Person *b) {
    return strcmp(a->name, b->name);
}

int compareDate(const struct Transaction *a, const struct Transaction *b) {
    return a->date_of_transaction - b->date_of_transaction;
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

struct Node* SortedMerge(struct Node* a, struct Node* b, int (*compar)(const void*, const void*))
{
    struct Node* result = NULL;
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (compar(a->data, b->data) <= 0) {
        result = a;
        result->next = SortedMerge(a->next, b, compar);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next, compar);
    }
    return (result);
}

// sorts the linked list by changing links
// recursive function that splits the list into smaller pieces,
// compares pairs and sends them to the function to be merged
void MergeSort(struct Node** headRef, int (*compar)(const void*, const void*)){
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;
    // Base case -- length 0 or 1
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    middle(head, &a, &b);
    MergeSort(&a, compar);
    MergeSort(&b, compar);
    *headRef = SortedMerge(a, b, compar);
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
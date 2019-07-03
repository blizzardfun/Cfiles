#include <stdio.h>
#include <stdlib.h>

typedef struct node   // list node
{
    int val;
    struct node * next;
} node_t;

// print the list in order
void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d", current->val);
        current = current->next;
    }
    printf("\n");
}

// pop the head of the current tree (using pointers so tree is altered)and return its node value
int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    // tree is already empty
    if (*head == NULL) {
        return -1;
    }

    // remove node
    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

// remove the node with the given value 
// list is traversed until value is found and then pop function is called to remove node
int remove_by_value(node_t ** head, int val) {
    if ((*head) -> val == val){
        pop(head);
    }
    else{
        node_t * current = *head;
        // stop loop when end is reached or one before desired node
        while ( current->next != NULL && current->next->val != val ){
            current = current->next;
        }
        if (current->next == NULL ) { // end was reached
            return -1;
        }
        pop(&(current->next));
        return 1;
    }
        
}

int main() {
 // allocate list and initialize values
    node_t * test_list = malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = malloc(sizeof(node_t));
    test_list->next->next->next->next->val = 5;
    test_list->next->next->next->next->next = NULL;

    printf("Initial list\n");
    print_list(test_list);
    remove_by_value(&test_list, 3);
    printf("Final list with 3 removed\n");
    print_list(test_list);
}
#include "stack.h"

stack *init(const int data) {
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->num = data;
    temp->next = NULL;
    return temp;
}

void push(stack **head, const int data) {
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->num = data;
    temp->next = *head;
    *head = temp;
}
int pop(stack **head) {
    stack *temp = NULL;
    int value = -1;
    if (head != NULL) {
        temp = (*head)->next;
        value = (*head)->num;
        free(*head);
        *head = temp;
    }
    return value;
}
void destroy(stack *head) {
    stack *prev = NULL;
    while (head) {
        prev = head;
        head = head->next;
        free(prev);
    }
    free(head);
}

// init, push, pop, destroy

#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include <stdio.h>
#include <stdlib.h>
#define INIT 1
#define POP1 2
#define POP2 3
#define POP3 4

typedef struct stack {
    int num;
    struct stack *next;
} stack;
stack *init(const int data);
void push(stack **head, const int data);
int pop(stack **head);
void destroy(stack *head);
#endif  // SRC_STACK_H_

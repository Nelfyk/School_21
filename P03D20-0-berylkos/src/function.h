#ifndef SRC_FUNCTION_H_
#define SRC_FUNCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define OPER 12
typedef struct stack {
    int prior;  // приоритет
    char oper;  // операнд
    struct stack *next;
} stack;
typedef struct queue {
    int type;       // 0 or 1
    char makeOper;  // 0
    double makeNum;    // 1
    struct queue *next;
} queue;

int inputS(char *a);
void pushQueue(queue **head, const int type, const char makeOper, const double makeNum);
void pushStack(stack **head, const int prior, const char oper);
void destroy(stack *head);
char pop(stack **head);
char popQ(queue **head);
void output(const stack *headStack, const queue *headQueue, int choice);

stack *initStack();
queue *initQueue();
void initResult(queue **headResult, queue **headQueue);

void parse(char *a, int length, stack **headQueue, queue **headStack);
double result(queue *headResult);
#endif  // SRC_FUNCTION_H_


/*
sin(x) 
cos(x) 
tan(x) 
ctg(x) 
sqrt(x) 
ln(x)
*/
#include "stack.h"
void output(const stack *head);

int main() {
    printf("--==INI FUNCTION==--\n");
    stack *head = init(INIT);
    printf("IN:\n >%d\n", INIT);
    printf("OUT: \n >");
    output(head);
    (head->num == INIT) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));

    printf("\n--==PUSH FUNCTION==--");
    printf("\nIN:\n >%d\n", POP1);
    push(&head, POP1);
    printf("OUT: \n >");
    output(head);
    (head->num == POP1) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));

    printf("\nIN:\n >%d\n", POP2);
    push(&head, POP2);
    printf("OUT: \n >");
    output(head);
    (head->num == POP2) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));

    printf("\nIN:\n >%d\n", POP3);
    push(&head, POP3);
    printf("OUT: \n >");
    output(head);
    (head->num == POP3) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));

    printf("\n--==POP FUNCTION==--\n");
    printf("OUT: \npop:%d\n >", pop(&head));
    output(head);

    printf("\nOUT: \npop:%d\n >", pop(&head));
    output(head);

    printf("\nOUT: \npop:%d\n >", pop(&head));
    output(head);

    printf("\nOUT: \npop:%d\n >", pop(&head));
    output(head);

    destroy(head);
    return 0;
}

void output(const stack *head) {
    while (head) {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
}

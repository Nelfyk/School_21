#include "list.h"
void output(node *temp, int flag);
int main() {
    //
    door *testDoor1 = (door *)malloc(sizeof(door));
    testDoor1->id = 1;
    testDoor1->status = 1;
    //
    door *testDoor2 = (door *)malloc(sizeof(door));
    testDoor2->id = 2;
    testDoor2->status = 2;
    //
    door *testDoor3 = (door *)malloc(sizeof(door));
    testDoor3->id = 3;
    testDoor3->status = 3;
    //
    door *testDoor4 = (door *)malloc(sizeof(door));
    // testDoor4->id = 4;
    // testDoor4->status = 4;
    //
    node *head = init(testDoor1);
    head = add_door(head, testDoor2);
    (find_door(2, head) != NULL) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
    head = add_door(head, testDoor3);
    (find_door(3, head) != NULL) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
    head = add_door(head, testDoor4);
    (find_door(0, head) != NULL) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
    output(head, 0);
    printf("-------------\n");
    head = remove_door(find_door(3, head), head);
    (find_door(3, head) == NULL) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
    output(head, 0);
    head = remove_door(find_door(2, head), head);
    (find_door(2, head) == NULL) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
    output(head, 0);
    head = remove_door(find_door(0, head), head);
    (find_door(0, head) == NULL) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
    output(head, 0);

    // FREE
    destroy(head);
    free(testDoor1);
    free(testDoor2);
    free(testDoor3);
    free(testDoor4);
    return 0;
}

// OUT
void output(node *temp, int flag) {
    if (temp == NULL) {
        printf("NULL\n");
    } else {
        if (flag) {
            printf("%d, %d\n", temp->door.id, temp->door.status);
        } else {
            while (temp) {
                printf("%d, %d\n", temp->door.id, temp->door.status);
                temp = temp->next;
            }
        }
    }
}

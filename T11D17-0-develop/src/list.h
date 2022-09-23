#ifndef SRC_LIST_H_
#define SRC_LIST_H_
#include "door_struct.h"
typedef struct node {
    door door;
    struct node *next;
} node;
node *init(const door *door);
node *add_door(node *elem, const door *door);
node *find_door(int door_id, node *root);
node *remove_door(const node *elem, node *root);
void destroy(node *root);
#endif  // SRC_LIST_H_

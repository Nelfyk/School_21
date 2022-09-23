#include "list.h"

node *init(const door *door) {  // root = head
    node *temp = (node *)malloc(sizeof(node));
    temp->door = *door;
    temp->next = NULL;
    return temp;
}

node *add_door(node *elem, const door *door) {
    node *temp = (node *)malloc(sizeof(node));
    node *head = elem;
    while (elem->next) {
        elem = elem->next;
    }
    elem->next = temp;
    temp->next = NULL;
    temp->door = *door;
    return head;
}
node *find_door(int door_id, node *root) {
    while (root && root->door.id != door_id) {
        root = root->next;
    }
    return root;
}
node *remove_door(const node *elem, node *root) {
    node *prev = NULL;
    node *head = root;
    if (root == elem) {
        head = root->next;
        free(root);
    } else {
        while (root->next && root != elem) {
            prev = root;
            root = root->next;
        }
        if (root == elem) {
            prev->next = root->next;
            free(root);
        }
    }
    return head;
}
void destroy(node *root) {
    node *prev = NULL;
    while (root->next) {
        prev = root;
        root = root->next;
        free(prev);
    }
    free(root);
}

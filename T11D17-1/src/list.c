#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

node_t* init(struct door* door) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) return NULL;
    new_node->door = door;
    new_node->next = NULL;
    return new_node;
}

node_t* add_door(node_t* elem, struct door* door) {
    if (!elem) return NULL;
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) return NULL;
    new_node->door = door;
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

node_t* find_door(int door_id, node_t* root) {
    while (root) {
        if (root->door->id == door_id) return root;
        root = root->next;
    }
    return NULL;
}

node_t* remove_door(node_t* elem, node_t* root) {
    if (!elem || !root) return NULL;

    if (elem == root) {
        node_t* new_root = root->next;
        free(root);
        return new_root;
    }
    node_t* prev = root;
    while (prev->next && prev->next != elem) {
        prev = prev->next;
    }
    if (prev->next == elem) {
        prev->next = elem->next;
        free(elem);
    }
    return root;
}

void destroy(node_t* root) {
    while (root) {
        node_t* temp = root;
        root = root->next;
        free(temp);
    }
}
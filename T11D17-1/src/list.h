#ifndef LIST_H
#define LIST_H

#include "door_struct.h"

typedef struct door door_t;
typedef struct node {
    door_t* door;
    struct node* next;
} node_t;

node_t* init(door_t* door);

node_t* add_door(node_t* elem, door_t* door);

node_t* find_door(int door_id, node_t* root);

node_t* remove_door(node_t* elem, node_t* root);

void destroy(node_t* root);

#endif
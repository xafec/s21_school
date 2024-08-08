#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

t_stack* init(int value) {
    t_stack* new_node = malloc(sizeof(t_stack));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

t_stack* push(int value, t_stack* root) {
    if (root == NULL) {
        return init(value);
    }
    t_stack* new_node = init(value);
    if (new_node == NULL) {
        return NULL;
    }
    new_node->next = root;
    return new_node;
}

t_stack* pop(t_stack* root) {
    if (root == NULL) {
        return NULL;
    }
    t_stack* temp_node = root;
    root = root->next;
    free(temp_node);
    return root;
}

void destroy(t_stack* root) {
    while (root != NULL) {
        t_stack* temp = root;
        root = root->next;
        free(temp);
    }
}
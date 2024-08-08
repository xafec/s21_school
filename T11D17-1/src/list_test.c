#include "list.h"

#include <stdio.h>

int test_add_door() {
    struct door d1 = {1, 0};
    struct door d2 = {2, 0};
    int result;
    node_t* root = init(&d1);
    add_door(root, &d2);
    if (root->next->door->id == d2.id) {
        result = 1;
    } else {
        result = 0;
    }
    destroy(root);
    return result;
}

int test_remove_door() {
    struct door d1 = {1, 0};
    struct door d2 = {2, 0};
    int result;
    node_t* root = init(&d1);
    node_t* node2 = add_door(root, &d2);

    root = remove_door(node2, root);

    if (!find_door(d2.id, root)) {
        result = 1;
    } else {
        result = 0;
    }

    destroy(root);
    return result;
}

int main() {
    if (test_add_door()) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    if (test_remove_door()) {
        printf("SUCCES");
    } else {
        printf("FAIL\n");
    }
    return 0;
}
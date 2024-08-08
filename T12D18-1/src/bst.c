#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *node = malloc(sizeof(t_btree));
    if (node == NULL) {
        return NULL;
    }
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    if (root == NULL) {
        return;
    }

    if (cmpf(item, root->item) < 0) {
        root->left = bstree_create_node(item);
    } else if (cmpf(item, root->item) > 0) {
        root->right = bstree_create_node(item);
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) {
        return;
    }

    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) {
        return;
    }

    applyf(root->item);
    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) {
        return;
    }

    bstree_apply_postfix(root->left, applyf);
    bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
}
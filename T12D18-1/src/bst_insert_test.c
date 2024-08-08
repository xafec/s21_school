#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int compare(int a, int b);
void test_bst_insert(t_btree *root);

int main() {
    t_btree *root = bstree_create_node(5);
    bstree_insert(root, 10, compare);
    bstree_insert(root, 3, compare);
    test_bst_insert(root);

    free(root);

    return 0;
}

void test_bst_insert(t_btree *root) {
    if (root->left == NULL && root->right == NULL) {
        printf("root: %d\n", root->item);
    }

    else if (root->left == NULL && root->right != NULL) {
        printf("root: %d\n", root->item);
        printf("right: %d\n", root->right->item);
        free(root->right);
    }

    else if (root->left != NULL && root->right == NULL) {
        printf("root: %d\n", root->item);
        printf("left: %d\n", root->left->item);
        free(root->left);
    }

    else if (root->left != NULL && root->right != NULL) {
        printf("root: %d\n", root->item);
        printf("left: %d\n", root->left->item);
        printf("right: %d\n", root->right->item);
        free(root->left);
        free(root->right);
    }
}

int compare(int a, int b) { return a - b; }
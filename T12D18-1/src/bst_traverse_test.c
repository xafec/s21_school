#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void applyf(int item) { printf("%d ", item); }

int compare(int a, int b) { return a - b; }

void free_btree(t_btree *root) {
    if (root == NULL) {
        return;
    }
    free_btree(root->left);
    free_btree(root->right);
    free(root);
}

int main() {
    t_btree *root = bstree_create_node(5);
    bstree_insert(root, 10, compare);
    bstree_insert(root, 3, compare);
    printf("infix - элементы отобразятся по возрастанию(левое поддерево->корень->правое поддерево)\n");
    bstree_apply_infix(root, applyf);
    printf(
        "\nprefix - элементы отобразятся в том же порядке, что хранятся(корень->левое поддерево->правое "
        "поддерево)\n");
    bstree_apply_prefix(root, applyf);
    printf("\npostfix - элементы отобразятся по убыванию(левое поддерево->правое поддерево->корень)\n");
    bstree_apply_postfix(root, applyf);

    free_btree(root);
    return 0;
}
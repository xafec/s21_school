#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    t_btree *root = bstree_create_node(5);
    printf("root: %d\n", root->item);
    free(root);
    return 0;
}

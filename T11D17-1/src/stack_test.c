#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int test_init() {
    t_stack* stack = init(10);
    if (stack == NULL) {
        return 0;
    }
    if (stack->value != 10 || stack->next != NULL) {
        destroy(stack);
        return 0;
    }
    destroy(stack);
    return 1;
}

int test_push() {
    t_stack* stack = init(10);
    stack = push(20, stack);
    if (stack == NULL) {
        return 0;
    }
    if (stack->value != 20 || stack->next->value != 10) {
        destroy(stack);
        return 0;
    }
    destroy(stack);
    return 1;
}

int test_pop() {
    t_stack* stack = init(10);
    stack = push(20, stack);
    stack = pop(stack);
    if (stack == NULL) {
        return 0;
    }
    if (stack->value != 10) {
        destroy(stack);
        return 0;
    }
    destroy(stack);
    return 1;
}

int main() {
    printf("Test init: %s\n", test_init() ? "SUCCESS" : "FAIL");
    printf("Test push: %s\n", test_push() ? "SUCCESS" : "FAIL");
    printf("Test pop: %s\n", test_pop() ? "SUCCESS" : "FAIL");
    return 0;
}
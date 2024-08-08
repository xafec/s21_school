#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shunting.h"
#include "stacks.h"

#define eps 1e-5

int isdigitly(char ch) { return ((ch >= '0') && (ch <= '9')); }

double needsomexppls(char output[SIZE_EXP][SIZE_EXP], double x) {
    struct stack_for_draw stack;
    stack.top = -1;
    double a, b;
    char token[SIZE_EXP];

    for (int i = 0; output[i][0] != '\0'; i++) {
        strcpy(token, output[i]);

        if (isdigitly(token[0]) || (token[0] == '-' && isdigitly(token[1]))) {
            push_double(&stack, atof(token));
        } else if (strcmp(token, "x") == 0) {
            push_double(&stack, x);
        } else if (strcmp(token, "+") == 0) {
            b = pop_double(&stack);
            a = pop_double(&stack);
            push_double(&stack, a + b);
        } else if (strcmp(token, "-") == 0) {
            b = pop_double(&stack);
            a = pop_double(&stack);
            push_double(&stack, a - b);
        } else if (strcmp(token, "*") == 0) {
            b = pop_double(&stack);
            a = pop_double(&stack);
            push_double(&stack, a * b);
        } else if (strcmp(token, "/") == 0) {
            b = pop_double(&stack);
            a = pop_double(&stack);
            if (b != 0) push_double(&stack, a / b);
        } else if (strcmp(token, "sin") == 0) {
            a = pop_double(&stack);
            push_double(&stack, sin(a));
        } else if (strcmp(token, "cos") == 0) {
            a = pop_double(&stack);
            push_double(&stack, cos(a));
        } else if (strcmp(token, "sqrt") == 0) {
            a = pop_double(&stack);
            if (a >= 0) push_double(&stack, sqrt(a));
        } else if (strcmp(token, "ln") == 0) {
            a = pop_double(&stack);
            if (a > eps) push_double(&stack, log(a));
        }
    }
    double result_val = pop_double(&stack);
    return result_val;
}
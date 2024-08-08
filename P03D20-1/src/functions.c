#include "functions.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stacks.h"

int is_operator(const char *token) {
    return strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 ||
           strcmp(token, "/") == 0;
}

int is_prioritet(const char *op) {
    int flag = 0;
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) flag = 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) flag = 2;
    return flag;
}

int is_function(const char *token) {
    return strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0 ||
           strcmp(token, "ctg") == 0 || strcmp(token, "sqrt") == 0 || strcmp(token, "ln") == 0;
}

int is_digit(char ch) { return ((ch >= '0') && (ch <= '9')) || (ch == 'x'); }

int is_space(char ch) { return (ch == ' '); }

int is_alpha(char ch) { return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); }

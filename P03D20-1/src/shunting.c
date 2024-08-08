#include "shunting.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "stacks.h"

void shunting_yard(const char *input, char output[][SIZE_EXP]) {
    struct stack_for_shunt my_stack;
    my_stack.top = -1;
    char token[SIZE_EXP];
    int out_index = 0;
    char *p = (char *)input;
    char prev_token = '(';
    int err = 0;
    int err2 = 0;

    while (*p != '\0' && err != 1) {
        if (is_space(*p)) {
            p++;
            continue;
        }

        if (is_digit(*p) || (*p == '.' && is_digit(*(p + 1)))) {
            int len = 0;
            while (is_digit(*p) || *p == '.') {
                token[len++] = *p++;
            }
            token[len] = '\0';
            strcpy(output[out_index++], token);
            prev_token = 'n';
            continue;
        }

        if (is_alpha(*p)) {
            int len = 0;
            while (is_alpha(*p)) {
                token[len++] = *p++;
            }
            token[len] = '\0';
            if (is_function(token)) {
                push(&my_stack, token);
            } else {
                err = 1;
            }
            if (err) {
                break;
            }
            prev_token = 'f';
            continue;
        }

        if (*p == '(') {
            token[0] = *p;
            token[1] = '\0';
            push(&my_stack, token);
            p++;
            prev_token = '(';
            continue;
        }

        if (*p == ')') {
            while (my_stack.top >= 0 && strcmp(show_top_elemet(&my_stack), "(") != 0) {
                strcpy(output[out_index++], pop(&my_stack));
            }
            if (my_stack.top < 0) {
                err = 1;
            }
            if (err) {
                break;
            }
            pop(&my_stack);
            if (my_stack.top >= 0 && is_function(show_top_elemet(&my_stack))) {
                strcpy(output[out_index++], pop(&my_stack));
            }
            p++;
            prev_token = ')';
            continue;
        }

        if (*p == '-') {
            if (prev_token == '(' || is_operator((char[]){prev_token, '\0'}) || prev_token == 'f') {
                strcpy(output[out_index++], "0");
                token[0] = '-';
                token[1] = '\0';
            } else {
                token[0] = '-';
                token[1] = '\0';
            }
            p++;
        } else if (is_operator((char[]){*p, '\0'})) {
            token[0] = *p++;
            token[1] = '\0';
        } else {
            err = 1;
        }
        if (err) {
            break;
        }

        while (my_stack.top >= 0 && is_operator(show_top_elemet(&my_stack)) &&
               ((is_operator(token) && is_prioritet(token) <= is_prioritet(show_top_elemet(&my_stack))) ||
                (!is_operator(token) && is_prioritet(token) < is_prioritet(show_top_elemet(&my_stack))))) {
            strcpy(output[out_index++], pop(&my_stack));
        }
        push(&my_stack, token);
        prev_token = token[0];
    }

    while (my_stack.top >= 0 && err2 != 1) {
        if (strcmp(show_top_elemet(&my_stack), "(") == 0 || strcmp(show_top_elemet(&my_stack), ")") == 0) {
            err2 = 1;
        }
        if (err2) {
            break;
        }
        strcpy(output[out_index++], pop(&my_stack));
    }

    output[out_index][0] = '\0';
}
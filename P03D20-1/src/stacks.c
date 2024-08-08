#include "stacks.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(struct stack_for_shunt *s, const char *xp) {
    int stack_top = s->top;
    stack_top += 1;
    strcpy(s->xps[stack_top], xp);
    s->top = stack_top;
}

char *pop(struct stack_for_shunt *s) {
    int stack_top = s->top;
    char *val = s->xps[stack_top];
    stack_top -= 1;
    s->top = stack_top;
    return val;
}

char *show_top_elemet(struct stack_for_shunt *s) {
    int val = s->top;
    return s->xps[val];
}

void push_double(struct stack_for_draw *s, double xp) {
    int stack_top = s->top;
    stack_top += 1;
    s->xps[stack_top] = xp;
    s->top = stack_top;
}

double pop_double(struct stack_for_draw *s) {
    int stack_top = s->top;
    double val;
    val = s->xps[stack_top];
    stack_top -= 1;
    s->top = stack_top;
    return val;
}
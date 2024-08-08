#ifndef STACKS_H
#define STACKS_H

#define SIZE_EXP 1000

struct stack_for_shunt {
    char xps[SIZE_EXP][SIZE_EXP];
    int top;
};

struct stack_for_draw {
    double xps[SIZE_EXP];
    int top;
};

void push(struct stack_for_shunt *s, const char *xp);
char *pop(struct stack_for_shunt *s);
char *show_top_elemet(struct stack_for_shunt *s);

void push_double(struct stack_for_draw *s, double xp);
double pop_double(struct stack_for_draw *s);

#endif
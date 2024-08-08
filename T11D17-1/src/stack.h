#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int value;
    struct stack* next;
} t_stack;

t_stack* init(int value);
t_stack* push(int value, t_stack* root);
t_stack* pop(t_stack* root);
void destroy(t_stack* root);

#endif
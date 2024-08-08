#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int is_operator(const char *token);
int is_prioritet(const char *op);
int is_function(const char *token);
int is_digit(char ch);
int is_space(char ch);
int is_alpha(char ch);

#endif
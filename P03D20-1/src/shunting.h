#ifndef SHUNTING_H_
#define SHUNTING_H_

#define SIZE_EXP 1000

int is_space(char ch);
int is_alpha(char ch);
int is_operator(const char *token);
int precedence(const char *op);
int is_left_associative(const char *op);
int is_function(const char *token);
int is_digit(char ch);
void shunting_yard(const char *input, char output[][SIZE_EXP]);

#endif
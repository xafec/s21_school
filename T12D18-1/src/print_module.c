#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    time_t current_time = time(NULL);
    char time_string[9];
    strftime(time_string, 9, "%H:%M:%S", localtime(&current_time));

    for (int i = 0; Log_prefix[i] != '\0'; ++i) {
        print(Log_prefix[i]);
    }
    print(' ');
    for (int i = 0; time_string[i] != '\0'; ++i) {
        print(time_string[i]);
    }
    print(' ');
    for (int i = 0; message[i] != '\0'; ++i) {
        print(message[i]);
    }
}
#include "documentation_module.h"

#include <stdarg.h>
#include <stdlib.h>

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list args;
    va_start(args, document_count);
    int* document_availability = malloc(sizeof(int) * document_count);
    if (document_availability == NULL) {
        va_end(args);
        return NULL;
    }

    for (int i = 0; i < document_count; ++i) {
        document_availability[i] = validate(va_arg(args, char*));
    }
    va_end(args);
    return document_availability;
}

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

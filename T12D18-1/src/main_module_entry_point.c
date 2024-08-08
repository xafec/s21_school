#include <stdio.h>
#include <stdlib.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef PRINT_MODULE
    print_log(print_char, Module_load_success_message);
#endif

#ifdef DOCUMENTATION_MODULE
    int *document_availability = check_available_documentation_module(validate, Documents_count, Documents);

    char *arr[Documents_count] = {Documents};

    for (int i = 0; i < Documents_count; ++i) {
        printf("%d. %-15s: %s\n", i + 1, arr[i], document_availability[i] ? "available" : "unavailable");
    }

    free(document_availability);
#endif

    return 0;
}

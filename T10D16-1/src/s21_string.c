#include "s21_string.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(char *str) {
    if (str == NULL) {
        return 0;
    }

    size_t len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

int s21_strcmp(char *str1, char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return -1;
    }

    while (*str1 == *str2) {
        if (*str1 == '\0' && *str2 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *s21_strcpy(char *dest, char *src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    char *start = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return start;
}

char *s21_strcat(char *dest, char *src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    char *dest_start = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest_start;
}

char *s21_strchr(char *str, int symbol) {
    if (str == NULL) {
        return NULL;
    }

    while (*str != '\0') {
        if (*str == symbol) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *s21_strstr(char *haystack, char *needle) {
    if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    size_t needle_len = s21_strlen(needle);
    size_t haystack_len = s21_strlen(haystack);

    if (needle_len > haystack_len) {
        return NULL;
    }

    for (size_t i = 0; i < haystack_len; i++) {
        if (haystack[i] == needle[0]) {
            size_t j = 1;
            while (j < needle_len && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == needle_len) {
                return (char *)(haystack + i);
            }
        }
    }
    return NULL;
}

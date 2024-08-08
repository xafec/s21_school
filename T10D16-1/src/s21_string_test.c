#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(char *str, int len);
void s21_strcmp_test(char *str1, char *str2);
void s21_strcpy_test(char *dest, char *src);
void s21_strcat_test(char *dest, char *src, char *result);
void s21_strchr_test(char *str, int symbol);
void s21_strstr_test(char *str, char *needle);

int main() {
#ifdef STRLEN
    printf("s21_strlen test:\n");
    s21_strlen_test("Hello, World!", 13);
    s21_strlen_test("\0", 0);
    s21_strlen_test("\n", 1);
    s21_strlen_test("Lorem Ipsum is simply dummy text", 33);
#endif

#ifdef STRCMP
    printf("\n\n\ns21_strcmp test:\n");
    s21_strcmp_test("Hello, World!", "Hello, World!");
    s21_strcmp_test("Hello, World!", "Hello, World! ");
    s21_strcmp_test("Hello, World!", "Hello, Wo!");
    s21_strcmp_test("Hello, World!", "");
#endif

#ifdef STRCPY
    printf("\n\n\ns21_strcpy test:\n");
    char dest[100] = {0};
    char src[] = "Hello, World!";
    s21_strcpy_test(dest, src);

    char dest1[100] = "0";
    char src1[] = "Lorem Ipsum is simply dummy text";
    s21_strcpy_test(dest1, src1);

    char dest2[100] = "0asdsdfmkmsalkdjgkjashfgd";
    char src2[] = "";
    s21_strcpy_test(dest2, src2);

    char dest3[100] = "Hello, World!";
    char src3[] = "\0";
    s21_strcpy_test(dest3, src3);
#endif

#ifdef STRCAT
    printf("\n\n\ns21_strcat test:\n");
    char dest4[100] = "Hello, World!";
    char src4[] = "Lorem Ipsum is simply dummy text";
    s21_strcat_test(dest4, src4, "Hello, World!Lorem Ipsum is simply dummy text");

    char dest5[100] = "Hello, World!";
    char src5[] = "Hello, World!";
    s21_strcat_test(dest5, src5, "Hello, World!Hello, World!");

    char dest6[100] = "Hello, World!";
    char src6[] = "\0";
    s21_strcat_test(dest6, src6, "Hello, World!\0");
#endif

#ifdef STRCHR
    printf("\n\n\ns21_strchr test:\n");
    char str[] = "Hello, World";
    s21_strchr_test(str, 'H');
    s21_strchr_test(str, 'l');
    s21_strchr_test(str, 'o');
    s21_strchr_test(str, ' ');
    s21_strchr_test(str, '!');
#endif

#ifdef STRSTR
    printf("\n\n\ns21_strstr test:\n");
    char strr1[] = "Hello, World!";
    s21_strstr_test(strr1, "World");
    s21_strstr_test(strr1, "Hello");
    s21_strstr_test(strr1, "World!");
    s21_strstr_test(strr1, "!");
    s21_strstr_test(strr1, "\0");
#endif

    return 0;
}

void s21_strlen_test(char *str, int len) {
    int str_len = s21_strlen(str);
    printf("\n%-50s %-2d-%2d ", str, str_len, len);
    if (str_len == len) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcmp_test(char *str1, char *str2) {
    int str_len = s21_strcmp(str1, str2);
    printf("\n%-50s %-50s ", str1, str2);
    if (str_len == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcpy_test(char *dest, char *src) {
    char *str = s21_strcpy(dest, src);
    printf("\n%-50s %-50s ", dest, src);
    int check = 0;
    for (int i = 0; i < (int)s21_strlen(src); i++) {
        if (str[i] != src[i]) {
            check = 1;
            break;
        } else {
            check = 0;
        }
    }
    if (check == 0 && str != NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcat_test(char *dest, char *src, char *result) {
    printf("\n%-50s %-50s ", dest, src);
    int check = 0;
    char *str = s21_strcat(dest, src);
    for (int i = 0; i < (int)s21_strlen(result); i++) {
        if (str[i] != result[i]) {
            check = 1;
            break;
        } else {
            check = 0;
        }
    }
    if (check == 0 && str != NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strchr_test(char *str, int symbol) {
    printf("\n%-50s %-50c ", str, symbol);
    char *strchr = s21_strchr(str, symbol);
    if (strchr != NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strstr_test(char *str, char *needle) {
    printf("\n%-50s %-50s ", str, needle);
    char *strstr = s21_strstr(str, needle);
    if (strstr != NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
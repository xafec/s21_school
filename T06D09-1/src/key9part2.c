#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input(int *a, int *b, int *length1, int *length2, int *result_length);
void shift(int *a, int *b, int length1, int length2, int *new_length1, int *new_length2);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int buff1[LEN] = {0};
    int buff2[LEN] = {0};
    int length1 = 0, length2 = 0, result_length = 0;
    int result[LEN + 1] = {0};
    if (input(buff1, buff2, &length1, &length2, &result_length)) {
        printf("n/a");
        return 1;
    }
    int new_length1, new_length2;
    shift(buff1, buff2, length1, length2, &new_length1, &new_length2);
    length1 = new_length1;
    length2 = new_length2;

    sum(buff1, length1, buff2, length2, result, &result_length);
    for (int i = 0; i < result_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    sub(buff1, length1, buff2, length2, result, &result_length);
    for (int i = 0; i < result_length; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}

int input(int *a, int *b, int *length1, int *length2, int *result_length) {
    int c;
    for (int *p = a; p - a < LEN; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
        if (*p > 9 || *p < 0) {
            return 1;
        }
        (*length1)++;
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (c != ' ') {
            return 1;
        }
    }
    for (int *p = b; p - b < LEN; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
        if (*p > 9) {
            return 1;
        }
        (*length2)++;
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (c != ' ') {
            return 1;
        }
    }
    if ((*length1 > LEN) || (*length2 > LEN)) {
        return 1;
    }
    if ((*length1) > (*length2)) {
        *result_length = *length1;
    } else {
        *result_length = *length2;
    }
    return 0;
}

void shift(int *a, int *b, int length1, int length2, int *new_length1, int *new_length2) {
    if (length1 > length2) {
        for (int i = length2; i < length1; i++) {
            b[i] = 0;
        }
        for (int i = length2 - 1; i >= 0; i--) {
            b[i] = b[i + (length1 - length2)];
        }
        *new_length1 = length1;
        *new_length2 = length1;
    } else if (length1 < length2) {
        for (int i = length1; i < length2; i++) {
            a[i] = 0;
        }
        for (int i = length1 - 1; i >= 0; i--) {
            a[i] = a[i + (length2 - length1)];
        }
        *new_length1 = length2;
        *new_length2 = length2;
    } else {
        *new_length1 = length1;
        *new_length2 = length2;
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    int k = 0;
    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--, k++) {
        int digit1 = (i >= 0) ? buff1[i] : 0;
        int digit2 = (j >= 0) ? buff2[j] : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k] = sum % 10;
    }
    if (carry) {
        result[k++] = carry;
    }
    *result_length = k;
    for (int i = 0, j = *result_length - 1; i < j; i++, j--) {
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int borrow = 0;
    int k = 0;

    for (int i = len1 - 1, j = len2 - 1; i >= 0; i--, j--, k++) {
        int digit1 = buff1[i];
        int digit2 = (j >= 0) ? buff2[j] : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[k] = diff;
    }
    while (k > 0 && result[k - 1] == 0) {
        k--;
    }
    *result_length = k;
    for (int i = 0, j = *result_length - 1; i < j; i++, j--) {
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
}

#include <stdio.h>
#define NMAX 10

int input(int *a);
void swap(int *a, int *b);
void sort(int *a);
void output(int *a);

int main() {
    int a[NMAX] = {0};
    if (input(a)) {
        return 1;
    }
    sort(a);
    output(a);
    return 0;
}

int input(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        // int c;
        // (c = getchar() != '\n' || c != ' ')
        if (scanf("%d", p) != 1 && getchar() != '\n') {
            printf("n/a");
            return 1;
        }
    }
    if (getchar() != '\n') {
        printf("n/a");
        return 1;
    }

    return 0;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        for (int *q = p + 1; q - a < NMAX; q++) {
            if (*p > *q) {
                swap(p, q);
            }
        }
    }
}

void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        printf("%d ", *p);
    }
}
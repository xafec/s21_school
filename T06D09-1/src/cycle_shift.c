#include <stdio.h>

#define NMAX 10

int input(int *a, int *n, int *shift);
int cycle_shift(int *a, int n, int shift);
void output(int *a, int n);

int main() {
    int n, c = 0, A[NMAX] = {0};
    if (input(A, &n, &c)) {
        printf("n/a");
        return 1;
    }
    cycle_shift(A, n, c);
    output(A, n);
    return 0;
}

int input(int *a, int *n, int *shift) {
    if (scanf("%d", n) == 1 && getchar() == '\n' && *n <= NMAX) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1 && getchar() != '\n') {
                return 1;
            }
        }
        if (getchar() != '\n') {
            return 1;
        }
        if (scanf("%d", shift) != 1 && getchar() != '\n') {
            return 1;
        }
    } else {
        return 1;
    }

    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

int cycle_shift(int *a, int n, int shift) {
    for (int i = 0; i < shift; i++) {
        int first = a[0];
        for (int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = shift > 0 ? first : a[n - 2];
    }

    return 0;
}

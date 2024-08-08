#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void swap(int *a, int *b);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int *a = NULL;
    int n = 0;

    if (input(&a, &n)) {
        return 1;
    }

    sort(a, n);
    output(a, n);

    free(a);
    return 0;
}

int input(int **a, int *n) {
    int flag = 0;
    if (scanf("%d", n) != 1 || *n <= 0) {
        printf("n/a");
        flag = 1;
    }

    if (flag == 0) {
        *a = (int *)malloc(*n * sizeof(int));
        if (*a == NULL) {
            printf("n/a");
            flag = 1;
        }

        if (flag == 0) {
            for (int i = 0; i < *n; i++) {
                if (scanf("%d", &((*a)[i])) != 1) {
                    printf("n/a");
                    free(*a);
                    return 1;
                }
            }
        }
    }

    return flag;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}
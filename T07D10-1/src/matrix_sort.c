#include <stdio.h>
#include <stdlib.h>

int input(int *n, int *m, int *a);
void firstDynamicArray(int, int);
void secondDynamicArray(int, int);
void thirdDynamicArray(int, int);
void input_array_dynamic(int, int, int *, int *);
void sort(int **a, int n, int m);
int row_sum(int **a, int n);
void output_array(int **a, int n, int m);

int main() {
    int n, mode, m = 0;
    if (input(&n, &m, &mode) == 1) {
        return 1;
    }

    if (mode == 1) {
        firstDynamicArray(n, m);
    } else if (mode == 2) {
        secondDynamicArray(n, m);
    } else if (mode == 3) {
        thirdDynamicArray(n, m);
    }
    return 0;
}

int input(int *N, int *M, int *mode) {
    int flag = 0;
    if (scanf("%d", mode) != 1 || *mode < 1 || *mode > 4) {
        printf("n/a");
        flag = 1;
    }

    if (flag == 0) {
        if (scanf("%d %d", N, M) != 2 || *N > 100 || *N < 1 || *M > 100 || *M < 1) {
            printf("n/a");
            flag = 1;
        }
    }

    if (flag == 0) {
        char c = getchar();
        if (c != '\n') {
            printf("n/a");
            flag = 1;
        }
    }

    return flag;
}

void firstDynamicArray(int N, int M) {
    int **single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int *));
    int *ptr = (int *)(single_array_matrix + M);
    for (int i = 0; i < M; i++) {
        single_array_matrix[i] = ptr + N * i;
    }
    int flag = 0;
    input_array_dynamic(N, M, *single_array_matrix, &flag);
    if (flag == 1) {
        printf("n/a");
        return;
    }

    sort(single_array_matrix, N, M);

    output_array(single_array_matrix, N, M);

    free(single_array_matrix);
}
void secondDynamicArray(int N, int M) {
    int **pointer_array = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        pointer_array[i] = malloc(N * sizeof(int));
    }
    int flag = 0;
    input_array_dynamic(N, M, *pointer_array, &flag);
    if (flag == 1) {
        printf("n/a");
        return;
    }

    sort(pointer_array, N, M);

    output_array(pointer_array, N, M);

    for (int i = 0; i < M; i++) {
        free(pointer_array[i]);
    }
    free(pointer_array);
}
void thirdDynamicArray(int N, int M) {
    int **pointer_array = malloc(M * sizeof(int *));
    int *pointer = malloc(M * N * sizeof(int));
    for (int i = 0; i < M; i++) {
        pointer_array[i] = pointer + N * i;
    }
    int flag = 0;
    input_array_dynamic(N, M, *pointer_array, &flag);
    if (flag == 1) {
        printf("n/a");
        return;
    }

    sort(pointer_array, N, M);

    output_array(pointer_array, N, M);

    free(pointer_array);
    free(pointer);
}

void input_array_dynamic(int N, int M, int *data, int *flag) {
    *flag = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", data + i * N + j) != 1) {
                *flag = 1;
            };
        }
    }
}

int row_sum(int **a, int n) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += a[n][j];
    }
    return sum;
}

void sort(int **a, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (row_sum(a, j) > row_sum(a, j + 1)) {
                for (int k = 0; k < m; k++) {
                    int temp = a[j][k];
                    a[j][k] = a[j + 1][k];
                    a[j + 1][k] = temp;
                }
            }
        }
    }
}

void output_array(int **a, int n, int m) {
    for (int i = 0; i < m; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < n; j++) {
            if (i != (m - 1) || j != (n - 1)) {
                printf("%d ", a[i][j]);
            } else {
                printf("%d", a[i][j]);
            }
        }
    }
}
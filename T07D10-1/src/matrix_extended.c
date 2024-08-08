#include <stdio.h>
#include <stdlib.h>

#define MAXI 100
#define MAXJ 100

int input(int *, int *, int *);
void firstDynamicArray(int, int);
void secondDynamicArray(int, int);
void thirdDynamicArray(int, int);
void staticArray(int N, int M, int data[MAXI][MAXJ]);
void input_array_static(int N, int M, int data[MAXI][MAXJ], int *flag);
void input_array_dynamic(int, int, int *, int *);
void max_min_in_static(int N, int M, int data[MAXI][MAXJ]);
void max_min_in_dynamic(int N, int M, int *);

int main() {
    int N, M, mode, arr[MAXI][MAXJ];
    if (input(&N, &M, &mode) == 1) {
        return 1;
    }
    if (mode == 1) {
        staticArray(N, M, arr);
    } else if (mode == 2) {
        firstDynamicArray(N, M);
    } else if (mode == 3) {
        secondDynamicArray(N, M);
    } else if (mode == 4) {
        thirdDynamicArray(N, M);
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
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (i != (M - 1) || j != (N - 1)) {
                printf("%d ", single_array_matrix[i][j]);
            } else {
                printf("%d", single_array_matrix[i][j]);
            }
        }
    }
    max_min_in_dynamic(N, M, *single_array_matrix);
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
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (i != (M - 1) || j != (N - 1)) {
                printf("%d ", pointer_array[i][j]);
            } else {
                printf("%d", pointer_array[i][j]);
            }
        }
    }
    max_min_in_dynamic(N, M, *pointer_array);
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
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (i != (M - 1) || j != (N - 1)) {
                printf("%d ", pointer_array[i][j]);
            } else {
                printf("%d", pointer_array[i][j]);
            }
        }
    }
    max_min_in_dynamic(N, M, *pointer_array);
    free(pointer_array);
    free(pointer);
}
void staticArray(int N, int M, int data[MAXI][MAXJ]) {
    int flag = 0;
    input_array_static(N, M, data, &flag);
    if (flag == 1) {
        printf("n/a");
        return;
    }
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (i != (M - 1) || j != (N - 1)) {
                printf("%d ", data[i][j]);
            } else {
                printf("%d", data[i][j]);
            }
        }
    }
    max_min_in_static(N, M, data);
}

void input_array_static(int N, int M, int data[MAXI][MAXJ], int *flag) {
    *flag = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &data[i][j]) != 1) {
                *flag = 1;
            }
        }
    }
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

void max_min_in_static(int N, int M, int data[MAXI][MAXJ]) {
    printf("\n");
    int max_in_row[M];
    int min_in_coll[N];
    for (int i = 0; i < M; i++) {
        max_in_row[i] = data[i][0];
        for (int j = 0; j < N; j++) {
            if (data[i][j] > max_in_row[i]) {
                max_in_row[i] = data[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        min_in_coll[i] = data[0][i];
        for (int j = 0; j < M; j++) {
            if (data[j][i] < min_in_coll[i]) {
                min_in_coll[i] = data[j][i];
            }
        }
    }
    for (int i = 0; i < M; i++) {
        printf("%d ", max_in_row[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        if (i != (N - 1)) {
            printf("%d ", min_in_coll[i]);
        } else {
            printf("%d", min_in_coll[i]);
        }
    }
}

void max_min_in_dynamic(int N, int M, int *data) {
    printf("\n");
    int max_in_row[M];
    int min_in_coll[N];
    for (int i = 0; i < M; i++) {
        max_in_row[i] = data[i * N];
        for (int j = 0; j < N; j++) {
            if (data[i * N + j] > max_in_row[i]) {
                max_in_row[i] = data[i * N + j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        min_in_coll[i] = data[i];
        for (int j = 0; j < M; j++) {
            if (data[j * N + i] < min_in_coll[i]) {
                min_in_coll[i] = data[j * N + i];
            }
        }
    }
    for (int i = 0; i < M; i++) {
        printf("%d ", max_in_row[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        if (i != (N - 1)) {
            printf("%d ", min_in_coll[i]);
        } else {
            printf("%d", min_in_coll[i]);
        }
    }
}
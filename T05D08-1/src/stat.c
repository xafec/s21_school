#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) return 1;
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) == 1 && getchar() == '\n') {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1 && getchar() != '\n') {
                printf("n/a");
                return 1;
            }
        }
        if (getchar() != '\n') {
            printf("n/a");
            return 1;
        }
    } else {
        printf("n/a");
        return 1;
    };

    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    return sum / n;
}

double variance(int *a, int n) {
    double sum = 0;
    double means = mean(a, n);

    for (int i = 0; i < n; ++i) sum += (a[i] - means) * (a[i] - means);

    return sum / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
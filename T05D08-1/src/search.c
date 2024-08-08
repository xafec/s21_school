#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int even(int a);
int check(int a, double mean, double variance);

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

int main() {
    int n, data[NMAX];
    if (input(data, &n)) return 1;
    for (int i = 0; i < n; ++i) {
        if (check(data[i], mean(data, n), variance(data, n)) == 0) {
            printf("%d\n", data[i]);
            return 0;
        }
    }
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

int even(int a) {
    if (a % 2 == 0) return 1;
    return 0;
}

int check(int a, double mean, double variance) {
    if (a == 0) {
        return 1;
    }
    if (!even(a)) {
        return 1;
    }
    if (a >= mean && a <= mean + 3 * sqrt(variance)) {
        return 0;
    } else {
        return 1;
    }
}
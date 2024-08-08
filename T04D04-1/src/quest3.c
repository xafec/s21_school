#include <stdio.h>

int fib(int n);

int main() {
    int num;
    if (scanf("%i", &num) == 1 && getchar() == '\n') {
        if (num < 0) {
            printf("-%i", fib(num));
        } else {
            printf("%i", fib(num));
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int fib(int n) {
    if (n == 0) return 0;

    if (n == 1 || n == 2) return 1;

    return fib(n - 1) + fib(n - 2);
}

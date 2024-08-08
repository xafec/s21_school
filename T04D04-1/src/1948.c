#include <math.h>
#include <stdio.h>

int is_prime(int a);
int nod(int a);

int main() {
    int a;
    if ((scanf("%i", &a)) == 1 && (getchar() == '\n')) {
        if (is_prime(a)) {
            printf("%i", a);
        } else {
            printf("%i", nod(a));
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int is_prime(int a) {
    if (a < 0) {
        a *= -1;
    }

    if (a == 0 || a == 1) return 0;

    for (int i = 2; i < a; i++) {
        for (int j = 1; j < a; j++) {
            if ((a - i * j) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int nod(int a) {
    int max = 2;
    for (int i = 2; i < a; i++) {
        for (int j = 1; j < a; j++) {
            if ((a - i * j) == 0 && i > max && is_prime(i)) {
                max = i;
            }
        }
    }
    return max;
}
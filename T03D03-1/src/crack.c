#include <stdio.h>

int sqr(int a);

int main() {
    float x, y;
    int result = scanf("%f %f", &x, &y);

    if (result != 2) {
        printf("n/a");
        return 1;
    }

    int A = sqr(x);
    int B = sqr(y);

    if (A + B < 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }

    return 0;
}

int sqr(int a) { return a * a; }
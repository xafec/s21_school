#include <stdio.h>

int max(int a, int b);

int main() {
    printf("Vvedite a i b:");
    float a, b;
    int result = scanf("%f %f", &a, &b);
    int a1, b1;
    a1 = (int)a;
    b1 = (int)b;

    if (result != 2 || a > a1 || b > b1) {
        printf("n/a");
        return 1;
    }
    int maxx = max(a, b);
    printf("%i", maxx);

    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else if (a < b) {
        return b;
    } else {
        return a;
    }
}
#include <stdio.h>

int sum(int a, int b);
int raznost(int a, int b);
int proizvedenie(int a, int b);
int chastnoe(int a, int b);
void clear_buffer();

int main() {
    float a, b;
    float a1, a2, b1, b2;
    printf("Vvedite a i b:");
    int result = scanf("%f %f", &a, &b);

    if (result != 2) {
        printf("n/a");
        return 1;
    }

    a1 = a;
    a2 = (int)a;
    b1 = b;
    b2 = (int)b;

    if (a1 > a2 || b1 > b2) {
        printf("n/a");
        return 1;
    }

    clear_buffer();
    if (b == 0) {
        printf("%i %i %i n/a", sum(a, b), raznost(a, b), proizvedenie(a, b));
    }
    printf("%i %i %i %i", sum(a, b), raznost(a, b), proizvedenie(a, b), chastnoe(a, b));
    return 0;
}

int sum(int a, int b) {
    int c = a + b;
    return c;
}

int raznost(int a, int b) {
    int c = a - b;
    return c;
}

int proizvedenie(int a, int b) {
    int c = a * b;
    return c;
}

int chastnoe(int a, int b) { return a / b; }
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
#include <math.h>
#include <stdio.h>

int main() {
    float x;
    int result = scanf("%f", &x);
    if (result != 1) {
        printf("n/a");
        return 1;
    }
    float y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, (float)1 / 3) - 1e3) * x + 3) / (x * x / 2) -
              x * pow((10 + x), (2 / x)) - 1.01;
    printf("%.1lf", y);
    return 0;
}
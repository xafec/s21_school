#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculate.h"
#include "shunting.h"
#include "stacks.h"

#define SIZE_EXP 1000
#define GRAPH_HEIGHT 25
#define GRAPH_WIDTH 80

void plotGraph(const char *expression);

int main() {
    char input[SIZE_EXP];

    fgets(input, SIZE_EXP, stdin);
    input[strcspn(input, "\n")] = 0;

    plotGraph(input);

    return 0;
}

void plotGraph(const char *input) {
    double y_max = 1.0;
    double y_min = -1.0;
    double y_step = (y_max - y_min) / GRAPH_HEIGHT;

    char output[SIZE_EXP][SIZE_EXP];
    shunting_yard(input, output);

    for (int j = GRAPH_HEIGHT; j >= 1; j--) {
        for (int i = 1; i <= GRAPH_WIDTH; i++) {
            double x = 4.0 * M_PI / GRAPH_WIDTH * (double)(i - 1);
            double val = needsomexppls(output, x);

            double y_step_min = y_min + y_step * (j - 1);
            double y_step_max = y_min + y_step * j;
            if ((val <= y_step_max) && (val >= y_step_min)) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}
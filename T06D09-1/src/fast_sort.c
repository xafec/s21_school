#include <stdio.h>
#define NMAX 10

int input(int *a, int *b);
void swap(int *a, int *b);
void quick_sort(int *a, int first, int last);
void heap_sort(int *a, int n);
void output(int *a);

int main() {
    int a[NMAX], b[NMAX] = {0};
    if (input(a, b)) {
        return 1;
    }

    quick_sort(a, 0, NMAX - 1);
    heap_sort(b, NMAX);
    output(a);
    printf("\n");
    output(b);
    return 0;
}

int input(int *a, int *b) {
    for (int *p = a; p - a < NMAX; p++) {
        // int c;
        // (c = getchar() != '\n' || c != ' ')
        if (scanf("%d", p) != 1 && getchar() != '\n') {
            printf("n/a");
            return 1;
        }
        b[p - a] = *p;
    }
    if (getchar() != '\n') {
        printf("n/a");
        return 1;
    }

    return 0;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle) left++;
            while (a[right] > middle) right--;
            if (left <= right) {
                swap(a + left, a + right);
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}

void heapify(int *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) largest = left;

    if (right < n && a[right] > a[largest]) largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        printf("%d ", *p);
    }
}
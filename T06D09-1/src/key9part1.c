/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int number);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX] = {0};
    if (input(data, &n)) {
        printf("n/a");
        return 1;
    }
    int sum = sum_numbers(data, n);
    int numbers[NMAX] = {0};
    int count = find_numbers(data, n, sum, numbers);
    output(numbers, count, sum);

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) == 1 && getchar() == '\n' && *n <= NMAX) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1 && getchar() != '\n') {
                return 1;
            }
        }
        if (getchar() != '\n') {
            return 1;
        }
    } else {
        return 1;
    }

    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0 || buffer[i] == 1 || buffer[i] == -1) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (number != 0 && buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[j] = buffer[i];
            j++;
        }
    }
    return j;
}

void output(int *a, int length, int number) {
    printf("%d\n", number);
    for (int *p = a; p - a < length; p++) {
        printf("%d ", *p);
    }
}
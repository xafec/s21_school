#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

// Объявление функций
void inputFromFile(int **field, char *filename);
void fieldOutput(int **field);
int countNeighbors(int **field, int row, int col);
void fieldUpdate(int **field, int **newField);
void fieldClean(int **field);

int main(int argc, char *argv[]) {
    int **field, **newField, **temp;
    int generation = 0;
    float key = 1;
    // Выделение памяти для двух полей
    field = (int **)malloc(HEIGHT * sizeof(int *));
    newField = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        field[i] = (int *)malloc(WIDTH * sizeof(int));
        newField[i] = (int *)malloc(WIDTH * sizeof(int));
    }
    // Инициализация поля
    if (argc > 1) {
        inputFromFile(field, argv[1]);
    } else {
        printf("Файл инициализации не найден");
        exit(EXIT_FAILURE);
    }
    // Инициализация библиотеки <ncurses.h>
    initscr();
    // Делаем формат поля 80х25 в консоли
    resize_term(HEIGHT, WIDTH);
    // Контроль клавиатуры
    cbreak();
    nodelay(stdscr, true);
    //  Основной цикл игры
    while (1) {
        curs_set(0);  // Убрать курсор
        clear();      // Очистить экран
        // Вывод номера поколения и поля
        printw("Generation: %d\n", generation);  // Аналог printf() из <stdio.h>
        fieldOutput(field);
        // Обновление поля
        fieldUpdate(field, newField);
        // Меняем указатели местами
        temp = field;
        field = newField;
        newField = temp;
        generation++;
        // Задержка и обработка ввода клавиш
        char ch = getch();  // Аналог getchar() из <stdio.h>
        // Выход из игры при нажатии клавиши q
        if (ch == 'q') {
            break;
        }
        if (ch == 'z') {
            key += 0.3;
            if (key >= 3.0) {
                key = 3.0;
            }
        } else if (ch == 'x') {
            key *= 0.5;
            if (key <= 0.1) {
                key = 0.1;
            }
        }
        // Функция позволяет отобразить все изменения
        refresh();
        // Функция регулирования скорости выведения на экран
        usleep(100000 * key);
    }
    // Освобождение памяти
    fieldClean(field);
    fieldClean(newField);
    // Завершение работы с библиотекой <ncurses.h>
    endwin();
    return 0;
}

// Загрузка поля из файла
void inputFromFile(int **field, char *filename) {
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (fscanf(file, "%d", &field[i][j]) != 1) {
                printf("Ошибка чтения файла\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
}

// Вывод поля в консоль
void fieldOutput(int **field) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (field[i][j]) {
                printw("0");  // Живая клетка
            } else {
                printw(".");  // Мертвая клетка
            }
        }
        putchar('\n');
    }
}

// Подсчет количества живых соседей для клетки (row, col)
int countNeighbors(int **field, int row, int col) {
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            // Проверка границ и исключение самой клетки
            int r = (i + HEIGHT) % HEIGHT;  // Циклические границы
            int c = (j + WIDTH) % WIDTH;
            if (!(i == row && j == col)) {
                count += field[r][c];
            }
        }
    }
    return count;
}

// Обновление поля на следующее поколение
void fieldUpdate(int **field, int **newField) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(field, i, j);
            if (field[i][j]) {
                newField[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                newField[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}

void fieldClean(int **field) {
    for (int i = 0; i < HEIGHT; i++) {
        free(field[i]);
    }
    free(field);
}

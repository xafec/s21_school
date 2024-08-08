#include <stdio.h>
#include <termios.h>

static struct termios stored_settings;

void set_keypress(void) {
    struct termios new_settings;

    tcgetattr(0, &stored_settings);

    new_settings = stored_settings;

    new_settings.c_lflag &= (~ICANON & ~ECHO);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;

    tcsetattr(0, TCSANOW, &new_settings);
    return;
}

void render(int, int, int, int, int, int);
void control_menu(int, int);
void winner_menu(int, int, int, int);
void enter_menu(int, int);
void clear_screen();

int main() {
    set_keypress();
    // Инициализация переменных
    /// Размеры игрового поля
    int max_x = 80;
    int max_y = 25;

    /// Позиции мяча и ракеток
    int score_1 = 0, score_2 = 0;
    int ball_x = 13;  // Y )
    int ball_y = 40;  // X )

    /// Скорость мяча
    int b_vx = 1;
    int b_vy = 1;

    /// Позиции ракеток
    int P1_y = 13;
    int P2_y = 13;
    int winner = 0;

    enter_menu(max_x, max_y);

    // Цикл игры
    // Пока никто не победил
    while (!winner) {
        // Очистка консоли
        clear_screen();

        // Рендер игрового поля
        render(max_x, max_y, ball_x, ball_y, P1_y, P2_y);

        // Вывод меню управления
        control_menu(score_1, score_2);

        // Ввод управления
        printf("~> ");
        int input = getchar();

        if (input == 'z' || input == 'Z') P1_y++;
        if (input == 'a' || input == 'A') P1_y--;
        if (input == 'k' || input == 'K') P2_y--;
        if (input == 'm' || input == 'M') P2_y++;

        if (P2_y == 1) {
            P2_y++;
        } else if (P2_y == 24) {
            P2_y--;
        } else if (P1_y == 1) {
            P1_y++;
        } else if (P1_y == 24) {
            P1_y--;
        }

        // Движение мяча
        ball_x += b_vx;
        ball_y += b_vy;
        if (ball_x == max_y - 1 || ball_x == 1) {  // граница на 25, удар на 24
            // Если мяч касается верхней или нижней границы, то смещаем мяч
            // в противоположную сторону по вертикали
            b_vx = -b_vx;
        }
        if (ball_y == max_x - 1 || ball_y == 1) {  // граница на 80, удар на 79
            // Если мяч касается правой или левой границы, то смещаем
            // мяч в противоположную сторону по горизонтали
            b_vy = -b_vy;
        }
        if (ball_y == 5 && (ball_x == P1_y || ball_x == P1_y + 1 || ball_x == P1_y - 1) && (b_vy == 1)) {
            // Если шар ударяется о границу а потом попадает на ракетку, то пусть
            // продолжает движение, а не меняет направление
        } else if (ball_y == 5 && (ball_x == P1_y || ball_x == P1_y + 1 || ball_x == P1_y - 1)) {
            // Если мяч по X равен 5 и там находиться ракетка, то мы
            // смещаем мяч в противоположную сторону по горизонтали
            b_vy = -b_vy;
        }

        if (ball_y == 75 && (ball_x == P2_y || ball_x == P2_y + 1 || ball_x == P2_y - 1) && (b_vy == -1)) {
            // Если шар ударяется о границу а потом попадает на ракетку, то пусть
            // продолжает движение, а не меняет направление
        } else if (ball_y == 75 && (ball_x == P2_y || ball_x == P2_y + 1 || ball_x == P2_y - 1)) {
            // Если мяч по X равен 75 и там находиться ракетка, то мы
            // смещаем мяч в противоположную сторону по горизонтали
            b_vy = -b_vy;
        }

        // Подсчет очков
        if (ball_y == 1) {
            score_2++;
        } else if (ball_y == 79) {  // граница на 80, удар на 79
            score_1++;
        }

        // Проверка победителя
        winner = (score_1 == 21 || score_2 == 21) ? 1 : 0;

        // Выход из игры
        if (input == 'q' || input == 'Q') {
            break;
        }
    }

    // Вывод победителя
    winner_menu(max_x, max_y, score_1, score_2);

    return 0;
}

// Рендер игрового поля
void render(int max_x, int max_y, int ball_x, int ball_y, int P1_y, int P2_y) {
    for (int i = 0; i <= max_y; i++) {
        for (int j = 0; j <= max_x; j++) {
            if (i == 0 || i == max_y) {
                putchar('-');
            } else if (i == ball_x && j == ball_y) {
                putchar('O');
            } else if (j == 0 || j == 40 || j == 80) {
                putchar('|');
            } else if (j == 76) {
                if (i == P2_y - 1 || i == P2_y || i == P2_y + 1) {
                    putchar('I');
                } else {
                    putchar(' ');
                }
            } else if (j == 4) {
                if (i == P1_y - 1 || i == P1_y || i == P1_y + 1) {
                    putchar('I');
                } else {
                    putchar(' ');
                }
            } else {
                putchar(' ');
            }
        }
        printf("\n");
    }
}

// Меню управления
void control_menu(int score_1, int score_2) {
    printf("\n\t\tP1 score: %d\t\t\t\tP2 score: %d\n\n", score_1, score_2);
    printf(
        "Player 1: 'a' - up, 'z' - down\t\t\t   Player 2: 'k' - up, 'm' - "
        "down\n\n");
    printf("\t\t\t\t    Exit: 'q'\n");
}

void winner_menu(int max_x, int max_y, int score_1, int score_2) {
    clear_screen();
    for (int i = 0; i <= max_y; i++) {
        for (int j = 0; j <= max_x; j++) {
            if (i == 0 || i == max_y) {
                printf("-");
            } else if (j == 0 || j == 80) {
                printf("|");
            } else if (i == 13) {
                if ((score_1 == 21 || score_1 > score_2) && j == 33) {
                    printf("Player 1 wins!");
                    for (int k = 0; k <= 33; k++) {
                        if (k == 33) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                    }
                    break;
                } else if ((score_2 == 21 || score_2 > score_1) && j == 33) {
                    printf("Player 2 wins!");
                    for (int k = 0; k <= 33; k++) {
                        if (k == 33) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                    }
                    break;
                } else if (j == 37 && score_1 == score_2) {
                    printf("Draw!");
                    for (int k = 0; k <= 38; k++) {
                        if (k == 38) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                    }
                    break;
                } else {
                    printf(" ");
                }
            } else {
                putchar(' ');
            }
        }
        printf("\n");
    }
}

void enter_menu(int max_x, int max_y) {
    clear_screen();
    for (int i = 0; i <= max_y; i++) {
        for (int j = 0; j <= max_x; j++) {
            if (i == 0 || i == max_y) {
                printf("-");
            } else if (j == 0 || j == 80) {
                printf("|");
            } else if (i == 13 && j == 33) {
                printf("Enter to start");
                for (int k = 0; k <= 33; k++) {
                    if (k == 33) {
                        printf("|");
                    } else {
                        printf(" ");
                    }
                }
                break;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("~> ");
    getchar();
}

void clear_screen() { printf("\033[H\033[J"); }

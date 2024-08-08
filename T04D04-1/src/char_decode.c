#include <stdio.h>

int code();
int decode();
int hex(char c);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("n/a");
        return 1;
    }

    int flag = argv[1][0] - '0';
    if (flag != 0 && flag != 1) {
        printf("n/a");
        return 1;
    }

    if (flag == 0) {
        code();
    } else {
        decode();
    }

    return 0;
}

int code() {
    int ch = getchar();
    int xhh = getchar();
    if (ch == ' ' || xhh != ' ') {
        printf("n/a");
        return 1;
    }
    printf("%02X ", ch);
    while (ch != ' ' && (xhh == ' ')) {
        ch = getchar();
        xhh = getchar();
        if (ch == xhh || (ch == ' ' && xhh == '\n')) {
            break;
        }
        printf("%02X ", ch);
    }
    return 0;
}

int decode() {
    int ch1 = getchar();
    int ch2 = getchar();
    int xhh = getchar();
    if (ch1 == ' ' || ch2 == ' ' || xhh != ' ') {
        printf("n/a");
        return 1;
    }
    char letter = (char)(hex(ch1) * 16 + hex(ch2));
    printf("%c ", letter);
    while (ch1 != ' ' && ch2 != ' ' && (xhh == ' ')) {
        ch1 = getchar();
        ch2 = getchar();
        xhh = getchar();
        if (ch1 == xhh || ch2 == xhh || (ch1 == ' ' && xhh == '\n') || (ch2 == ' ' && xhh == '\n')) {
            break;
        }
        letter = (char)(hex(ch1) * 16 + hex(ch2));
        printf("%c ", letter);
    }
    return 0;
}

int hex(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}
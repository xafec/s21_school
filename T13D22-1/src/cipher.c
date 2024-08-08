#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log_levels.h"
#include "logger.h"

#define MAX 256

int input(int *n, int *flag);
int print_file(char *filepath);
void add_string_to_file(const char *filepath);
void caesar_cipher(char *filepath, char *filename, int shift);
void clearFile(char *filepath, char *filename);

int main() {
    log_init("cipher.log");
    int n = 0, flag = 0;
    char filepath[MAX];
    char last_file[MAX];
    memset(last_file, 0, MAX);
    last_file[0] = '\0';
    struct dirent *dir;

    printf("Menu:\n1. Read file\n2. Add string to file\n3. Caesar cipher and clear .h files\n-1. Exit\n");

    while (n != -1 && flag == 0) {
        if (input(&n, &flag)) {
            printf("n/a\n");
        }
        if (flag == 0) {
            if (n == 1) {
                fgets(filepath, MAX, stdin);
                filepath[strlen(filepath) - 1] = '\0';
                if (print_file(filepath) == 0) {
                    logcat(info, "File printed.", filepath);
                    printf("\n");
                    strcpy(last_file, filepath);
                } else {
                    logcat(error, "Failed to open file", filepath);
                    printf("\n");
                }
            } else if (n == 2 && last_file[0] != '\0') {
                add_string_to_file(last_file);
                logcat(info, "String added to file.", last_file);
                print_file(last_file);
                printf("\n");
            } else if (n == 3) {
                int shift;
                printf("Enter shift for caesar cipher: ");
                if (scanf("%d", &shift) != 1) {
                    printf("n/a\n");
                    continue;
                }
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;

                printf("Enter directory path from root (example: src/ai_modules): ");
                char path[MAX], dirname[MAX + 3];
                fgets(path, MAX, stdin);
                path[strlen(path) - 1] = '\0';

                strcpy(dirname, "../");
                strcpy(dirname + 3, path);

                DIR *d;
                d = opendir(dirname);
                if (d) {
                    while ((dir = readdir(d)) != NULL) {
                        int len = strlen(dir->d_name);
                        if (len > 2 && strcmp(dir->d_name + len - 2, ".c") == 0) {
                            caesar_cipher(dirname, dir->d_name, shift);
                            logcat(info, "Caesar cipher applied to .c file", dir->d_name);
                        } else if (len > 2 && strcmp(dir->d_name + len - 2, ".h") == 0) {
                            clearFile(dirname, dir->d_name);
                            logcat(info, ".h file cleared", dir->d_name);
                        }
                    }
                    closedir(d);
                    printf("Done!\n");
                } else {
                    printf("n/a\n");
                }
            } else if (n == -1) {
                flag = 1;
            } else {
                printf("n/a\n");
            }
        }
    };

    log_close();

    return 0;
}

int input(int *n, int *flag) {
    int c;
    if (scanf("%d", n) != 1) {
        *flag = 1;
    }

    if (*n != -1 && *n != 1 && *n != 2 && *n != 3) {
        *flag = 1;
    }

    c = getchar();
    if (c != '\n' && c != EOF && c != ' ') {
        *flag = 1;
    }

    return *flag;
}

int print_file(char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("n/a\n");
        logcat(error, "Failed to open file", filepath);
        return 1;
    }

    char ch;
    int is_empty = 1;
    while ((ch = fgetc(file)) != EOF) {
        is_empty = 0;
        putchar(ch);
    }

    if (is_empty) {
        printf("n/a\n");
    }

    fclose(file);
    return 0;
}

void add_string_to_file(const char *filepath) {
    int flag = 0;
    FILE *file = fopen(filepath, "a");
    if (!file) {
        printf("n/a\n");
        logcat(error, "Failed to open file", filepath);
        flag = 1;
    }
    if (!flag) {
        char str[MAX];
        fgets(str, MAX, stdin);
        str[strlen(str) - 1] = '\0';
        fputs("\n", file);
        fputs(str, file);
        fclose(file);
    }
}

void caesar_cipher(char *filepath, char *filename, int shift) {
    char fullpath[MAX];
    snprintf(fullpath, MAX, "%s/%s", filepath, filename);

    FILE *file = fopen(fullpath, "r+");
    if (!file) {
        printf("Could not open file %s\n", filename);
        logcat(error, "Failed to open file", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(fileSize + 1);
    if (!content) {
        printf("Memory allocation error\n");
        logcat(error, "Memory allocation error", filename);
        fclose(file);
        return;
    }

    fread(content, 1, fileSize, file);
    content[fileSize] = '\0';

    for (int i = 0; i < fileSize; i++) {
        if (isalpha(content[i])) {
            char base = islower(content[i]) ? 'a' : 'A';
            content[i] = (content[i] - base + shift) % 26 + base;
        }
    }

    fseek(file, 0, SEEK_SET);
    fwrite(content, 1, fileSize, file);
    fclose(file);
    free(content);
}

void clearFile(char *filepath, char *filename) {
    char fullpath[MAX];
    snprintf(fullpath, MAX, "%s/%s", filepath, filename);

    FILE *file = fopen(fullpath, "w");
    if (!file) {
        printf("Could not open file %s\n", filename);
        logcat(error, "Failed to open file", filename);
        return;
    }
    fclose(file);
}
#include "state_sort.h"

#include <stdio.h>

int main() {
    char dir[256], path[259] = {""};
    fgets(dir, 256, stdin);
    dir[strlen(dir) - 1] = '\0';
    strcpy(path, "../");
    strcat(path, dir);

    int option, flag = 0;
    DoorState new_state;
    if (scanf("%d", &option) != 1) {
        printf("n/a");
        flag = 1;
    };
    if (!flag) {
        if (option == 0) {
            if (isCorrectPath(path)) {
                outputFile(path);
            } else {
                printf("n/a");
                flag = 1;
            }
        } else if (option == 1) {
            if (isCorrectPath(path)) {
                sortFile(path);
                outputFile(path);
            } else {
                printf("n/a");
                flag = 1;
            }
        } else if (option == 2) {
            scanf("%d %d %d %d %d %d %d %d", &new_state.year, &new_state.month, &new_state.day,
                  &new_state.hour, &new_state.minute, &new_state.second, &new_state.status, &new_state.code);
            if (isCorrectPath(path)) {
                appendStringToFile(path, &new_state);
                sortFile(path);
                outputFile(path);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    }

    return 0;
}

int isEmptyFile(FILE *file) {
    fseek(file, 0, SEEK_END);
    // ftell returns the current file position
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size == 0;
}

void print_record(const DoorState *record) {
    printf("%d %d %d %d %d %d %d %d\n", record->year, record->month, record->day, record->hour,
           record->minute, record->second, record->status, record->code);
}

int isCorrectPath(char *path) {
    int flag = 0;
    FILE *ptr = fopen(path, "r");
    if (ptr) {
        flag = 1;
        fclose(ptr);
    }
    return flag;
}

void outputFile(char *path) {
    FILE *file = fopen(path, "rb");
    if (!file || isEmptyFile(file)) {
        if (file) fclose(file);
        return;
    }
    fseek(file, 0, SEEK_SET);
    DoorState record;
    while (fread(&record, sizeof(DoorState), 1, file) == 1) {
        print_record(&record);
    }

    fclose(file);
}

int lengthFile(FILE *file) {
    fseek(file, 0, SEEK_END);
    // ftell returns the current file position
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

void sortFile(char *path) {
    FILE *file = fopen(path, "r+b");
    int n = lengthFile(file) / sizeof(DoorState);
    if (!file || isEmptyFile(file)) {
        if (file) fclose(file);
        return;
    }
    DoorState record1;
    DoorState record2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            fseek(file, j * sizeof(DoorState), SEEK_SET);
            fread(&record1, sizeof(DoorState), 1, file);
            fread(&record2, sizeof(DoorState), 1, file);
            //  if a(first) > b(second)
            if (stateCompare(&record1, &record2) > 0) {
                fseek(file, j * sizeof(DoorState), SEEK_SET);
                fwrite(&record2, sizeof(DoorState), 1, file);
                fwrite(&record1, sizeof(DoorState), 1, file);
            }
        }
    }
    fclose(file);
}

int stateCompare(const DoorState *a, const DoorState *b) {
    if (a->year != b->year) return a->year - b->year;
    if (a->month != b->month) return a->month - b->month;
    if (a->day != b->day) return a->day - b->day;
    if (a->hour != b->hour) return a->hour - b->hour;
    if (a->minute != b->minute) return a->minute - b->minute;
    if (a->second != b->second) return a->second - b->second;
    if (a->status != b->status) return a->status - b->status;
    return a->code - b->code;
}
// ../datasets/door_state_1 2 2020 12 21 23 54 26 1 768
void appendStringToFile(char *path, DoorState *new_state) {
    FILE *file = fopen(path, "ab");
    if (!file) {
        printf("n/a");
        return;
    }
    fwrite(new_state, sizeof(DoorState), 1, file);

    fclose(file);
}
#include "clear_state.h"

int main() {
    DoorState stateFrom, stateTo;
    char path[256];
    if (scanf("%255s", path) != 1 ||
        scanf("%d.%d.%d", &stateFrom.day, &stateFrom.month, &stateFrom.year) != 3 ||
        scanf("%d.%d.%d", &stateTo.day, &stateTo.month, &stateTo.year) != 3) {
        printf("n/a\n");
        return 1;
    }

    if (isCorrectPath(path)) {
        FILE *file = fopen(path, "rb");
        if (file == NULL || isEmptyFile(file)) {
            printf("n/a\n");
        } else {
            fclose(file);
            removeLinesBetweenDates(path, stateFrom, stateTo);
            outputFile(path);
        }
        if (file) fclose(file);
    } else {
        printf("n/a\n");
    }
    return 0;
}

int isEmptyFile(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size == 0;
}

int isCorrectPath(char *path) {
    FILE *ptr = fopen(path, "rb");
    if (ptr) {
        fclose(ptr);
        return 1;
    }
    return 0;
}

int stateCompare(const DoorState *a, const DoorState *b) {
    if (a->year != b->year) return a->year - b->year;
    if (a->month != b->month) return a->month - b->month;
    return a->day - b->day;
}

void removeLinesBetweenDates(const char *path, DoorState stateFrom, DoorState stateTo) {
    FILE *input = fopen(path, "rb");
    FILE *temp = tmpfile();

    if (!input || !temp) {
        if (input) fclose(input);
        if (temp) fclose(temp);
        printf("n/a\n");
        return;
    }

    DoorState record;
    while (fread(&record, sizeof(DoorState), 1, input) == 1) {
        if (stateCompare(&record, &stateFrom) < 0 || stateCompare(&record, &stateTo) > 0) {
            fwrite(&record, sizeof(DoorState), 1, temp);
        }
    }

    fclose(input);

    input = fopen(path, "wb");
    if (!input) {
        fclose(temp);
        printf("n/a\n");
        return;
    }

    rewind(temp);
    while (fread(&record, sizeof(DoorState), 1, temp) == 1) {
        fwrite(&record, sizeof(DoorState), 1, input);
    }

    fclose(input);
    fclose(temp);
}

void outputFile(char *path) {
    FILE *file = fopen(path, "rb");
    if (!file || isEmptyFile(file)) {
        if (file) fclose(file);
        return;
    }

    DoorState record;
    while (fread(&record, sizeof(DoorState), 1, file) == 1) {
        print_record(&record);
    }

    fclose(file);
}

void print_record(const DoorState *record) {
    printf("%d %d %d %d %d %d %d %d\n", record->year, record->month, record->day, record->hour,
           record->minute, record->second, record->status, record->code);
}
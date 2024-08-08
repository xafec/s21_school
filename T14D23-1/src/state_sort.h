#ifndef STATE_SORT_H
#define STATE_SORT_H
#include <stdio.h>
#include <string.h>

typedef struct {
    int year, month, day, hour, minute, second, status, code;
} DoorState;

int isEmptyFile(FILE *file);
void print_record(const DoorState *record);
int isCorrectPath(char *path);
void outputFile(char *path);
void sortFile(char *path);
int lengthFile(FILE *file);
int stateCompare(const DoorState *a, const DoorState *b);
void appendStringToFile(char *path, DoorState *new_state);
#endif
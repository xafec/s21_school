#ifndef STATE_SEARCH_H
#define STATE_SEARCH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year, month, day, hour, minute, second, status, code;
} DoorState;

int isEmptyFile(FILE *file);
int isCorrectPath(char *path);
int lengthFile(FILE *file);
int stateCompare(const DoorState *a, const DoorState *b);

#endif
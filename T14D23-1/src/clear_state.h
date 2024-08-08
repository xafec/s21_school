#ifndef CLEAR_STATE_H
#define CLEAR_STATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    int year, month, day, hour, minute, second, status, code;
} DoorState;

int isEmptyFile(FILE *file);
int isCorrectPath(char *path);
int lengthFile(FILE *file);
int stateCompare(const DoorState *a, const DoorState *b);
void removeLinesBetweenDates(const char *path, DoorState stateFrom, DoorState stateTo);
void outputFile(char *path);
void print_record(const DoorState *record);

#endif
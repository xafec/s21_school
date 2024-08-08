#ifndef LOGGER_H
#define LOGGER_H

#include "log_levels.h"

typedef enum log_level LogLevel;

int log_init(const char *filename);

void logcat(LogLevel level, const char *message, const char *filename);

void log_close();

#endif
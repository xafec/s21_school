#include "logger.h"

#include <stdio.h>
#include <time.h>

static FILE *logfile = NULL;

int log_init(const char *filename) {
    int flag = 0;
    logfile = fopen(filename, "a");
    if (logfile == NULL) {
        printf("Failed to open log file: %s\n", filename);
        flag = 1;
    }

    return flag;
}

void logcat(LogLevel level, const char *message, const char *filename) {
    if (logfile == NULL) {
        return;
    }

    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    char timestr[20];
    strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", timeinfo);

    char *levelstr;
    switch (level) {
        case debug:
            levelstr = "DEBUG";
            break;
        case info:
            levelstr = "INFO";
            break;
        case warning:
            levelstr = "WARNING";
            break;
        case error:
            levelstr = "ERROR";
            break;
        case trace:
            levelstr = "TRACE";
            break;
        default:
            levelstr = "UNKNOWN";
            break;
    }

    fprintf(logfile, "[%s] %s: %s (%s)\n", levelstr, timestr, message, filename);
}

void log_close() {
    if (logfile != NULL) {
        fclose(logfile);
        logfile = NULL;
    }
}
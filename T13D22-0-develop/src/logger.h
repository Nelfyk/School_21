#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_
#include <time.h>

#include "cipher.h"
enum log_level {
    debug,
    trace,
    info,
    warning,
    error
};
FILE* log_init(char* filename);
void logcat(FILE* log_file, char* message, enum log_level level);
void frame(FILE* log_file);
int log_close(FILE* log_file);
#endif  // SRC_LOGGER_H_

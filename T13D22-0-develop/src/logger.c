#include "logger.h"

FILE* log_init(char* filename) {
    return fopen(filename, "a");
}
void logcat(FILE* log_file, char* message, enum log_level level) {
    char tempEnum[5][10] = {"DEBUG", "TRACE", "INFO", "WARNING", "ERROR"};
    time_t t = time(NULL);
    fprintf(log_file, "%s - %s - %s\n", tempEnum[level], strtok(ctime(&t), "\n"), message);
}
void frame(FILE* log_file) {
    fputs("------------------------------------------------------\n", log_file);
}
int log_close(FILE* log_file) {
    return fclose(log_file);
}

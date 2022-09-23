#include "s21_string.h"

size_t s21_strlen(const char *a) {
    size_t len = 0;
    for (; *(a + len); len++) {
    }
    return len;
}
int s21_strcmp(const char *a, const char *b) {
    for (; *a && *a == *b; a++, b++) {
    }
    return *a - *b;
}
void s21_strcpy(const char *a, char *b) {
    for (; *a || *b; a++, b++) {
        *b = *a;
    }
}
void s21_strcat(const char *a, char *b) {
    for (; *b; b++) {
    }
    for (; *a; a++, b++) {
        *b = *a;
    }
}
int s21_strchr(const char *a, char b) {
    int count = 1;
    for (; *a && *a != b; a++, count++) {
    }
    return count;
}
int s21_strstr(const char *a, const char *b) {
    int count = 1;
    int temp = 0;
    int len = (int)s21_strlen(b);
    for (; *a && temp != len; a++, count++)
        if (*a == *b) {
            temp++;
            b++;
        }
    (temp != len) ? (count = -1) : (count += 0);
    return count - temp;
}
// void s21_strtok(const char *a, char *b) {
//     for(;*b && *b!=*a;b++){
//     }
//     return
// }

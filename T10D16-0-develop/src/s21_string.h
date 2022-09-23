#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdio.h>
size_t s21_strlen(const char *a);
int s21_strcmp(const char *a, const char *b);
void s21_strcpy(const char *a, char *b);
void s21_strcat(const char *a, char *b);
int s21_strchr(const char *a, char b);
int s21_strstr(const char *a, const char *b);
// void s21_strtok(const char *a, char *b);
#endif  // SRC_S21_STRING_H_

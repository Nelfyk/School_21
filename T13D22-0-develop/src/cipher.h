#ifndef SRC_CIPHER_H_
#define SRC_CIPHER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_1 1000
#define ENG 26
#define RUS 32
void menu();
int choice1(int *error, char *name, FILE * pLog);
void choice2(int *error, char *name, int exist, FILE * pLog);
void choice3(int *error, FILE * pLog);
char *inputDinamic();
int check(char *a, FILE * pLog);

void encrypt(int n, char *a, FILE * pLog);
void swap(char *a, FILE * pLog);

#endif  // SRC_CIPHER_H_

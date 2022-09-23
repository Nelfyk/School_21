#include "cipher.h"
#ifdef LOGGING
#include "logger.h"
#endif

void menu() {
    FILE *pLog = NULL;
#ifdef LOGGING
    pLog = log_init("logger.txt");  // файл логов
    logcat(pLog, "Start program", info);
#endif
    char name[50] = {0};  // строка
    int error = 0;
    int temp = 0;
    int exist = -1;
    scanf("%i", &temp);
    while (temp != -1) {
        if (temp == 1) {
            exist = choice1(&error, name, pLog);
        } else {
            if (temp == 2) {
                choice2(&error, name, exist, pLog);
            } else {
                if (temp == 3) {
                    choice3(&error, pLog);
                } else {
#ifdef LOGGING
                    logcat(pLog, "Incorrect input", error);
#endif
                    error++;
                }
            }
        }
        (error) ? (printf("n/a\n")) : (error += 0);
        error = 0;
        fflush(stdin);
        (!scanf("%i", &temp)) ? (error++) : (error += 0);
    }
#ifdef LOGGING
    logcat(pLog, "Finish program", info);
    frame(pLog);
    log_close(pLog);
#endif
}
int choice1(int *error, char *name, FILE *pLog) {
    pLog = pLog;
#ifdef LOGGING
    logcat(pLog, "Reading_file", debug);
#endif
    int exist = 0;
    char buffer[SIZE_1];
    getchar();
    scanf("%50s", name);
    FILE *pF = fopen(name, "r");
    if (pF && fgets(buffer, SIZE_1, pF) != NULL) {
        printf("%s", buffer);
        while (fgets(buffer, SIZE_1, pF)) {
            printf("%s", buffer);
        }
        fclose(pF);
#ifdef LOGGING
        logcat(pLog, "Reading_file succes", debug);
#endif
        printf("\n");
    } else {
#ifdef LOGGING
        logcat(pLog, "Reading_file FAILED", warning);
#endif
        exist = 1;
        *error += 1;
    }

    return exist;
}
void choice2(int *error, char *name, int exist, FILE *pLog) {
    pLog = pLog;
#ifdef LOGGING
    logcat(pLog, "Writing_to_file", debug);
#endif
    if (!exist) {
        FILE *pF = fopen(name, "a");
        getchar();  // ??
        char *a = inputDinamic();
        fputs(a, pF);
        fclose(pF);
        free(a);
#ifdef LOGGING
        logcat(pLog, "Writing_to_file succes", debug);
#endif
    } else {
#ifdef LOGGING
        logcat(pLog, "Writing_to_file FAILED", warning);
#endif
        *error += 1;
    }
}
void choice3(int *error, FILE *pLog) {  // -=3=-
    pLog = pLog;
#ifdef LOGGING
    logcat(pLog, "Caesar_encrypt", debug);
#endif
    char buffer[SIZE_1];
    int num = 0;
    char c;
    if (scanf("%i%c", &num, &c) == 2 && c == '\n') {
        system("ls ai_modules >> temp.txt");
        FILE *pF = fopen("temp.txt", "r");
        while (fgets(buffer, SIZE_1, pF)) {
            if (check(buffer, pLog) == 0) {
                char temp[SIZE_1] = "ai_modules/";
                buffer[strlen(buffer) - 1] = '\0';
                strcat(temp, buffer);
                FILE *pClear = fopen(temp, "w");
                fclose(pClear);
            }
            if (check(buffer, pLog) == 1) {
                char temp[SIZE_1] = "ai_modules/";
                buffer[strlen(buffer) - 1] = '\0';
                strcat(temp, buffer);
                encrypt(num, temp, pLog);
                swap(temp, pLog);
            }
        }

        fclose(pF);
        system("rm temp.txt");
#ifdef LOGGING
        logcat(pLog, "Caesar_encrypt succes", debug);
#endif
    } else {
#ifdef LOGGING
        logcat(pLog, "Caesar_encrypt FAILED", warning);
#endif
        *error += 1;
    }
}
char *inputDinamic() {
    char *a, buffer;
    int count = 0;
    while (scanf("%c", &buffer) && buffer != '\n') {
        a = (char *)realloc(a, sizeof(char) * (count + 1));
        a[count] = buffer;
        count++;
    }
    return a;
}
int check(char *a, FILE *pLog) {
    pLog = pLog;
#ifdef LOGGING
    logcat(pLog, "checking_the_file_extension", trace);
#endif
    int checker = -1;
    for (int q = 0; *a && !q; a++) {
        if (*(a + q) == '.' && *(a + q + 1) == 'h') {
            checker = 0;
            q = 1;
        } else {
            if (*(a + q) == '.' && *(a + q + 1) == 'c') {
                checker = 1;
                q = 1;
            }
        }
    }
    return checker;
}
void encrypt(int n, char *a, FILE *pLog) {
    pLog = pLog;
#ifdef LOGGING
    logcat(pLog, "Encrypting_process", trace);
#endif
    FILE *pF1 = fopen(a, "r");
    FILE *pF2 = fopen("output.txt", "w");
    int flag;
    char c;
    c = getc(pF1);
    while (!feof(pF1)) {
        flag = 0;  // обработан ли текущий символ
        if (c >= 'A' && c <= 'Z') {
            c = c + (n % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            fprintf(pF2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z') {
            c = c + (n % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            fprintf(pF2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(pF2, "%c", c);
        c = getc(pF1);
    }
    fclose(pF1);
    fclose(pF2);
}
void swap(char *a, FILE *pLog) {
    pLog = pLog;
#ifdef LOGGING
    logcat(pLog, "Swap_process", trace);
#endif
    char buffer[SIZE_1] = {0};
    FILE *pF1 = fopen("output.txt", "r");
    FILE *pF2 = fopen(a, "w");
    // logcat(logger, "star while", info);
    while (fgets(buffer, SIZE_1, pF1)) {
        fputs(buffer, pF2);
    }
    fclose(pF1);
    fclose(pF2);
    system("rm -f output.txt");
}

// TEST
//    printf("\n__1 if true__\n");

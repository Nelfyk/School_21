#include "s21_string.h"

// MAIN
void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
// help
void lenTest(const char *a, size_t num);
void cmpTest(const char *a, const char *b, int num);
void cpyTest(const char *a, char *b);
void catTest(const char *a, char *b);
int chrTest(const char *a, char b);
int strTest(const char *a, char *b);
// out
void output(const char *a);

int main() {
    name return 0;
}

void s21_strlen_test() {
    lenTest("21school", 8);
    lenTest("", 0);
    lenTest("ñçøâàá", 6);
}
void s21_strcmp_test() {
    cmpTest("21school", "21school", 0);  // 0 - identical
    cmpTest("21SCHOOL", "21school", 1);  // 1 - different
    cmpTest("21school!!!", "21school", 1);
}
void s21_strcpy_test() {
    char b[1000] = {""};
    cpyTest("21school", b);
    cpyTest("69", b);
    cpyTest("ñçøâàá", b);
}
void s21_strcat_test() {
    char b[1000] = {"2"};
    catTest("1", b);
    (s21_strcmp("21", b) == 0) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
    catTest("school", b);
    (s21_strcmp("21school", b) == 0) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
    catTest("?!", b);
    (s21_strcmp("21school?!", b) == 0) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
}
void s21_strchr_test() {
    (chrTest("21school", '1') == 2) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
    (chrTest("21school", 'f') == -1) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
    (chrTest("21school", ' ') == -1) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
}
void s21_strstr_test() {
    (strTest("21school", "1s") == 2) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
    (strTest("21school", "f fsdf") == -1) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
    (strTest("21school", " ") == -1) ? (printf("\nSUCCESS\n")) : (printf("\nFAIL\n"));
}
// LENGTH
void lenTest(const char *a, size_t num) {
    printf("\nIN:\n >");
    output(a);
    printf("\nOUT:\n >%li\n", s21_strlen(a));
    (s21_strlen(a) == num) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
}
// CMP
void cmpTest(const char *a, const char *b, int num) {
    printf("\nIN:\n >");
    output(a);
    printf("\n >");
    output(b);
    printf("\nOUT: %i\n", s21_strcmp(a, b));
    if (num == 0) {
        (s21_strcmp(a, b) == 0) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
    } else {
        (s21_strcmp(a, b) != 0) ? (printf("SUCCESS\n")) : (printf("FAIL\n"));
    }
}
// CPY
void cpyTest(const char *a, char *b) {
    printf("\n/--cpy--/");
    printf("\nIN:\n >");
    output(a);
    printf("\n >");
    output(b);
    s21_strcpy(a, b);
    printf("\n/--cmp--/");
    cmpTest(a, b, 0);
}
// CAT
void catTest(const char *a, char *b) {
    printf("\n/--cat--/");
    printf("\nIN:\n >");
    output(a);
    printf("\n >");
    output(b);
    s21_strcat(a, b);
    printf("\nOUT:\n ");
    output(b);
}
// CHR
int chrTest(const char *a, char b) {
    printf("\nIN:\n >");
    output(a);
    printf("\n >");
    printf("%c", b);
    int temp = s21_strchr(a, b);
    (s21_strchr(a, b) > (int)s21_strlen(a)) ? (temp = -1) : (printf("\nOUT:\n %i", temp));
    (temp == -1) ? (printf("\nOUT:\n NULL")) : (temp += 0);
    return temp;
}
// STR
int strTest(const char *a, char *b) {
    printf("\nIN:\n >");
    output(a);
    printf("\n >");
    output(b);
    int temp = s21_strstr(a, b);
    (temp == -1) ? (printf("\nOUT:\n NULL")) : (printf("\nOUT:\n %i", temp));
    return temp;
}
// OUT
void output(const char *a) {
    for (; *a; a++) {
        printf("%c", *a);
    }
}

// printf("\n_____%i____\n",temp);
// все наоборот >:(

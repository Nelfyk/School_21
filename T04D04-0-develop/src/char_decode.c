#include <math.h>
#include <stdio.h>

void code();
void decode();

int main(int n, char* arg[]) {
    int a;
    if (n != 2) {
        printf("n/a");
    } else {
        sscanf(arg[1], "%d", &a);
        switch (a) {
            case 0: {
                code();
                break;
            }
            case 1: {
                decode();
                break;
            }
            default: {
                printf("n/a");
            }
        }
    }
    return 0;
}

void code() {
    unsigned char c1, c2;
    while (scanf("%c%c", &c1, &c2)) {
        if (c2 != '\n' && c2 != ' ') {
            printf("n/a");
            break;
        }
        printf("%x ", c1);
        if (c2 == '\n')
            break;
    }
}

void decode() {
    char c1, c2;
    while (scanf("%2hhx%c", &c1, &c2)) {
        if (c2 != ' ' && c2 != '\n') {
            printf("n/a");
            break;
        }
        printf("%c ", c1);
        if (c2 == '\n')
            break;
    }
}

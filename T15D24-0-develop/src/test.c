#include "test.h"

#include "shared.h"

void outputModulesAll() {
    int num = 0;
    FILE *pDb = fopen("../materials/master_modules.db", "rb");
    if (pDb) {
        system("clear");
        while (fread(&num, sizeof(int), 1, pDb) != 0) {
            printf("%i ", num);
            char buffer[33] = {0};
            fread(buffer, 1, 32, pDb);
            printf("%s ", buffer);
            for (int i = 0; i < 3; i++) {
                fread(&num, sizeof(int), 1, pDb);
                printf("%i ", num);
            }
            printf("\n================================\n");
        }
        fclose(pDb);
    } else {
        printf("НЕТУ ТАКОВА ФАЙЛИКА\n");
    }
}
void outputLevelsAll() {
    int num = 0;
    FILE *pDb = fopen("../materials/master_levels.db", "rb");
    if (pDb) {
        system("clear");
        while (fread(&num, sizeof(int), 1, pDb)) {
            printf("%i ", num);
            for (int i = 0; i < 2; i++) {
                fread(&num, sizeof(int), 1, pDb);
                printf("%i ", num);
            }
            printf("\n================================\n");
        }
        fclose(pDb);
    } else {
        printf("НЕТУ ТАКОВА ФАЙЛИКА\n");
    }
}
void outputStatusEventsAll() {
    int num = 0;
    FILE *pDb = fopen("../materials/master_status_events.db", "rb");
    if (pDb) {
        system("clear");
        char buffer[30] = {0};
        while (fread(&num, sizeof(int), 1, pDb)) {
            printf("%i ", num);
            fread(&num, sizeof(int), 1, pDb);
            printf("%i ", num);
            fread(&num, sizeof(int), 1, pDb);
            printf("%i ", num);
            fread(buffer, 1, 11, pDb);
            printf("%s ", buffer);
            fread(buffer, 1, 9, pDb);
            printf("%s ", buffer);
            printf("\n================================\n");
        }
        fclose(pDb);
    } else {
        printf("НЕТУ ТАКОВА ФАЙЛИКА\n");
    }
}

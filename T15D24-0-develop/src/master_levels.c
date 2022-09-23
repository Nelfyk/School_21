#include "master_levels.h"

levels *selectL(FILE *pDb, int id) {
    levels *level = (levels *)malloc(sizeof(levels));
    int num = 0;
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fseek(pDb, sizeof(int) * 2, SEEK_CUR);
    }
    level->mmry_level = num;
    fread(&level->cell, sizeof(int), 1, pDb);
    fread(&level->flag, sizeof(int), 1, pDb);
    return level;
}
void insertL(FILE *pDb, levels *level) {
    int num = 0;
    int count = 0;
    while (fread(&num, sizeof(int), 1, pDb) != 0) {
        (num == level->mmry_level) ? (count++) : (count += 0);
        fseek(pDb, sizeof(int) * 2, SEEK_CUR);
    }
    if (!count) {
        fseek(pDb, 0, SEEK_END);
        fwrite(&level->mmry_level, sizeof(int), 1, pDb);
        fwrite(&level->cell, sizeof(int), 1, pDb);
        fwrite(&level->flag, sizeof(int), 1, pDb);
        checkModules();
    } else {
        system("clear");
        printf("\n\e[1;91mACCESS DENIED.\e[m\n\n");
    }
}
void updateL(FILE *pDb, int id, levels *level) {
    int num = 0;
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fseek(pDb, sizeof(int) * 2, SEEK_CUR);
    }
    fseek(pDb, -(sizeof(int)), SEEK_CUR);
    fwrite(&num, sizeof(int), 1, pDb);
    fwrite(&level->cell, sizeof(int), 1, pDb);
    fwrite(&level->flag, sizeof(int), 1, pDb);
    checkModules();
}
void deleteL(FILE *pDb, int id) {
    int num = 0;
    FILE *pTemp = fopen("../materials/temp", "wb");
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(&num, sizeof(int), 1, pDb);
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(&num, sizeof(int), 1, pDb);
        fwrite(&num, sizeof(int), 1, pTemp);
    }
    fseek(pDb, sizeof(int) * 2, SEEK_CUR);
    while (fread(&num, sizeof(int), 1, pDb) != 0) {
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(&num, sizeof(int), 1, pDb);
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(&num, sizeof(int), 1, pDb);
        fwrite(&num, sizeof(int), 1, pTemp);
    }
    fclose(pTemp);
    fclose(pDb);
    pDb = fopen("../materials/master_levels.db", "wb");
    pTemp = fopen("../materials/temp", "r+b");
    fseek(pTemp, 0, SEEK_SET);
    while (fread(&num, sizeof(int), 1, pTemp) != 0) {
        fwrite(&num, sizeof(int), 1, pDb);
        fread(&num, sizeof(int), 1, pTemp);
        fwrite(&num, sizeof(int), 1, pDb);
        fread(&num, sizeof(int), 1, pTemp);
        fwrite(&num, sizeof(int), 1, pDb);
    }
    fclose(pTemp);
    system("rm -f ../materials/temp");
    checkModules();
}
int check(int level, int cell) {
    FILE *pDb = levelsDb(1);
    int num = 0;
    int q = 1;
    int a = 0, b = 0;
    while (q != 0) {
        if (num != level) {
            q = fread(&num, sizeof(int), 1, pDb);
            fseek(pDb, sizeof(int) * 2, SEEK_CUR);
        } else {
            fseek(pDb, -(sizeof(int) * 2), SEEK_CUR);
            a = 1;
            fread(&num, sizeof(int), 1, pDb);
            (num >= cell) ? (b = 1) : (b += 0);
            q = 0;
        }
    }
    fclose(pDb);
    return a && b;
}
int checkDef(int level) {
    FILE *pDb = levelsDb(1);
    int num = 0;
    int q = 1;
    while (q != 0) {
        if (num != level) {
            q = fread(&num, sizeof(int), 1, pDb);
            fseek(pDb, sizeof(int) * 2, SEEK_CUR);
        } else {
            fseek(pDb, -(sizeof(int)), SEEK_CUR);
            fread(&num, sizeof(int), 1, pDb);
            q = 0;
        }
    }
    fclose(pDb);
    return num;
}
void killV_L() {
    int num = 1;
    FILE *pDb = levelsDb(0);
    fseek(pDb, sizeof(int) * 2, SEEK_SET);
    fwrite(&num, sizeof(int), 1, pDb);
    fclose(pDb);
    printf("\n\e[1;91mLEVEL - 1. PROTECTED.\e[m\n\n");
}

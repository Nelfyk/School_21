#include "master_modules.h"

modules *selectM(FILE *pDb, int id) {
    modules *module = (modules *)malloc(sizeof(modules));
    int num = 0;
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fseek(pDb, 32 + sizeof(int) * 3, SEEK_CUR);
    }
    module->id = num;
    fread(module->name, sizeof(char), 32, pDb);
    fread(&module->level, sizeof(int), 1, pDb);
    fread(&module->cell, sizeof(int), 1, pDb);
    fread(&module->flag, sizeof(int), 1, pDb);
    return module;
}
void insertM(FILE *pDb, modules *module) {
    if (!checkDef(module->level)) {
        fseek(pDb, 0, SEEK_END);
        fwrite(&module->id, sizeof(int), 1, pDb);
        fwrite(module->name, 1, 32, pDb);
        fwrite(&module->level, sizeof(int), 1, pDb);
        fwrite(&module->cell, sizeof(int), 1, pDb);
        fwrite(&module->flag, sizeof(int), 1, pDb);
        logS(module->id, module->flag);
    } else {
        system("clear");
        printf("\n\e[1;91mACCESS DENIED.\e[m\n\n");
    }
}
void updateM(FILE *pDb, int id, modules *module) {
    int num = 0;
    int level = -1;
    int error = 0;
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fseek(pDb, 32 + sizeof(int) * 3, SEEK_CUR);
    }
    if (num == id) {
        fseek(pDb, 32, SEEK_CUR);
        fread(&level, sizeof(int), 1, pDb);
        if (!checkDef(level)) {
            fseek(pDb, -(32 + sizeof(int)), SEEK_CUR);
            fseek(pDb, -(sizeof(int)), SEEK_CUR);
            fwrite(&num, sizeof(int), 1, pDb);
            fwrite(module->name, 1, 32, pDb);
            fwrite(&module->level, sizeof(int), 1, pDb);
            fwrite(&module->cell, sizeof(int), 1, pDb);
            fwrite(&module->flag, sizeof(int), 1, pDb);
            logS(module->id, module->flag);
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error) {
        system("clear");
        printf("\n\e[1;91mACCESS DENIED.\e[m\n\n");
    }
}
void deleteM(FILE *pDb, int id) {
    int num = 0;
    int level = -1;
    int error = 0;
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fseek(pDb, 32 + sizeof(int) * 3, SEEK_CUR);
    }
    if (num == id) {
        fseek(pDb, 32, SEEK_CUR);
        fread(&level, sizeof(int), 1, pDb);
        if (!checkDef(level)) {
            fseek(pDb, -(32 + sizeof(int)), SEEK_CUR);
            fseek(pDb, 32 + sizeof(int) * 2, SEEK_CUR);
            num = 1;
            fwrite(&num, sizeof(int), 1, pDb);
            logS(id, 1);
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error) {
        system("clear");
        printf("\n\e[1;91mACCESS DENIED.\e[m\n\n");
    }
}
void checkModules() {
    FILE *pDb = modulesDb(0);
    int num = 0;
    int level, cell;
    rewind(pDb);
    while (fread(&num, sizeof(int), 1, pDb) != 0) {
        fseek(pDb, 32, SEEK_CUR);
        fread(&level, sizeof(int), 1, pDb);
        fread(&cell, sizeof(int), 1, pDb);
        fseek(pDb, -(32 + sizeof(int) * 3), SEEK_CUR);
        fseek(pDb, 32 + sizeof(int) * 3, SEEK_CUR);
        if (!check(level, cell)) {
            num = 1;
            fwrite(&num, sizeof(int), 1, pDb);
        } else {
            num = 0;
            fwrite(&num, sizeof(int), 1, pDb);
        }
    }
    fflush(pDb);
    fclose(pDb);
}
void killV_M() {
    int num = 0;
    FILE *pDb = modulesDb(0);
    rewind(pDb);
    while (fread(&num, sizeof(int), 1, pDb) != 0) {
        fseek(pDb, 32, SEEK_CUR);
        fread(&num, sizeof(int), 1, pDb);
        fread(&num, sizeof(int), 1, pDb);
        fseek(pDb, -(32 + sizeof(int) * 3), SEEK_CUR);
        fseek(pDb, 32 + sizeof(int) * 3, SEEK_CUR);
        num = 1;
        fwrite(&num, sizeof(int), 1, pDb);
    }
    printf("\n\e[1;91mAll modules is off.\e[m\n\n");
    rewind(pDb);
    fseek(pDb, 32 + sizeof(int), SEEK_CUR);
    num = 1;
    fwrite(&num, sizeof(int), 1, pDb);
    fwrite(&num, sizeof(int), 1, pDb);
    fseek(pDb, -(32 + sizeof(int) * 3), SEEK_CUR);
    fseek(pDb, 32 + sizeof(int) * 3, SEEK_CUR);
    num = 20;
    fwrite(&num, sizeof(int), 1, pDb);
    fflush(pDb);
    fclose(pDb);
    printf("\n\e[1;91mAI MOVED IN LEVEL - 1, CELL - 1.\e[m\n\n");
    printf("\n\e[1;91mPROTECTION MODULE - 20.\e[m\n\n");
}
void showAllOn() {
    int num = 0;
    int count = 0;
    char buf[33] = {0};
    FILE *pDb = modulesDb(1);
    rewind(pDb);
    while (fread(&num, sizeof(int), 1, pDb) != 0) {
        fseek(pDb, 32, SEEK_CUR);
        fread(&num, sizeof(int), 1, pDb);
        fread(&num, sizeof(int), 1, pDb);
        fread(&num, sizeof(int), 1, pDb);
        if (num == 0) {
            fseek(pDb, -(32 + sizeof(int) * 4), SEEK_CUR);
            fread(&num, sizeof(int), 1, pDb);
            printf("%i ", num);
            fread(buf, sizeof(char), 32, pDb);
            printf("%s ", buf);
            fread(&num, sizeof(int), 1, pDb);
            printf("%i ", num);
            fread(&num, sizeof(int), 1, pDb);
            printf("%i ", num);
            fread(&num, sizeof(int), 1, pDb);
            printf("%i", num);
            printf("\n================================\n");
            count++;
        }
    }
    if (!count) {
        system("clear");
        printf("\n\e[1;91mALL MODULES IS OFF.\e[m\n\n");
    }
    fclose(pDb);
}

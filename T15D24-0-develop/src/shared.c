#include "shared.h"

void select(int DB_Num, int id) {
    FILE *pDb = NULL;
    if (DB_Num == 1) {
        pDb = modulesDb(1);
        modules *module = selectM(pDb, id);
        if (module->id == id) {
            printf("%i %s %i %i %i\n", module->id, module->name, module->level, module->cell, module->flag);
        } else {
            system("clear");
            printf("\n\e[1;91mACCESS DENIED.\e[m\n\n");
        }
        //
        free(module);
        //
    } else {
        if (DB_Num == 2) {
            pDb = levelsDb(1);
            levels *level = selectL(pDb, id);
            if (level->mmry_level == id) {
                printf("%i %i %i\n", level->mmry_level, level->cell, level->flag);
            } else {
                system("clear");
                printf("\n\e[1;91mACCESS DENIED.\e[m\n\n");
            }
            //
            free(level);
            //
        } else {
            if (DB_Num == 3) {
                pDb = statusEventsDb(1);
                statusEvents *statusE = selectS(pDb, id);
                if (statusE->ev_id == id) {
                    printf("%i %i %i %s %s\n", statusE->ev_id, statusE->module_id,
                           statusE->new_status, statusE->date_change, statusE->time_change);
                } else {
                    system("clear");
                    printf("\n\e[1;91mACCESS DENIED.\e[m\n\n");
                }
                //
                free(statusE);
                //
            }
        }
    }
    fflush(pDb);
    fclose(pDb);
}
void insert(int DB_Num) {
    FILE *pDb = NULL;
    if (DB_Num == 1) {
        pDb = modulesDb(0);
        modules *module = (modules *)malloc(sizeof(modules));
        modules *temp = selectM(pDb, 10000);
        module->id = temp->id + 1;
        //
        free(temp);
        //
        printf("Enter by type: Some_module_4 2 0 \n");
        if (scanf("%20s %i %i %i", module->name, &module->level, &module->cell, &module->flag)) {
            insertM(pDb, module);
        }
        //
        free(module);
        //
    } else {
        if (DB_Num == 2) {
            pDb = levelsDb(0);
            levels *level = (levels *)malloc(sizeof(levels));
            printf("Enter by type: 2 2 0 \n");
            if (scanf("%i %i %i", &level->mmry_level, &level->cell, &level->flag)) {
                insertL(pDb, level);
            }
            //
            free(level);
            //
        } else {
            if (DB_Num == 3) {
                pDb = statusEventsDb(0);
                statusEvents *statusE = (statusEvents *)malloc(sizeof(statusEvents));
                statusEvents *temp = selectS(pDb, 10000);
                statusE->ev_id = temp->ev_id + 1;
                //
                free(temp);
                //
                printf("Enter by type: 44 1 03.02.2020 23:10:11 \n");
                if (scanf("%i %i %20s %20s", &statusE->module_id, &statusE->new_status,
                          statusE->date_change, statusE->time_change)) {
                    insertS(pDb, statusE);
                }
                //
                free(statusE);
                //
            }
        }
    }
    fclose(pDb);
}
void update(int DB_Num, int id) {
    FILE *pDb = NULL;
    if (DB_Num == 1) {
        pDb = modulesDb(0);
        modules *module = (modules *)malloc(sizeof(modules));
        printf("Enter by type: Some module 4 2 0 \n");
        if (scanf("%20s %i %i %i", module->name, &module->level, &module->cell, &module->flag)) {
            updateM(pDb, id, module);
        }
        //
        free(module);
        //
    } else {
        if (DB_Num == 2) {
            pDb = levelsDb(0);
            levels *level = (levels *)malloc(sizeof(levels));
            printf("Enter by type: 2 0 \n");
            if (scanf("%i %i", &level->cell, &level->flag)) {
                updateL(pDb, id, level);
            }
            //
            free(level);
            //
        } else {
            if (DB_Num == 3) {
                pDb = statusEventsDb(0);
                statusEvents *statusE = (statusEvents *)malloc(sizeof(statusEvents));
                printf("Enter by type: 44 1 03.02.2020 23:10:11 \n");
                if (scanf("%i %i %20s %20s", &statusE->module_id, &statusE->new_status,
                          statusE->date_change, statusE->time_change)) {
                    updateS(pDb, id, statusE);
                }
                //
                free(statusE);
                //
            }
        }
    }
    fclose(pDb);
}
void delete (int DB_Num, int id) {
    FILE *pDb = NULL;
    if (DB_Num == 1) {
        pDb = modulesDb(0);
        deleteM(pDb, id);
    } else {
        if (DB_Num == 2) {
            pDb = levelsDb(0);
            deleteL(pDb, id);
        } else {
            if (DB_Num == 3) {
                pDb = statusEventsDb(0);
                deleteS(pDb, id);
            }
        }
    }
    fclose(pDb);
}

FILE *modulesDb(int mode) {
    char modeFile[5];
    (mode) ? (strcpy(modeFile, "rb")) : (strcpy(modeFile, "r+b"));
    FILE *pDb = fopen("../materials/master_modules.db", modeFile);
    return pDb;
}
FILE *levelsDb(int mode) {
    char modeFile[5];
    (mode) ? (strcpy(modeFile, "rb")) : (strcpy(modeFile, "r+b"));
    FILE *pDb = fopen("../materials/master_levels.db", modeFile);
    return pDb;
}
FILE *statusEventsDb(int mode) {
    char modeFile[5];
    (mode) ? (strcpy(modeFile, "rb")) : (strcpy(modeFile, "r+b"));
    FILE *pDb = fopen("../materials/master_status_events.db", modeFile);
    return pDb;
}

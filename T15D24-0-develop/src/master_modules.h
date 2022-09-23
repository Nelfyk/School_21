#ifndef SRC_MASTER_MODULES_H_
#define SRC_MASTER_MODULES_H_
#include "master_status_events.h"
#include "shared.h"
typedef struct modules {
    int id;
    char name[32];
    int level;
    int cell;
    int flag;
} modules;
modules *selectM(FILE *pDb, int id);
void insertM(FILE *pDb, modules *module);
void updateM(FILE *pDb, int id, modules *module);
void deleteM(FILE *pDb, int id);
void checkModules();
int checkDef(int level);
void killV_M();
void showAllOn();
#endif  //  SRC_MASTER_MODULES_H_

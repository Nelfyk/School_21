#ifndef SRC_MASTER_LEVELS_H_
#define SRC_MASTER_LEVELS_H_
#include "shared.h"
typedef struct levels {
    int mmry_level;
    int cell;
    int flag;
} levels;
levels *selectL(FILE *pDb, int id);
void insertL(FILE *pDb, levels *level);
void updateL(FILE *pDb, int id, levels *level);
void deleteL(FILE *pDb, int id);
int check(int level, int cell);
void killV_L();
#endif  //  SRC_MASTER_LEVELS_H_

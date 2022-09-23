#ifndef SRC_MASTER_STATUS_EVENTS_H_
#define SRC_MASTER_STATUS_EVENTS_H_

#include "master_modules.h"
#include "shared.h"
typedef struct statusEvents {
    int ev_id;
    int module_id;
    int new_status;
    char date_change[11];
    char time_change[9];
} statusEvents;
statusEvents *selectS(FILE *pDb, int id);
void insertS(FILE *pDb, statusEvents *statusE);
void updateS(FILE *pDb, int id, statusEvents *statusE);
void deleteS(FILE *pDb, int id);
void logS(int id, int flag);
#endif  // SRC_MASTER_STATUS_EVENTS_H_

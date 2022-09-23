#ifndef SRC_SHARED_H_
#define SRC_SHARED_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"
#include "modules_db.h"
#include "test.h"  // удалить здесь и в makefile

void select(int DB_Num, int id);
void insert(int DB_Num);
void update(int DB_Num, int id);
void delete (int DB_Num, int id);
FILE *modulesDb(int mode);
FILE *levelsDb(int mode);
FILE *statusEventsDb(int mode);
#endif  //  SRC_SHARED_H_

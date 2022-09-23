#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000
typedef struct door {
    int id;
    int status;
} door;
#endif  // SRC_DOOR_STRUCT_H_

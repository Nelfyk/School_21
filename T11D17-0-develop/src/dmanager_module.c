#include "door_struct.h"

void initialize_doors(door *doors);
void sort(door *a);
void output(door *a);

int main() {
    door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    output(doors);

    return 0;
}
void sort(door *a) {
    door temp;
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT; j++) {
            a[j].status = 0;
            if (a[j].id > a[j + 1].id) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(door *a) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%i, ", a[i].id);
        printf("%i\n", a[i].status);
    }
}
// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

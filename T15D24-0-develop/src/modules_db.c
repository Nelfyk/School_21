#include "modules_db.h"

int main() {
    /*-----------------------------------------
            T E S T    F U N C T I O N
    ------------------------------------------*/
    // outputModulesAll();
    // outputLevelsAll();
    // outputStatusEventsAll();
    // select();
    /*-----------------------------------------
                     M A I N
    // ------------------------------------------*/
    menu();
    /*----------------------------------------------------------------------
    -----------------------------------------------------------------------*/
    return 0;
}

void menu() {
    int ch = -1;
    while (ch != 0) {
        printf("Please choose one operation:\n\t1. SELECT\n\t2. INSERT\n\t");
        printf("3. UPDATE\n\t4. DELETE\n\t7. Get all active additional modules");
        printf("\n\t8. Display all\n\t\e[1;91m9. KILL VERTER\e[m");
        printf("\n\t0. EXIT\n> ");
        if (scanf("%i", &ch)) {
            (ch >= 1 && ch <= 4) ? (ch_14(ch)) : (ch += 0);
            (ch == 7) ? (ch_7()) : (ch == 8) ? (ch_8(ch))
                               : (ch == 9)   ? (killVerter())
                                             : (ch += 0);
        } else {
            getchar();
            system("clear");
        }
    }
    printf("Good bye.\n");
}
void ch_14(int ch) {
    int db, id;
    printf("Please choose a table:\n\t1. Modules\n\t2. Levels\n\t3. Status events\n> ");
    if (scanf("%i", &db)) {
        if (ch != 2) {
            printf("Insert the number of record: ");
            if (scanf("%i", &id)) {
                (ch == 1) ? (select(db, id)) : (ch == 3) ? (update(db, id))
                                           : (ch == 4)   ? (delete (db, id))
                                                         : (ch += 0);
            }
        } else {
            insert(db);
        }
    }
}
void ch_8() {
    int db;
    printf("Please choose a table:\n\t1. Modules\n\t2. Levels\n\t3. Status events\n> ");
    if (scanf("%i", &db)) {
        (db == 1) ? (outputModulesAll()) : (db == 2) ? (outputLevelsAll())
                                       : (db == 3)   ? (outputStatusEventsAll())
                                                     : (db += 0);
    }
}
void ch_7() {
    showAllOn();
}
void killVerter() {
    killV_M();
    killV_L();
}
/*
выключить все его включенные дополнительные модули (перевести их статус в 0),
удалить записи про них (простановкой соответствующего флага в 1),
а главный модуль (c id 0) перевести в защищенный режим
(последовательным переводом в статус 0, затем 1, затем - 20), и переместить его в
первую ячейку первого уровня памяти с выставлением этому уровню флага защищенности 1.
*/

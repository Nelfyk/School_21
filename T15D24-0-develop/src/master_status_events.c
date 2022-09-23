#include "master_status_events.h"

statusEvents *selectS(FILE *pDb, int id) {
    statusEvents *statusE = (statusEvents *)malloc(sizeof(statusEvents));
    int num = 0;
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fseek(pDb, sizeof(int) * 2 + 20, SEEK_CUR);
    }
    statusE->ev_id = num;
    fread(&statusE->module_id, sizeof(int), 1, pDb);
    fread(&statusE->new_status, sizeof(int), 1, pDb);
    fread(statusE->date_change, sizeof(char), 11, pDb);
    fread(statusE->time_change, sizeof(char), 9, pDb);
    return statusE;
}
void insertS(FILE *pDb, statusEvents *statusE) {
    fseek(pDb, 0, SEEK_END);
    fwrite(&statusE->ev_id, sizeof(int), 1, pDb);
    fwrite(&statusE->module_id, sizeof(int), 1, pDb);
    fwrite(&statusE->new_status, sizeof(int), 1, pDb);
    fwrite(&statusE->date_change, sizeof(char), 11, pDb);
    fwrite(&statusE->time_change, sizeof(char), 9, pDb);
}
void updateS(FILE *pDb, int id, statusEvents *statusE) {
    int num = 0;
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fseek(pDb, sizeof(int) * 2 + 20, SEEK_CUR);
    }
    fseek(pDb, -(sizeof(int)), SEEK_CUR);
    fwrite(&num, sizeof(int), 1, pDb);
    fwrite(&statusE->module_id, sizeof(int), 1, pDb);
    fwrite(&statusE->new_status, sizeof(int), 1, pDb);
    fwrite(&statusE->date_change, sizeof(char), 11, pDb);
    fwrite(&statusE->time_change, sizeof(char), 9, pDb);
}
void deleteS(FILE *pDb, int id) {
    int num = 0;
    char buffer[15] = {0};
    FILE *pTemp = fopen("../materials/temp", "wb");
    while (fread(&num, sizeof(int), 1, pDb) != 0 && num != id) {
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(&num, sizeof(int), 1, pDb);
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(&num, sizeof(int), 1, pDb);
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(buffer, sizeof(char), 11, pDb);
        fwrite(&buffer, sizeof(char), 11, pTemp);
        fread(buffer, sizeof(char), 9, pDb);
        fwrite(&buffer, sizeof(char), 9, pTemp);
    }
    fseek(pDb, sizeof(int) * 2 + 20, SEEK_CUR);
    while (fread(&num, sizeof(int), 1, pDb) != 0) {
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(&num, sizeof(int), 1, pDb);
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(&num, sizeof(int), 1, pDb);
        fwrite(&num, sizeof(int), 1, pTemp);
        fread(buffer, sizeof(char), 11, pDb);
        fwrite(&buffer, sizeof(char), 11, pTemp);
        fread(buffer, sizeof(char), 9, pDb);
        fwrite(&buffer, sizeof(char), 9, pTemp);
    }
    fclose(pTemp);
    fclose(pDb);
    pDb = fopen("../materials/master_status_events.db", "wb");
    pTemp = fopen("../materials/temp", "r+b");
    fseek(pTemp, 0, SEEK_SET);
    while (fread(&num, sizeof(int), 1, pTemp) != 0) {
        fwrite(&num, sizeof(int), 1, pDb);
        fread(&num, sizeof(int), 1, pTemp);
        fwrite(&num, sizeof(int), 1, pDb);
        fread(&num, sizeof(int), 1, pTemp);
        fwrite(&num, sizeof(int), 1, pDb);
        fread(buffer, sizeof(char), 11, pTemp);
        fwrite(&buffer, sizeof(char), 11, pDb);
        fread(buffer, sizeof(char), 9, pTemp);
        fwrite(&buffer, sizeof(char), 9, pDb);
    }
    fclose(pTemp);
    system("rm -f ../materials/temp");
}
void logS(int id, int flag) {
    FILE *pDb = fopen("../materials/master_status_events.db", "r+b");
    time_t t = time(NULL);
    char buf[64];
    statusEvents *statusE = selectS(pDb, 10000);
    statusE->ev_id += 1;
    statusE->module_id = id;
    statusE->new_status = flag;
    strftime(buf, sizeof(buf), "%d.%m.%Y", localtime(&t));
    strcpy(statusE->date_change, buf);
    strftime(buf, sizeof(buf), "%H:%M:%S", localtime(&t));
    strcpy(statusE->time_change, buf);
    insertS(pDb, statusE);
    //
    free(statusE);
    //
    fclose(pDb);
}

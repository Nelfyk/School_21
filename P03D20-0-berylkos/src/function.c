#include "function.h"
// --------------------------------F_U_N_C_T_I_O_N---------------------------------

void parse(char *a, int length, stack **headStack, queue **headQueue) {
    char num[10] = {0};
    char operands[OPER] = {'+', '-', '*', '/', '(', ')', 's', 'c', 't', 'k', 'q', 'l'};
    char prior[OPER] = {1, 1, 2, 2, 0, 5, 10, 10, 10, 10, 10, 10};
    int tempCounter = 0;

    for (int i = 0, count = 0; i < length; i++) {
        int typeFlag = 0;

        printf("\nДействие: %i из %i\n", i, length);
        // --------------------------------SIMBOLS--------------------------------

        for (int j = 0; j < OPER && !typeFlag; j++) {
            if ((a[i] == operands[j]) && !(i == 0 && a[i] == '-') && !(a[i - 1] == '(' && a[i] == '-') && (a[i] != '(' && a[i] != ')') && j < 5) {
                printf("\n_______SIMBOL: %c_______\n", operands[j]);
                // проверка на приоритет в стеке перед push
                if (*headStack && ((*headStack)->prior >= prior[j])) {
                    printf("\n_______POP_______\n");
                    pushQueue(headQueue, 0, pop(headStack), 0);
                }
                pushStack(headStack, prior[j], operands[j]);
                ((*headStack)->next && (*headStack)->next->prior >= (*headStack)->prior) ? (pushQueue(headQueue, 0, pop(&((*headStack)->next)), 0)) : (typeFlag += 0);  // если избавили и встретились с таким же
                typeFlag++;
            } else {  // СО СКОБКАМИ
                if (a[i] == '(' && a[i] == operands[j]) {
                    printf("\n_______SIMBOL: %c_______\n", a[i]);
                    pushStack(headStack, prior[j], operands[j]);
                } else {
                    if (a[i] == ')' && a[i] == operands[j]) {
                        printf("\n_______SIMBOL: %c_______\n", a[i]);
                        while (*headStack && (*headStack)->oper != '(') {
                            pushQueue(headQueue, 0, pop(headStack), 0);
                        }
                        pop(headStack);
                    } else {
                        if (a[i] == 's' && a[i + 1] == 'i' && a[i + 2] == 'n') {
                            i += 2;  // инкрементируем i
                            pushStack(headStack, 10, 's');
                        } else {
                            if (a[i] == 'c' && a[i + 1] == 'o' && a[i + 2] == 's') {
                                i += 2;  // инкрементируем i
                                pushStack(headStack, 10, 'c');
                            } else {
                                if (a[i] == 't' && a[i + 1] == 'a' && a[i + 2] == 'n') {
                                    i += 2;  // инкрементируем i
                                    pushStack(headStack, 10, 't');
                                } else {
                                    if (a[i] == 'c' && a[i + 1] == 't' && a[i + 2] == 'g') {
                                        i += 2;  // инкрементируем i
                                        pushStack(headStack, 10, 'k');
                                    } else {
                                        if (a[i] == 's' && a[i + 1] == 'q' && a[i + 2] == 'r' && a[i + 3] == 't') {
                                            i += 3;  // инкрементируем i
                                            pushStack(headStack, 10, 'q');
                                        } else {
                                            if (a[i] == 'l' && a[i + 1] == 'n') {
                                                i++;  // инкрементируем i
                                                pushStack(headStack, 10, 'l');
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // --------------------------------VALUE--------------------------------
        if (!typeFlag && ((a[i] >= '0' && a[i] <= '9' && a[i] != ' ') || (i == 0 && a[i] == '-') || (a[i] == '-' && a[i - 1] == '('))) {
            tempCounter++;
            num[count] = a[i];
            // printf("num[count]===%c===\n",num[count]);
            // printf("i===%i===\n",i);
            // printf("count===%i===\n",count);
            // printf("a[i]===%c===\n",a[i]);
            // printf("a[i+1]===%c===\n",a[i+1]);
            // printf("num===%s===\n",num);
            // printf("atoi(num)===%i===\n",atoi(num));

            printf("\n_______VALUE: %c_______\n", a[i]);

            if (a[i + 1] >= '0' && a[i + 1] <= '9') {
                count++;
            } else {
                pushQueue(headQueue, 1, 'q', atoi(num));
                count = 0;
                strcpy(num, "empty");  // обнуление массива
            }
        } else {
            (count > 0) ? (pushQueue(headQueue, 1, 'q', atoi(num))) : (count += 0);
            if (count > 0) {
                strcpy(num, "empty");  // обнуление массива
            }
            count = 0;
        }
        printf("tempCounter===%i===\n", tempCounter);

        (*headQueue) ? (printf("Q_HEAD -> %c or %.0lf\n", (*headQueue)->makeOper, (*headQueue)->makeNum)) : (typeFlag += 0);
        (*headStack) ? (printf("S_HEAD -> %c\n", (*headStack)->oper)) : (typeFlag += 0);
    }
    for (int i = 0; *headStack; i++) {  // пушим остатки из стека
        pushQueue(headQueue, 0, pop(headStack), 0);
    }
}
stack *initStack() {
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->next = NULL;
    return temp;
}
queue *initQueue() {
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->next = NULL;
    return temp;
}
void initResult(queue **headResult, queue **headQueue) {  // reverse stack
    while ((*headQueue)) {
        pushQueue(headResult, (*headQueue)->type, (*headQueue)->makeOper, (*headQueue)->makeNum);
        popQ(headQueue);
    }
}

double result(queue *headResult) { // << не реализованная функция
    double res = 0;
    queue *temp = NULL;

    while (headResult) {
        if (headResult->type) {
            printf("_ALARM_");
            pushQueue(&temp, 1, 'q', headResult->makeNum);
            headResult = headResult->next;
        } else {
            if (headResult->makeOper == '+') {
                printf("_+_");
                res = headResult->makeNum + headResult->next->makeNum;
                pushQueue(&temp, 1, 'q', res);
                headResult = headResult->next->next;
            }
        }
        // headResult=headResult->next;
        printf("___1__");
    }

    // printf("___HEAD: %.4lf",headResult->makeNum);
    // while(headResult){
    //     if(headResult->type){
    //         printf("_ALARM_");
    //         pushQueue(&temp, 1, 'q', headResult->makeNum);
    //         popQ(&headResult);
    //     } else {
    //         if(headResult->makeOper=='+'){
    //             printf("_ALARM_")
    //             res=popQ(&temp)+popQ(&(temp->next));
    //             calc->makeNum=res;
    //             pushQueue(&temp, 1, 'q', calc->makeNum);
    //         } else {
    //             if(headResult->makeOper=='-'){
    //                 calc->makeNum=popQ(&temp)-popQ(&(temp->next));
    //                 pushQueue(&temp, 1, 'q', calc->makeNum);
    //             } else {
    //                 if (headResult->makeOper=='*'){
    //                     calc->makeNum=popQ(&temp)*popQ(&(temp->next));
    //                     pushQueue(&temp, 1, 'q', calc->makeNum);
    //                 } else {
    //                     if(headResult->makeOper=='/'){
    //                     calc->makeNum=popQ(&temp)/popQ(&(temp->next));
    //                     pushQueue(&temp, 1, 'q', calc->makeNum);
    //                     }
    //                 }
    //             }
    //         }
    //         headResult = headResult->next;
    //     }
    //     // popQ(&headResult);
    // }
    printf("___RESULT: %.2lf", temp->makeNum);
    return 0;
}

int inputS(char *a) {
    char temp[300];
    int length = 0;
    for (int i = 0, q = 0; !q; i++) {
        scanf("%c", &temp[i]);
        (temp[i] == '\n') ? (q++) : (q += 0);
        (!q) ? (a[i] = temp[i]) : (q += 0);
        (!q) ? (length++) : (length += 0);
    }
    for (int i = 0; i < length; i++) {
        a[i] = tolower(a[i]);
    }
    return length;
}
void pushQueue(queue **head, const int type, const char makeOper, const double makeNum) {
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->next = *head;
    temp->type = type;  // 0 or 1
    temp->makeOper = makeOper;
    temp->makeNum = makeNum;
    *head = temp;
}
void pushStack(stack **head, const int prior, const char oper) {
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->next = *head;
    temp->prior = prior;
    temp->oper = oper;
    *head = temp;
}
char pop(stack **head) {
    stack *temp = NULL;
    char value = 'q';  // если пуст - q
    if (head != NULL) {
        temp = (*head)->next;
        value = (*head)->oper;
        free(*head);
        *head = temp;
    }
    return value;
}
char popQ(queue **head) {
    queue *temp = NULL;
    char value = 'q';  // если пуст - q
    if (head != NULL) {
        temp = (*head)->next;
        value = (*head)->makeOper;
        free(*head);
        *head = temp;
    }
    return value;
}
void destroy(stack *head) {
    stack *prev = NULL;
    while (head) {
        prev = head;
        head = head->next;
        free(prev);
    }
    free(head);
}
// 0 - stack | 1 - queue
void output(const stack *headStack, const queue *headQueue, int choice) {
    if (!choice) {  // 0
        while (headStack) {
            printf("%c ", headStack->oper);
            headStack = headStack->next;
        }
    } else {  // 1
        while (headQueue) {
            (headQueue->type) ? (printf("%.1lf ", headQueue->makeNum)) : (printf("%c ", headQueue->makeOper));
            headQueue = headQueue->next;
        }
    }
    printf("\n");
}

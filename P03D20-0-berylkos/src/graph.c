#include "function.h"
// -----------------------------------M_A_I_N--------------------------------------
int main() {
    char a[300];

    stack *headStack = initStack();
    queue *headQueue = initQueue();
    int length=inputS(a);  // ввод строки
    parse(a,length, &headStack, &headQueue);
    output(headStack, headQueue, 0);
    output(headStack, headQueue, 1);
    queue *headResult = NULL;
    initResult(&headResult, &headQueue);
    output(headStack, headResult, 1);
    // result(headResult); << результирующая ф-ция. не работает
    return 0;
}


/*
    -Программа выполняет преобразование из инфиксной в постфиксную запись использовав два стека.
    с учетом функций >> (sin(x), cos(x), tan(x), ctg(x), sqrt(x), ln(x)), а так же любого регистра
    -В конце выполняется реверс стека для математических операций.


_ в файле "paintGraphic.c" функция отрисовки графика(не проверена).     
_ сайт который очень помог: https://habr.com/ru/post/489744/
*/
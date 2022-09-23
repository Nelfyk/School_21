#include <ncurses.h>

#define ROWS 25
#define COLS 80
#define DIE 0
#define LIVE 1

void paint(int *a, int q);
void read_file(int *a);
int searchLife(int *a, int cY, int cX);
void body(int *a, int *b);
void game();
void swap(int *a, int *b);
void checkWorld(int *a, int *b, int *q);
int keyHandling(int delay, int *q);
void visual();

int main() {
    game();
    return 0;
}

void game() {
    int world_prev[ROWS][COLS];
    int world_next[ROWS][COLS];
    int delay = 300;
    int q = 0;

    read_file((int *)world_prev);
    initscr();  // запуск терминала ncurses
    visual();
    while (!q) {
        timeout(delay);  // задержка для getch
        clear();
        paint((int *)world_prev, q);
        body((int *)world_prev, (int *)world_next);
        swap((int *)world_prev, (int *)world_next);
        checkWorld((int *)world_prev, (int *)world_next, &q);
        delay = keyHandling(delay, &q);
    }
    endwin();  // выход из ncurses

    // Финальная отрисовка
    paint((int *)world_prev, q);
    printf("\n\e[1;91mTHE END?\e[m");
}

void visual() {
    noecho();  // выключение отображение ввода
    raw();     // полный контроль клавиатуры
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // определение цветовой пары #1
    attrset(COLOR_PAIR(1));                  // исп. цвет. пары #1
}

int keyHandling(int delay, int *q) {
    char key = getch();
    (key == '1') ? (delay = 300) : (key == '2') ? (delay = 200)
                               : (key == '3')   ? (delay = 100)
                               : (key == '4')   ? (delay = 50)
                               : (key == '5')   ? (delay = 20)
                               : (key == 'q')   ? (*q = 1)
                                                : (delay += 0);
    return delay;
}

void checkWorld(int *a, int *b, int *q) {
    int count = 0;
    for (int *p = a, *r = b; p - a < ROWS * COLS; p++, r++) {
        if (*p == *r) {
            count++;
        }
    }
    if (count == 2000) {
        *q = 1;
    }
}

void swap(int *a, int *b) {
    int temp[ROWS][COLS];
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            temp[x][y] = *(a + y + COLS * x);
            *(a + y + COLS * x) = *(b + y + COLS * x);
            *(b + y + COLS * x) = temp[x][y];
        }
    }
}

void paint(int *a, int q) {
    for (int y = 0; y <= ROWS + 1; y++) {
        for (int x = 0; x <= COLS + 1; x++) {
            if (x == 0 || x == COLS + 1) {
                (!q) ? (mvprintw(y, x, "/")) : (printf("\e[1;92m/"));  // боковые стены
            } else {
                if (y == 0 || y == ROWS + 1) {
                    (!q) ? (mvprintw(y, x, "-")) : (printf("\e[1;92m-"));  // потолок и пол
                } else {
                    if (*(a + (y - 1) * COLS + (x - 1)) == 1) {
                        (!q) ? (mvprintw(y, x, "*")) : (printf("\e[1;92m*"));  // если L - жив
                    } else {
                        (!q) ? (mvprintw(y, x, " ")) : (printf(" "));  // если D - мертв
                    }
                }
            }
        }
        printf("\n");
    }
}

int searchLife(int *a, int cY, int cX) {
    int count = 0;
    count += *(a + ((cY - 1) + COLS) % COLS + (((cX - 1) + ROWS) % ROWS) * COLS);
    count += *(a + ((cY) + COLS) % COLS + (((cX - 1) + ROWS) % ROWS) * COLS);
    count += *(a + ((cY + 1) + COLS) % COLS + (((cX - 1) + ROWS) % ROWS) * COLS);
    count += *(a + ((cY + 1) + COLS) % COLS + (((cX) + ROWS) % ROWS) * COLS);
    count += *(a + ((cY - 1) + COLS) % COLS + (((cX) + ROWS) % ROWS) * COLS);
    count += *(a + ((cY - 1) + COLS) % COLS + (((cX + 1) + ROWS) % ROWS) * COLS);
    count += *(a + ((cY) + COLS) % COLS + (((cX + 1) + ROWS) % ROWS) * COLS);
    count += *(a + ((cY + 1) + COLS) % COLS + (((cX + 1) + ROWS) % ROWS) * COLS);
    return count;
}

void body(int *a, int *b) {
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            int lifes = searchLife(a, y, x);
            int cell_state = *(a + y + COLS * x);
            int *cell_next_state = (b + y + COLS * x);
            if (lifes == 3 && cell_state == 0) {
                *cell_next_state = LIVE;
            } else if ((lifes == 2 || lifes == 3) && cell_state == 1) {
                *cell_next_state = LIVE;
            } else {
                *cell_next_state = DIE;
            }
        }
    }
}

void read_file(int *a) {
    char file_number[16], file_name[256];
    FILE *init_file;
    printf("Enter file name (number): ");
    scanf("%15s", file_number);
    sprintf(file_name, "%s%s", file_number, ".txt");
    init_file = fopen(file_name, "r");
    for (int *p = a; p - a < ROWS * COLS && fscanf(init_file, "%1d", p) != EOF;
         p++) {
    }
}

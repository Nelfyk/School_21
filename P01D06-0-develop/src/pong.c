// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

// ok

#include <stdio.h>

void paint(int player1, int player2, int ballX, int ballY);
void update(int player1, int player2, int ballX, int ballY);

int main() {
    int player1 = 10;  // координаты первой ракетки
    int player2 = 10;  // -//- второй ракетки
    int ballX = 39;    // координаты по Х мяча
    int ballY = 11;    // -//- по У мяча

    update(player1, player2, ballX, ballY);

    return 0;
}

void paint(int player1, int player2, int ballX, int ballY) {
    for (int y = 0; y < 27; y++) {
        for (int x = 0; x < 82; x++) {
            if (x == 0 || x == 81) {
                printf("/");
            } else {
                if (y == 0 || y == 26) {
                    printf("-");
                } else {
                    if ((y == player1 && x == 1) || (y == player1 + 1 && x == 1) ||
                        (y == player1 + 2 && x == 1)) {
                        printf("|");
                    } else {
                        if ((y == player2 && x == 80) || (y == player2 + 1 && x == 80) ||
                            (y == player2 + 2 && x == 80)) {
                            printf("|");
                        } else {
                            if (x == ballX && y == ballY) {
                                printf("@");
                            } else {
                                printf(" ");
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }
}
void update(int player1, int player2, int ballX, int ballY) {
    const int WIN = 21;
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;
    int restart = 0;

    int stepX = -1;
    int stepY = -1;
    char key, c;
    int q = 0;

    //==============// KEY'S
    while (!q) {
        int pressed = 0;
        while (!pressed) {
            printf("\033[0d\033[2J");
            printf(
                "\n\n                     Player_1 : %d      ||      Player_2 : %d\n",
                scorePlayer1, scorePlayer2);
            paint(player1, player2, ballX, ballY);
            scanf("%c%c", &key, &c);
            switch (key) {
                case 'a': {
                    if (player1 > 1 && c == '\n') {
                        player1--;
                        pressed++;
                    }
                    break;
                }
                case 'z': {
                    if (player1 < 23 && c == '\n') {
                        player1++;
                        pressed++;
                    }
                    break;
                }
                case 'k': {
                    if (player2 > 1 && c == '\n') {
                        player2--;
                        pressed++;
                    }
                    break;
                }
                case 'm': {
                    if (player2 < 23 && c == '\n') {
                        player2++;
                        pressed++;
                    }
                    break;
                }
                case ' ': {
                    if (c == '\n')
                        pressed++;
                    break;
                }
                case 'q': {
                    q = 1;
                    pressed++;
                    break;
                }
            }
        }

        //==============//  ACTION
        // движение по Y
        if (ballY < 25 && ballY > 1) {
            ballY += stepY;
        } else {
            stepY *= -1;
            ballY += stepY;
        }

        // движение по X
        if (ballX < 79 && ballX > 2) {
            ballX += stepX;
        } else {
            if ((ballX == 79 && ballY == player2) ||
                (ballX == 79 && ballY == player2 + 1) ||
                (ballX == 79 && ballY == player2 + 2)) {
                stepX *= -1;
                ballX += stepX;
            } else {
                if ((ballX == 2 && ballY == player1) ||
                    (ballX == 2 && ballY == player1 + 1) ||
                    (ballX == 2 && ballY == player1 + 2)) {
                    stepX *= -1;
                    ballX += stepX;
                } else {
                    if ((ballX == 79 && ballY != player2) ||
                        (ballX == 79 && ballY != player2 + 1) ||
                        (ballX == 79 && ballY != player2 + 2)) {
                        scorePlayer1++;
                        restart++;
                    } else {
                        scorePlayer2++;
                        restart++;
                    }
                }
            }
        }

        //==============// RESTART
        if (restart) {
            player1 = 10;  // координаты первой ракетки
            player2 = 10;  //            второй ракетки
            ballX = 39;    // координаты по Х мяча
            ballY = 11;    //            по У мяча
            stepX *= -1;   // реверс в другую сторону
            stepY *= -1;   // реверс в другую сторону
            restart = 0;
        }

        //==============// OUT
        if (scorePlayer1 == WIN) {
            q = 1;
            printf("\nCONGRATULATION Player_1 !!!");
        }
        if (scorePlayer2 == WIN) {
            q = 1;
            printf("\nCONGRATULATION Player_2 !!!");
        }
    }
}

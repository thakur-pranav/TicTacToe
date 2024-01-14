#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char brd[3][3];
const char PLR = 'X';
const char CMP = 'O';

void rsetBrd();
void prntBrd();
int chkFreeSpcs();
void plyrMv();
void cmptrMv();
char chkWnr();
void prntWnr(char);

int main() {    
    char wn = ' ';
    char rspns;

    do {
        wn = ' ';
        rspns = ' ';
        rsetBrd();
        while (wn == ' ' && chkFreeSpcs() != 0) {
            prntBrd();
            plyrMv();
            wn = chkWnr();
            if (wn != ' ' || chkFreeSpcs() == 0) {
                break;
            }
            cmptrMv();
            wn = chkWnr();
            if (wn != ' ' || chkFreeSpcs() == 0) {
                break;
            }
        }
        prntBrd();
        prntWnr(wn);
        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &rspns);
        rspns = toupper(rspns);
    } while (rspns == 'Y');

    printf("Thanks for playing!");

    return 0;
}

void rsetBrd() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            brd[i][j] = ' ';
        }
    }
}

void prntBrd() {
    printf(" %c | %c | %c ", brd[0][0], brd[0][1], brd[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", brd[1][0], brd[1][1], brd[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", brd[2][0], brd[2][1], brd[2][2]);
    printf("\n");
}

int chkFreeSpcs() {
    int freeSpcs = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (brd[i][j] != ' ') {
                freeSpcs--;
            }
        }
    }
    return freeSpcs;
}

void plyrMv() {
    int x, y;

    do {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if (brd[x][y] != ' ') {
            printf("Invalid move! \n");
        } else {
            brd[x][y] = PLR;
            break;
        }

    } while (brd[x][y] != ' ');
}

void cmptrMv() {
    srand(time(0));
    int x, y;

    if (chkFreeSpcs() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (brd[x][y] != ' ');

        brd[x][y] = CMP;
    } else {
        prntWnr(' ');
    }
}

char chkWnr() {
    for (int i = 0; i < 3; i++) {
        if (brd[i][0] == brd[i][1] && brd[i][0] == brd[i][2]) {
            return brd[i][0];
        }
    }
    for (int i = 0; i < 3; i++) {
        if (brd[0][i] == brd[1][i] && brd[0][i] == brd[2][i]) {
            return brd[0][i];
        }
    }
    if (brd[0][0] == brd[1][1] && brd[0][0] == brd[2][2]) {
        return brd[0][0];
    }
    if (brd[0][2] == brd[1][1] && brd[0][2] == brd[2][0]) {
        return brd[0][2];
    }
    return ' ';
}

void prntWnr(char wn) {
    if (wn == PLR) {
        printf("YOU WIN!");
    } else if (wn == CMP) {
        printf("YOU LOSE!");
    } else {
        printf("IT'S A TIE!");    
    }
}

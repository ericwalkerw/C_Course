#include <stdio.h>
#include <stdlib.h>
// Kh?i t?o m?ng 10 ph?n t? t? 0 d?n 9
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

// Prototype
int checkForWin();
void drawBoard();
void resetBoard();
int markBoard(int choice,char mark);

int main() {
    int player = 1, i, choice;
    char mark;

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;

        printf("Nguoi choi %d, nhap vi tri (1-9): ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (!markBoard(choice, mark)) {
            printf("Vi tri khong hop le! Vui long thu lai.\n");
            player--; // Gi? nguyên lu?t
        }

        i = checkForWin();
        player++;

    } while (i == -1);

    drawBoard();
    if (i == 1)
        printf("=> Nguoi choi %d thang!\n", --player);
    else
        printf("=> Hoa nhau!\n");

    return 0;
}

// Ve bang choi
void drawBoard() {
	system("cls");
    printf("\n\n");
    printf(" %c | %c | %c\n", square[1], square[2], square[3]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", square[4], square[5], square[6]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n\n", square[7], square[8], square[9]);
}

// Kiem tra thang/thua/hoa
int checkForWin() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;


    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;

    else
        return -1;
}
// DANH DAU X or O vao board
int markBoard(int choice, char mark) {
    if (choice >= 1 && choice <= 9 && square[choice] == ('0' + choice)) {
        square[choice] = mark;
        return 1;
    }
    return 0;
}


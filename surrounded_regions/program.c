#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define m 4
// #define n 4

void savePath(char **board, int height, int length, int row, int col) {
    board[row][col] = 'S';
    printf("row %d col %d saved\n", row, col);
    // go up
    if((row - 1) >= 0 && board[row - 1][col] == 'O') {
        savePath(board, height, length, row - 1, col);
    }
    // go down
    if((row + 1) < height && board[row + 1][col] == 'O') {
        savePath(board, height, length, row + 1, col);
    }
    // go left
    if((col - 1) >= 0 && board[row][col - 1] == 'O') {
        savePath(board, height, length, row, col - 1);
    }
    // go right
    if((col + 1) < length && board[row][col + 1] == 'O') {
        savePath(board, height, length, row, col + 1);
    }
}

void printMatrix(char **board, int height, int length) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < length; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void solve(char **board, int boardSize, int *boardColSize) {
    int i, j;
    printMatrix(board, boardSize, *boardColSize);
    // traverse first row
    for(j = 0; j < *boardColSize; j++) {
        // printf("row: %d col: %d ", 0, j);
        if(board[0][j] == 'O') {
            savePath(board, boardSize, *boardColSize, 0, j);
        }
    }
    // puts("");
    // printMatrix(board, boardSize, *boardColSize);
    // traverse last column
    for(i = 0; i < boardSize; i++) {
        // printf("row: %d col: %d ", i, *boardColSize - 1);
        if(board[i][*boardColSize - 1] == 'O') {
            savePath(board, boardSize, *boardColSize, i, *boardColSize - 1);
        }
    }
    // puts("");
    // printMatrix(board, boardSize, *boardColSize);
    // traverse last row
    for(j = *boardColSize - 1; j >= 0; j--) {
        // printf("row: %d col: %d ", boardSize - 1, j);
        if(board[boardSize - 1][j] == 'O') {
            savePath(board, boardSize, *boardColSize, boardSize - 1, j);
        }
    }
    // puts("");
    // printMatrix(board, boardSize, *boardColSize);
    // traverse first column
    for(i = boardSize - 1; i >= 0; i--) {
        // printf("row: %d col: %d ", i, 0);
        if(board[i][0] == 'O') {
            savePath(board, boardSize, *boardColSize, i, 0);
        }
    }
    // puts("");
    printMatrix(board, boardSize, *boardColSize);
}

int main() {
    // int m = 4;
    // int n = 4;
    // char board[m][n];
    // strcpy(board[0], "XXXX");
    // printf("%c\n", board[0][0]);
    // printf("%s\n", board[0]);
    // strcpy(board[1], "")
    // char board[4][4] = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    // char *board[4] = {"XXXX", "XOOX", "XXOX", "XOXX"};
    // int m = sizeof(board) / sizeof(char*);
    // int n = strlen(board[0]);
    // char board[4][4] = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    // int m = sizeof(board) / sizeof(char[4]);
    // int n = sizeof(board[0]) / sizeof(char);
    char *board[4];
    board[0] = strdup("XXXX");
    board[1] = strdup("XOOX");
    board[2] = strdup("XXOX");
    board[3] = strdup("XOXX");
    int m = sizeof(board) / sizeof(char *);
    int n = strlen(board[0]);
    printf("%d %d\n", m, n);
    solve(board, m, &n);


}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLS 9

void solveSudoku(char **board, int boardSize, int *boardColSize) {
    int i, j;
    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < boardSize; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    char board_stack[ROWS][COLS] = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, \
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, \
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, \
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, \
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, \
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, \
                              {'.', '6', '.', '.', '7', '.', '2', '8', '.'}, \
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, \
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    char **board = (char **)malloc(ROWS * sizeof(char*));
    int i;
    for(int i = 0; i < ROWS; i++) {
        *(board + i) = (char*)malloc(COLS * sizeof(char));
    }
    for(i = 0; i < ROWS; i++) {
        memcpy(*(board + i), *(board_stack + i), COLS);
    }
    
    // board
    
    size_t boardSize = sizeof(board) / sizeof(char*);
    printf("%zu\n", boardSize);
    int *boardColSize = (int*)malloc(COLS * sizeof(int));
    solveSudoku(board, boardSize, boardColSize);
    for(i = 0; i < ROWS; i++) {
        free(*(board + i));
        *(board + i) = NULL;
    }
    free(board);
    board = NULL;
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 9
#define COLS 9

int findNum(char **board, int row, int col) {
    int numSolutions = 0;
    int digits = 9;
    int solution;
    // memset(solution, -1, digits);
    bool fitsRow, fitsCol, fitsBox;
    fitsRow = fitsCol = fitsBox = true;
    int num, i, j;
    int boxLen = (int)sqrt(sqrt(ROWS * COLS));
    // int testSolutions[9] = {0};  
    for(num = 1; num <= digits; num++) {
        for(i = 0; i < COLS; i++) {
            if(*(*(board + row) + i) == (num + '0')){
                fitsRow = false;
                break;
            }
        }
        if(fitsRow) {
            for(i = 0; i < ROWS; i++) {
                if(*(*(board + i) + col) == (num + '0')) {
                    fitsCol = false;
                    break;
                }
            }        
        }
        if(fitsRow && fitsCol) {
            for(i = (row / 3) * boxLen; i < ((row / 3) + 1) * boxLen; i++) {
                for(j = (col / 3) * boxLen; j < ((col / 3) + 1) * boxLen; j++) {
                    // printf("%c ", *(*(board + i) + j));
                    if(*(*(board + i) + j) == (num + '0')) {
                        fitsBox = false;
                        break;
                    }
                }
                if(!fitsBox) {
                    break;
                }
            }
        }
        if(fitsRow && fitsCol && fitsBox) {
            // testSolutions[numSolutions] = num; 
            numSolutions++;
            solution = num;
        }
        fitsRow = fitsCol = fitsBox = true;
    }
    // printf("All solutions:\n");
    // for(i = 0; i < 9; i++) {
    //     printf("%d ", testSolutions[i]);
    // }
    // printf("\n");
    if(numSolutions == 1) {
        printf("Solution at (%d, %d) is: %d\n", row, col, solution);
        return solution;
    } else {
        return -1;
    }
}

void solveSudoku(char **board, int boardSize, int *boardColSize) {
    int i, j;
    int solved = 0;
    int rows, cols;
    rows = cols = sqrt((double) boardSize);
    int solvedPerRow[rows] = {};
    memset(solvedPerRow, 0, rows);
    int solvedPerCol[cols] = {};
    memset(solvedPerCol, 0, cols);

    int rowsColsPerBox = (int)sqrt(sqrt(boardSize));
    int solvedPerBox[rowsColsPerBox][rowsColsPerBox] = {};
    for(i = 0; i < rowsColsPerBox; i++) {
        memset(solvedPerBox[i], 0, rowsColsPerBox);
    }
    // printf("%d\n", numBoxes);
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            // printf("%c ", board[i][j]);
            if(board[i][j] != '.') {
                solved++;
                solvedPerRow[i]++;
                solvedPerCol[j]++;
                (solvedPerBox[i / 3][j / 3])++;
            } 
        }
        // printf("\n");
    }
    // printf("%d\n", solved);
    // for(i = 0; i < rows; i++) {
    //     printf("%d ", solvedPerRow[i]);
    // }
    // printf("\n");
    // for(i = 0; i < cols; i++) {
    //     printf("%d ", solvedPerCol[i]);
    // }
    // printf("\n");
    // for(i = 0; i < 3; i++) {
    //     for(j = 0; j < 3; j++) {
    //         printf("%d ", solvedPerBox[i][j]);
    //     }
    //     printf("\n");
    // }
    int numsInBox = (int)sqrt(boardSize);
    int temp = -1;
    while(solved < boardSize) {
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                // if(solveInRow() || solveInColumn() || solveInBox()) {
                //     solved++;
                // }
                if((board[i][j] == '.') && (solvedPerRow[i] < cols) && (solvedPerCol[j] < rows) \
                    && (solvedPerBox[i / 3][j / 3] < numsInBox)) {
                        temp = findNum(board, i, j);
                        if(temp > 0) {
                            board[i][j] = temp + '0';
                            (solvedPerRow[i])++;
                            (solvedPerCol[j])++;
                            (solvedPerBox[i / 3][j / 3])++;
                            solved++;
                            temp = -1;
                        }
                }
            }
        }
    }
    if(solved == boardSize) {
        return;
    }
}

int main(void) {
    char board_stack[ROWS][COLS] = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, \
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, \
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, \
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, \
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, \
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, \
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, \
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, \
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    // printf("Size of board_stack: %zu\n", sizeof(board_stack));

    char **board = (char **)malloc(ROWS * sizeof(char*));
    int i;
    for(int i = 0; i < ROWS; i++) {
        *(board + i) = (char*)malloc(COLS * sizeof(char));
    }
    for(i = 0; i < ROWS; i++) {
        memcpy(*(board + i), *(board_stack + i), COLS);
    }
    
    // board
    
    size_t boardSize = ROWS * COLS;
    // printf("%zu\n", boardSize);
    int *boardColSize = (int*)malloc(COLS * sizeof(int));
    // int boardColSize = COLS;
    // int *boardColSizePtr = &boardColSize;

    solveSudoku(board, boardSize, boardColSize);
    // findNum(board, 0, 2);

    int j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < ROWS; i++) {
        free(*(board + i));
        *(board + i) = NULL;
    }
    free(board);
    board = NULL;
    return 0;
}
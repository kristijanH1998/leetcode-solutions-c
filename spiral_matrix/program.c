#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct position {
    int x;
    int y;
} pos = {0, 0};

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize) {
    if(matrixSize <= 0 || (*matrixColSize) <= 0) {
        return NULL;
    }
    int rows = matrixSize;
    int cols = *matrixColSize;
    int matLen = rows * cols;
    // printf("%d\n", matLen);
    int *spiral = (int*)malloc(matLen * sizeof(int));
    if(rows == 1) {
        memcpy(spiral, matrix[0], matLen);
    }
    if(cols == 1) {
        for(int i = 0; i < rows; i++) {
            spiral[i] = matrix[i][0];
        }
    }
    int limitRL = 0;
    int limitUD = 0;
    int copied = 0;
    while(copied < matLen) {
        while(pos.y < (cols - limitRL)) {
            *(spiral + (copied++)) = *(*(matrix + pos.x) + pos.y);
            (pos.y)++;
        }
        (pos.y)--;
        (pos.x)++;
        while(pos.x < (rows - limitUD) && (copied < matLen)) {
            *(spiral + (copied++)) = *(*(matrix + pos.x) + pos.y);
            (pos.x)++;
        }
        (pos.x)--;
        (pos.y)--;
        limitUD++;
        while(pos.y >= limitRL && (copied < matLen)) {
            *(spiral + (copied++)) = *(*(matrix + pos.x) + pos.y);
            (pos.y)--;
        }
        (pos.y)++;
        (pos.x)--;
        limitRL++;
        while(pos.x >= limitUD && (copied < matLen)) {
            *(spiral + (copied++)) = *(*(matrix + pos.x) + pos.y);
            (pos.x)--;
        }
        (pos.x)++;
        (pos.y)++;
    }
    *returnSize = copied; // (rows == cols) ? copied : (copied - 1);
    // printf("%d %d\n", *returnSize, copied);
    return spiral;
}

int main(void) {
    int rows = 10;
    int cols = 2;
    int **matrix = (int**)malloc(rows * sizeof(int *));
    int i;
    for(i = 0; i < rows; i++) {
        *(matrix + i) = (int*)malloc(cols * sizeof(int));
    }
    int j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            *(*(matrix + i) + j) = i * cols + (j + 1);
        }
    }
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    int returnSize = 0;
    int *spiral = spiralOrder(matrix, rows, &cols, &returnSize);
    // printf("%d\n", returnSize);
    for(i = 0; i < returnSize; i++) {
        printf("%d ", *(spiral + i));
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

static int cmpNums(const void *num1, const void *num2) {
    return *(int*)num1 - *(int*)num2;
}

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
    int rows = matrixSize;
    int cols = *matrixColSize;
    int i, j;
    // for(i = 0; i < rows; i++) {
    //     for(j = 0; j < cols; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    //first perform binary search by looking at first number in each row, to find largest number less than target. Only in that row target can be found. 
    // int mid = (rows % 2 == 0) ? (rows / 2) : ((rows / 2) + 1);
    // while(!(matrix[mid][0] <= target)) {
    //     mid = mid / 2;
    // }
    // while((matrix[mid + 1][0] <= target) && (mid < (rows - 1))) {
    //     // do {
    //     mid = (mid / 2) + mid;
    //     // } while((matrix[mid][0] < target) && (mid < (rows - 1)) && (matrix[mid + 1][0] > target));
    // }
    
    // code below finds the row in which target may be found, utilizing binary search to achieve log(n) CPU time
    int low = 0;
    int high = matrixSize - 1;
    int mid = 0;
    while((low <= high) && (mid < matrixSize - 1)) {
        mid = low + (high - low) / 2; 
        if((matrix[mid][0] <= target) && ((mid == (matrixSize - 1)) || (matrix[mid + 1][0] > target))) {
            break;
        }
        if(matrix[mid][0] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    int matchRow = mid;
    // printf("%d\n", mid);
    // now time to search the correct row, again with binary search
    low = 0;
    high = cols;
    mid = -1;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(matrix[matchRow][mid] == target) {
            printf("target found at row %d column %d\n", matchRow, mid);
            return true;
        }
        if(matrix[matchRow][mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("target not found\n");
    return false;
}

int main(void) {
    int matrixCpy[5][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60},{100,110,120,130},{200,300,400,500}};
    int rows = 5;
    int cols = 4;
    int **matrix = (int**)malloc(rows * sizeof(int*));
    int i;
    for(i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        memcpy(matrix[i], matrixCpy[i], sizeof(int) * cols);
    }
    int j;
    int matrixSize = ARRAY_SIZE(matrixCpy);
    int matrixColSize = ARRAY_SIZE(matrixCpy[0]);
    // printf("%d %d %d %d\n", matrixSize, matrixColSize, ARRAY_SIZE(matrixCpy), ARRAY_SIZE(matrixCpy[0]));
    printf("%s\n", searchMatrix(matrix, matrixSize, &matrixColSize, 40) ? "true" : "false");
    return 0;
}
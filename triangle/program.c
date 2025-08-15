#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// my first solution
// void findSum(int **triangle, int triangleSize, int row, int numIndex, int pathSum, int *minSum) {
//     // printf("%d ", triangle[row][numIndex]);
//     pathSum += triangle[row][numIndex];
//     // if(pathSum > *minSum) {
//     //     return;
//     // } 
//     if((row == (triangleSize - 1))) {
//         if(pathSum < *minSum) {
//             *minSum = pathSum;
//         }
//         // printf("\n");
//         return;
//     }
//     // if() {
//     //     if(pathSum < *minSum) {       
//     //     }
//     //     return;
//     // }
//     findSum(triangle, triangleSize, row + 1, numIndex, pathSum, minSum);
//     findSum(triangle, triangleSize, row + 1, numIndex + 1, pathSum, minSum);
//     // return pathSum + ;
// }

// int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
//     // int i;
//     // for(i = 0; i < triangleSize; i++) {
//     //     printf("%d ", triangleColSize[i]);
//     // }
//     // printf("\n");
//     // int j;
//     // for(i = 0; i < triangleSize; i++) {
//     //     for(j = 0; j < triangleColSize[i]; j++) {
//     //         printf("%d ", triangle[i][j]);
//     //     }
//     //     printf("\n");
//     // }
//     int minSum = INT_MAX;
//     findSum(triangle, triangleSize, 0, 0, 0, &minSum);
//     return minSum;
// }

//second solution:
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
    int dp[triangleSize + 1][triangleSize + 1];
    int i;
    for(i = 0; i < triangleSize + 1; i++) {
        dp[triangleSize][i] = 0;
    }
    for(int level = triangleSize - 1; level >= 0; level--) {
        for(i = 0; i <= triangleSize; i++) {
            dp[level][i] = triangle[level][i] + MIN(dp[level + 1][i], dp[level + 1][i + 1]);
        }
    }
    return dp[0][0];
}

int main() {
    // int rows = 4;
    
    int rows = 1;
    
    // int rows = 3;

    int **triangle = (int**)malloc(rows * sizeof(int*));
    int numbers = 1;
    int triangleColSize[rows];
    for(numbers = 1; numbers <= rows; numbers++) {
        *(triangle + (numbers - 1)) = (int*)malloc(numbers * sizeof(int));
        triangleColSize[numbers - 1] = numbers;
    }
    // *(*(triangle + 0) + 0) = 2;
    // *(*(triangle + 1) + 0) = 3;
    // *(*(triangle + 1) + 1) = 4;
    // *(*(triangle + 2) + 0) = 6;
    // *(*(triangle + 2) + 1) = 5;
    // *(*(triangle + 2) + 2) = 7;
    // *(*(triangle + 3) + 0) = 4;
    // *(*(triangle + 3) + 1) = 1;
    // *(*(triangle + 3) + 2) = 8;
    // *(*(triangle + 3) + 3) = 3;
    
    *(*(triangle + 0) + 0) = -10;
    
    // *(*(triangle + 0) + 0) = -1;
    // *(*(triangle + 1) + 0) = 2;
    // *(*(triangle + 1) + 1) = 3;
    // *(*(triangle + 2) + 0) = 1;
    // *(*(triangle + 2) + 1) = -1;
    // *(*(triangle + 2) + 2) = -3;

    printf("%d\n", minimumTotal(triangle, rows, triangleColSize));
    return 0;
}
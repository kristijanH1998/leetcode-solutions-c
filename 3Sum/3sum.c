#include <stdio.h>
#include <stdlib.h>

// struct Triplet {
//     int first;
//     int second;
//     int third;
// };

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // for(int i = 0; i < numsSize; i++) {
    //     printf("%d\n", *(nums + i));
    // }

    for(int j = 0; j < (numsSize - 2); j++) {
        for(int k = j + 1; k < (numsSize - 1); k++) {
            for(int l = k + 1; l < (numsSize); l++) {
                // printf("%d %d %d\n", *(nums + j), *(nums + k), *(nums + l));
                if((*(nums + j) + *(nums + k) + *(nums + l)) == 0) {

                    // struct Triplet triplet
                    printf("%d %d %d\n", *(nums + j), *(nums + k), *(nums + l));



                    //https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
                }
            }
        }
    }


    return returnColumnSizes;
}

// int test(int* nums, int numsSize) {
//     printf("%d\n", numsSize);
//     printf("%lu\n", sizeof(*nums));
//     return 0;
// }

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    // int **result = threeSum(nums, sizeof(nums) / sizeof(int), );
    // printf("%ip\n", result);
    // printf("%d\n", sizeof(nums));
    int numsSize = sizeof(nums) / sizeof(int);
    int return_size = 0;
    int *column_sizes = (int*) malloc (1 * sizeof(int));
    // printf("%d\n", **(threeSum(nums, numsSize, &return_size, &column_sizes)));
    // printf("The size of the array of triplet arrays is: %d\n triplets", return_size);
    
    








    //2D Matrix Implementation:
    int rows = 5;
    int cols = 3;
    //Memory allocation:
    int **triplets = (int **) malloc (rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        //2 ways to allocate integer locations for each row array
        // *(triplets + i) = (int *) malloc (cols * sizeof(int));
        triplets[i] = (int *) malloc (cols * sizeof(int));
    }
    //Filling the matrix with values (zeroes):
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            triplets[i][j] = 0;
            *(*(triplets + i) + j) = 0;
        }
    }

    //Pring contents of the matrix:
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", triplets[i][j]);
        }
        printf("\n");
    }

    // triplets = (int**) realloc (triplets, 2 * sizeof(int*));
    // printf("%d\n", **triplets);
    
    
    //Freeing memory
    for(int i = 0; i < rows; i++) {
        free(triplets[i]);
    }
    free(triplets);

    
    
    return 0;
}
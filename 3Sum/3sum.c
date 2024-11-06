#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// struct Triplet {
//     int first;
//     int second;
//     int third;
// };

//Tests whether first passed triplet is a subset of second passed triplet
bool tripletSubsetOf(int* triplet1, int* triplet2) {
    int eq_nums_found = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(*(triplet1 + i) == *(triplet2 + j)) {
                eq_nums_found++;
                break;
            }
        } 
    }
    if(eq_nums_found == 3) {
        return true;
    }
    return false;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // for(int i = 0; i < numsSize; i++) {
    //     printf("%d\n", *(nums + i));
    // }
    int triplets_row_index = 0;  //increasing variable that determines how many rows (integer arrays) will be allocated for triplets (in other words, how many triplets will be in the result)
    const int triplets_cols = 3; //constant that determines how many columns should be in each triplet row (3)
    int **triplets = (int **) malloc ((triplets_row_index + 1) * sizeof(int *));
    *triplets = (int *) malloc (triplets_cols * sizeof(int));

    for(int j = 0; j < (numsSize - 2); j++) {
        for(int k = j + 1; k < (numsSize - 1); k++) {
            for(int l = k + 1; l < (numsSize); l++) {
                // printf("%d %d %d\n", *(nums + j), *(nums + k), *(nums + l));
                if((*(nums + j) + *(nums + k) + *(nums + l)) == 0) {
                    int test_triplet[] = {*(nums + j),*(nums + k),*(nums + l)};
                    bool equal_triplet_found = false;
                    for(int i = 0; i < triplets_row_index; i++) {
                        if(tripletSubsetOf(test_triplet, *(triplets + i)) && 
                            tripletSubsetOf(*(triplets + i), test_triplet)) {
                                equal_triplet_found = true;
                        }
                    }
                    //Triplet with identical values not found in matrix to be returned
                    if(!equal_triplet_found) {
                        *(*(triplets + triplets_row_index) + 0) = *(nums + j);
                        *(*(triplets + triplets_row_index) + 1) = *(nums + k);
                        *(*(triplets + triplets_row_index) + 2) = *(nums + l);
                        triplets_row_index++;
                        triplets = (int**) realloc (triplets, (triplets_row_index + 1) * sizeof(int*));
                        *(triplets + triplets_row_index) = (int *) malloc (triplets_cols * sizeof(int));
                    }
                    // printf("%d %d %d\n", *(nums + j), *(nums + k), *(nums + l));
                }
            }
        }
    }
    *returnSize = triplets_row_index;
    return triplets;
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
    
    int **result = threeSum(nums, numsSize, &return_size, &column_sizes);
    printf("The size of the array of triplet arrays is: %d\n triplets\n", return_size);
    printf("The resulting array of triplets is: \n");
    for(int i = 0; i < return_size; i++) {
        printf("[");
        for(int j = 0; j < 3; j++) {
            if(j < 2) {
                printf("%d, ", result[i][j]);
            } else {
                if(i == (return_size - 1)) {
                    printf("%d]\n", result[i][j]);
                } else {
                    printf("%d],\n", result[i][j]);
                }    
            }   
        }
    }

    // test code for tripletSubsetOf
    // int triplet1[] = {0,4,1};
    // int triplet2[] = {1,4,0};
    // printf("%d\n", (tripletSubsetOf(triplet1, triplet2) && tripletSubsetOf(triplet2, triplet1)));

    //2D Matrix Implementation:
    // int rows = 5;
    // int cols = 3;
    // //Memory allocation:
    // int **triplets = (int **) malloc (rows * sizeof(int *));
    // for(int i = 0; i < rows; i++) {
    //     //2 ways to allocate integer locations for each row array
    //     // *(triplets + i) = (int *) malloc (cols * sizeof(int));
    //     triplets[i] = (int *) malloc (cols * sizeof(int));
    // }
    // //Filling the matrix with values (zeroes):
    // for(int i = 0; i < rows; i++) {
    //     for(int j = 0; j < cols; j++) {
    //         triplets[i][j] = 0;
    //         *(*(triplets + i) + j) = 0;
    //     }
    // }
    
    // //Pring contents of the matrix:
    // printf("[");
    // for(int i = 0; i < rows; i++) {
    //     for(int j = 0; j < cols; j++) {
    //         if(j == 0) {
    //             printf("[%d,", triplets[i][j]);
    //         } else  if (j == 2) {
    //             printf("%d]", triplets[i][j]);
    //         } else {
    //             printf("%d,", triplets[i][j]);
    //         }
    //     }
    //     if(i != (rows - 1)) {
    //         printf(",\n");
    //     } else {
    //         printf("]\n");
    //     }
    // }
    
    // // triplets = (int**) realloc (triplets, 2 * sizeof(int*));
    // // printf("%d\n", **triplets);
    
    // //Freeing memory
    // for(int i = 0; i < rows; i++) {
    //     free(triplets[i]);
    // }
    // free(triplets);

    return 0;
}

//Resources:
//https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
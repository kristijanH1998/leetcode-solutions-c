#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int i, j, k, l;
    if(nums == NULL || numsSize < 1) {
        return NULL;
    }
    int retSz = *returnSize;
    for(i = 0; i <= (numsSize - 4); i++) {
        for(j = i + 1; j <= (numsSize - 3); j++) {
            for(k = j + 1; k <= (numsSize - 2); k++) {
                for(l = k + 1; l <= (numsSize - 1); l++) {
                    if((nums[i] + nums[j] + nums[k] + nums[l]) == target) {
                        *(*(returnColumnSizes + retSz) + 0) = nums[i];
                        *(*(returnColumnSizes + retSz) + 1) = nums[j];
                        *(*(returnColumnSizes + retSz) + 2) = nums[k];
                        *(*(returnColumnSizes + retSz) + 3) = nums[l];
                        // returnColumnSizes[retSz][0] = nums[i];
                        // returnColumnSizes[retSz][1] = nums[j];
                        // returnColumnSizes[retSz][2] = nums[k];
                        // returnColumnSizes[retSz][3] = nums[l];
                        retSz++;
                        returnColumnSizes = (int**)realloc(returnColumnSizes, (retSz + 1) * sizeof(int *));
                        *(returnColumnSizes + retSz) = (int *)malloc(4 * sizeof(int));
                    }
                }
            }
        }
    }
    *returnSize = retSz;
    return returnColumnSizes;
}

int main(void) {
    int *nums = (int *)malloc(10 * sizeof(nums));
    int i;
    for(i = 0; i < 10; i++) {
        *(nums + i) = i + 1;
    }
    int **quadruplets = (int **)malloc(1 * sizeof(int *));
    *quadruplets = (int *)malloc(4 * sizeof(int));
    int returnSize = 0;
    int *returnSizePtr = &returnSize;
    quadruplets = fourSum(nums, 10, 13, returnSizePtr, quadruplets);
    for(i = 0; i < returnSize; i++) {
        printf("%d %d %d %d\n", quadruplets[i][0], quadruplets[i][1], quadruplets[i][2], quadruplets[i][3]);
        free(*(quadruplets + i));
        *(quadruplets + i) = NULL;
    }
    free(quadruplets);
    quadruplets = NULL;
    return 0;
}
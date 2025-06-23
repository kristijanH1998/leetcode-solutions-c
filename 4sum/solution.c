#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int i, j, k, l;
    for(i = 0; i <= (numsSize - 4); i++) {
        for(j = i + 1; j <= (numsSize - 3); j++) {
            for(k = j + 1; k <= (numsSize - 2); k++) {
                for(l = k + 1; l <= (numsSize - 1); l++) {
                    // printf("%d %d %d %d\n", nums[i], nums[j], nums[k], nums[l]);
                    if((nums[i] + nums[j] + nums[k] + nums[l]) == target) {
                        printf("%d %d %d %d\n", nums[i], nums[j], nums[k], nums[l]);
                    }
                }
            }
        }
    }
    return NULL;
}

int main(void) {
    int *nums = (int *)malloc(10 * sizeof(nums));
    for(int i = 0; i < 10; i++) {
        *(nums + i) = i + 1;
    }
    fourSum(nums, 10, 20, NULL, NULL);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// goal: find two smallest integers such that their difference is greater than 1
// then the answer will be the smaller of the two plus 1 --> this would work if array was sorted

int firstMissingPositive(int *nums, int numsSize) {
    // unsigned int i, min_first, min_sec;
    // min_first = min_sec = INT_MAX;
    // for(i = 0; i < numsSize; i++) {
    //     if(nums[i] > 0) {
    //         // if(nums[i] < min_first) {
    //         //     min_sec = min_first;
    //         //     min_first = nums[i];
    //         // } else if(nums[i] < min_sec) {
    //         //     min_sec = nums[i];
    //         // }
    //         if(nums[])
    //     }
    // }
    // if(min_first > 1) {
    //     return 1;
    // }
    // printf("%d %d\n", min_first, min_sec);
    // int counter = 1;
    // while(true) {
    //     if(min > counter) {
    //         return counter;
    //     } else {
    //         counter
    //     }
    // }
    // at this stage we know that smallest number is 1
    // min = INT_MAX;
    // for(i = 0; i < numsSize; i++) {
    //     if((nums[i] < min) && (nums[i] > 2)) {
    //         min = nums[i];
    //     }
    // }
    // if(min == INT_MAX) {
    //     return 2;
    // } else {
    // }
    if(numsSize == 1) {
        if(nums[0] > 1 || nums[0] <= 0) {
            return 1;
        } else {
            return 2;
        }
    }
    int i, hasOne = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            hasOne = 1;
        }
        if (nums[i] <= 0 || nums[i] > numsSize) {
            nums[i] = 1;
        }
    }
    if (!hasOne) return 1;
    for(i = 0; i < numsSize; i++) {
        if(nums[abs(nums[i]) - 1] > 0) {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
    for(i = 0; i < numsSize; i++) {
        if(nums[i] > 0) {
            return i + 1;
        }
    }
    if(i == numsSize) {
        return i + 1;
    }
    return 1;
}

int main(void) {
    // int *nums = (int*)malloc(3 * sizeof(int));
    // *(nums + 0) = 1;
    // *(nums + 1) = 2;
    // *(nums + 2) = 0;
    int nums[] = {2, 1};
    printf("%d\n", firstMissingPositive(nums, sizeof(nums) / sizeof(int)));
    return 0;
}
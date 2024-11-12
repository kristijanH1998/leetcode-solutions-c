#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int threeSumClosest(int* nums, int numsSize, int target) {
    int diff = 0;
    int minDiff = INT_MAX;
    int sum = 0;
    for(int j = 0; j < (numsSize - 2); j++) {
        for(int k = j + 1; k < (numsSize - 1); k++) {
            for(int l = k + 1; l < (numsSize); l++) {
                // if((*(nums + j) + *(nums + k) + *(nums + l)) == 0) {
                diff = abs(target - (*(nums + j) + *(nums + k) + *(nums + l)));
                // printf("%d %d %d\n", *(nums + j), *(nums + k),*(nums + l));
                // printf("%d\n", diff);
                if(diff < minDiff) {
                    minDiff = diff;
                    sum = *(nums + j) + *(nums + k) + *(nums + l);
                }
                // }
            }
        }
    }
    return sum; 
}




int main() {
    int nums[] = {0,0,0};
    // printf("%d\n", sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", threeSumClosest(nums, sizeof(nums) / sizeof(nums[0]), 1));
    return 0;
}
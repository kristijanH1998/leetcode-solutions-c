#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize) {
    if(nums == NULL || numsSize <= 0) {
        return -1;
    }
    int i, j;
    for(i = 0; i < numsSize; i++) {
        for(j = 0; j < numsSize; j++) {
            if(nums[i] == nums[j] && i != j) {
                break;
            }
        }
        if(j >= numsSize) {
            return nums[i];
        }
    }
    return -1;
}

int main() {
    // int nums[] = {0,1,0,1,0,1,99};
    int nums[] = {2,2,3,2};
    int numsSize = sizeof(nums) / sizeof(int);
    printf("%d\n", singleNumber(nums, numsSize));

}
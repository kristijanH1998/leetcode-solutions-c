#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

static int best = INT_MAX;

int find_jumps(int *nums, int numsSize, int jumps) {
    if(jumps > best) {
        return best;
    }
    if(nums == NULL) {
        return -1;
    }
    if(numsSize == 1) {
        return jumps;
    }
    int minJumps = INT_MAX;
    int temp;
    for(int i = 1; i <= nums[0]; i++) {
        if(i < numsSize) {
            temp = find_jumps(nums + i, numsSize - i, jumps + 1);
            if(temp < minJumps) {
                best = minJumps = temp;
            }
        } else {
            continue;
        }
    }
    return minJumps;
}

int jump(int *nums, int numsSize) {
    if(nums == NULL || numsSize < 1 || numsSize > pow(10, 4)) {
        return -1;
    }
    if(numsSize == 1) {
        return 0;
    }
    int jumps = 0;
    int i;
    int temp;
    int minJumps = INT_MAX;
    for(i = 1; i <= nums[0]; i++) {
        if(i < numsSize) {
            temp = find_jumps(nums + i, numsSize - i, jumps + 1);
            if(temp < minJumps) {
                minJumps = temp;
            }
        } else {
            continue;
        }
    }
    return minJumps;
}

int main(void) {
    int nums[] = {1, 1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(int);
    printf("%d\n", jump(nums, numsSize));
    return 0;
}
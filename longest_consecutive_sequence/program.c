#include <stdio.h>
#include <stdlib.h>

int cmpInts(const void *i1, const void *i2) {
    return (*(int*)i1 - *(int*)i2);
}

//O(log(n)) solution
int longestConsecutive(int *nums, int numsSize) {
    if(nums == NULL || numsSize <= 0) {
        return 0;
    }
    // printf("%d\n", numsSize);
    qsort(nums, numsSize, sizeof(int), cmpInts);
    int i;
    for(i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    puts("");
    int longest = 1;
    int curr_longest = 1;
    for(i = 0; i < numsSize; i++) {
        if(nums[i+1] == nums[i] + 1) {
            curr_longest++;
        } else if(nums[i+1] == nums[i]){
            continue;
        } else {
            if(curr_longest > longest) {
                longest = curr_longest;
            }
            curr_longest = 1;
        }
    }
    return longest;
}

int main(void) {
    int nums[] = {100,4,200,1,3,2};
    int ans = longestConsecutive(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", ans);
    int nums2[] = {0,3,7,2,5,8,4,6,0,1};
    int ans2 = longestConsecutive(nums2, sizeof(nums2) / sizeof(int));
    printf("%d\n", ans2);
    int nums3[] = {1,0,1,2};
    int ans3 = longestConsecutive(nums3, sizeof(nums3) / sizeof(int));
    printf("%d\n", ans3);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*
# Intuition
I started thinking how to solve this problem using binary search, because it has O(log n) runtime speed. But since the array is rotated, it cannot simply be sent to binary search function for answer. Searching index by index is O(n), so to achieve O(log n), we must somehow be able to tell which half of the array to search. Even though we don't know where pivot element is, we know that if array is split in two halves, one half will be in ascending order (sorted), and another will be rotated. The half that's sorted can immediately be searched with binary search (if the element we're looking for is in that range). The other half of the original array we can approach recursively, looking at it as the next rotated array that should be split in half, and one half of it will be sorted and in ascending order, while another will be rotated. This "fractal" nature of one half of the array in each phase suggests a recursive algorithm.

# Approach
If array size is smaller or equal to 0, return -1, since no element can be there. If array size is 1, check if its only element equals target number, if not, return -1, otherwise return 0. 
Next, if first element is smaller than last, that means there was no rotation and array can be binary searched as a whole.
If first element is smaller than element in the middle of array (meaning that portion of array is in ascending order), and if target falls between first and middle element's values, do binary search on that half of array. In this case, other half is rotated, so recursively search it by calling search() with it, changing array size to half of size of original array.
Now, if first element wasn't smaller than middle element, then first half was rotated, and the second half is in ascending order. In this case, check if the target falls in this second half, if it does, binary search it. If target is not in the second half's range, look in the first half (which is in this scenario rotated), so call search() recursively with this first half of original array (from first to middle element).
Eventually one of the calls to search() or one of the bsearch()'es from one of those search() contexts will find the right index, and it will be returned to initial search() and then to main().
*/

static int cmpInts(const void *num1, const void *num2) {
    return (*(int*)num1 - *(int*)num2);
}

int search(int *nums, int numsSize, int target) {
    int *index = NULL;
    if(numsSize <= 0) {
        return -1;
    }
    if(numsSize == 1) {
        if(nums[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }
    // array not rotated
    if(nums[0] < nums[numsSize - 1]) {
        // binsearch whole array
        // int trg = target;
        index = bsearch(&target, nums, numsSize, sizeof(nums[0]), cmpInts);
        return ((index != NULL) ? (int)(index - nums) : -1);
    }
    if(nums[0] < nums[numsSize / 2]) {
        if((nums[0] <= target) && (target <= nums[numsSize / 2])) {
            // binsearch first half
            index = bsearch(&target, nums, (numsSize / 2) + 1, \
                sizeof(nums[0]), cmpInts);
            return ((index != NULL) ? (int)(index - nums) : -1);
        } else {
            // search() recursively in second half
            int result = search(&nums[(numsSize / 2) + 1], (numsSize % 2 == 0) ? ((numsSize / 2) - 1) : \
            (numsSize / 2), target);
            return (result == -1) ? -1 : ((numsSize / 2) + 1 + result); 
        }
    } else if((nums[numsSize / 2] <= target) && (target <= nums[numsSize - 1])){
        // binsearch second half
        index = bsearch(&target, &nums[numsSize / 2], (numsSize % 2 == 0) ? (numsSize / 2) : ((numsSize / 2) + 1), \
            sizeof(nums[0]), cmpInts);
        return ((index != NULL) ? (int)(index - nums) : -1);
    } else {
        // search() recursively in first half
        int result = search(nums, numsSize / 2, target);
        return result; 
    }
    return *index;
}

int main(void) {
    // int nums[] = {4, 5, 6, 7, 0, 1, 2};
    // int nums[] = {2, 4, 6, 8, 10};
    // int nums[] = {7, 8, 9, 10, 2, 3, 4};
    // int nums[10] = {8,9,10,1,2,3,4,5,6,7};
    int nums[] = {4,5,6,7,8,1,2,3};
    size_t numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", search(nums, numsSize, 8));
    return 0;
}
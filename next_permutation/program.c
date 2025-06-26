#include <stdio.h>
#include <stdlib.h>

int cmpIntegers(const void *first, const void *second) {
    if(*(const int *)first > *(const int *)second) {
        return 1;
    } else if(*(const int *)first < *(const int *)second) {
        return -1;
    } else {
        return 0;
    }
}

void swapElements(int **nums_ptr, int i, int j) {
    int temp = *(*nums_ptr + i);
    *(*nums_ptr + i) = *(*nums_ptr + j);
    *(*nums_ptr + j) = temp;
}

void nextPermutation(int **nums, int numsSize) {
    if(numsSize == 0) {
        return;
    }
    if(numsSize == 1) {
        printf("%d\n", **nums);
        return; 
    }
    int i, j, min_larger = 0;
    int swap_index = 0;
    for(i = numsSize - 2; i >= 0; i--) {
        if(*(*nums + i) < *(*nums + i + 1)) {
            min_larger = *(*nums + i + 1);
            swap_index = i + 1;
            for(j = i + 1; j < numsSize; j++){
                if((*(*nums + j) > *(*nums + i)) && (*(*nums + j) < min_larger)) {
                    min_larger = *(*nums + j);
                    swap_index = j;
                }
            }
            swapElements(nums, i, swap_index);
            if((numsSize - 1 - i) > 1) {
                qsort(*nums + i + 1, numsSize - 1 - i, sizeof(int), cmpIntegers);
            }
            break;
        }
    }
    if(i < 0) {
        qsort(*nums, numsSize, sizeof(int), cmpIntegers);
    }
    for(i = 0; i < numsSize; i++) {
        printf("%d ", *(*nums + i));
    }
    printf("\n");
}

int main(void) {
    // int nums[7] = {8, 9, 2, 5, 3, 2, 1};
    int size = 7;
    int *nums = (int *)malloc(size * sizeof(int));
    *(nums + 0) = 8;
    *(nums + 1) = 9;
    *(nums + 2) = 2;
    *(nums + 3) = 5;
    *(nums + 4) = 3;
    *(nums + 5) = 2;
    *(nums + 6) = 1;
    nextPermutation(&nums, size);
    int *nums2 = (int *)malloc(sizeof(int));
    *nums2 = 122;
    nextPermutation(&nums2, 1);
    return 0;
}
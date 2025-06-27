#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n) {
    int fac = 1;
    if(n == 0) {
        return fac;
    }
    while(n > 0) {
        fac = fac * n;
        n = n - 1;
    }
    return fac;
}

void swap(int **nums_ptr, int a, int b) {
    int temp = *(*nums_ptr + a);
    *(*nums_ptr + a) = *(*nums_ptr + b);
    *(*nums_ptr + b) = temp;
}

void printNums(int **nums_ptr, int size, int *permutationCount) {
    printf("#%d: ", *permutationCount + 1);
    (*permutationCount)++;
    for(int i = 0; i < size; i++) {
        printf("%d ", *(*nums_ptr + i));
    }
    printf("\n");
}

int **generatePermutations(int *nums, int numsSize, int startIndex, int *permutationCount, int ***permutations) {
    // base case is when nums holds only one integer
    if(startIndex == (numsSize - 1)) {
        return NULL;
    }
    // for each swapping of element at startIndex with each other element after it, recursively generate more
    // permutations by moving startIndex by 1 to the right
    for(int i = startIndex; i < numsSize; i++) {
        swap(&nums, startIndex, i);
        if(i != startIndex) {
            printNums(&nums, numsSize, permutationCount);
            memcpy(*(*permutations + (*permutationCount - 1)), nums, numsSize * sizeof(int));
        }
        generatePermutations(nums, numsSize, startIndex + 1, permutationCount, permutations);
        swap(&nums, startIndex, i);
    }
    return *permutations;
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    if(numsSize == 0 || nums == NULL || returnSize == NULL || returnColumnSizes == NULL || \
        (*returnColumnSizes) == NULL) {
        return NULL;
    }
    // print first array alignment and start generating permutations
    int permutationCount = 0;
    int permutationsSize = factorial(numsSize);

    //allocating space on heap for array of permutation arrays that will be returned
    int **permutations = (int **)malloc(permutationsSize * sizeof(int *));
    for(int i = 0; i < permutationsSize; i++) {
        *(permutations + i) = (int *)malloc(numsSize * sizeof(int));
    }

    printNums(&nums, numsSize, &permutationCount);
    memcpy(*permutations, nums, numsSize * sizeof(int));

    if(numsSize > 1) {
        permutations = generatePermutations(nums, numsSize, 0, &permutationCount, &permutations);
    }
    *returnSize = permutationCount;
    return permutations;
}

int main(void) {
    int size = 5;
    int *nums = (int *)malloc(size * sizeof(int));
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;
    nums[4] = 5;
    // nums[5] = 6;
    // nums[6] = 7;
    // nums[7] = 8;
    int returnSize = factorial(size);
    int *returnColumnSizes = (int *)malloc(returnSize * sizeof(int));
    int **permutations = permute(nums, size, &returnSize, &returnColumnSizes);
    // printf("%d\n", returnSize);
    for(int j = 0; j < returnSize; j++) {
        for(int i = 0; i < size; i++) {
            printf("%d ", *(*(permutations + j) + i));
        }
        printf("\n");
    }
    return 0;
}
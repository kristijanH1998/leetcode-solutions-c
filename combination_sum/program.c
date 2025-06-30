/*
Example input: candidates = [2,3,6,7], target = 7
Algorithm: recursive solution. In each call to combinationSum(), subtract each of the candidates from the target,
and each time (after each subtraction), recursively call combinationSum() with the same array of candidates, up-
dated target value(after one element has been subtracted from it), and maintain between calls an array of integers
that have been so far subtracted in that recursive chain of calls to combinationSum(). The base case is when
target == 0, that means that the combination of integers that have been subtracted from target, when added
together, equal target (in this case 7). Array of integer arrays must be maintained throughout the algorithm,
and each time the base case is reached, an array of integers subtracted in the chain of calls to the function
must be saved in that array of integer arrays. Since it is possible to subtract too much value from target and
end up with a negative value, that is also another base case where function combinationSum() returns and doesn't
call itself anymore, but when this is reached, nothing is stored in the resulting array of integer arrays, because
this combination of integers subtracted from the target, when added together, will equal more than the value of
the target (here more than 7).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

int cmpIntegers(const void *i1, const void *i2) {
    if(*(int *)i1 > *(int *)i2) {
        return 1;
    } else if(*(int *)i1 < *(int *)i2) {
        return -1;
    } else {
        return 0;
    }
}

bool findDuplicateCombs(int ***combinations, int *tempCombinationCopy, int returnSize, int tempCombCounter) {
    for(int i = 0; i < returnSize; i++) {
        if(memcmp(*(*combinations + i), tempCombinationCopy, tempCombCounter) == 0) {
            return true;
        }
    }
    return false;
}

// note: this function will print/store all permutations of valid combinations, for example if Input: 
// candidates = [2,3,6,7], target = 7, then [7], [2, 2, 3], [2, 3, 2], [3, 2, 2] will all be returned, but only
// [7] and [2, 2, 3] should be returned. The solution to this is to qsort() all arrays before they are stored
// in 'combinations', and before storing new ones they must be compared with existing arrays there to avoid
// duplicates
void findCombinations(int ***combinations, int *candidates, int candidatesSize, int target, \
    int *returnSize, int tempCombCounter, int *tempCombination, int ***returnColumnSizes, int startindex) {
    int i;
    if(target <= 0) {
        if(target == 0) {
            // printf("Combination found!\n");
            // for(i = 0; i < tempCombCounter; i++) {
            //     printf("%d ", tempCombination[i]);
            // }
            // printf("\n");
            // int tempCombinationCopy[tempCombCounter];
            // memcpy(tempCombinationCopy, tempCombination, sizeof(int) * tempCombCounter);
            // qsort(tempCombinationCopy, tempCombCounter, sizeof(int), cmpIntegers);
            // if(!findDuplicateCombs(combinations, tempCombinationCopy, (*returnSize), tempCombCounter)) {
            *returnSize = *returnSize + 1;
            *combinations = (int **)realloc(*combinations, ((*returnSize)) * sizeof(int *));
            *(*combinations + (*returnSize - 1)) = (int *)malloc(tempCombCounter * sizeof(int));
            // memcpy(*(*combinations + (*returnSize - 1)), tempCombinationCopy, sizeof(int) * tempCombCounter);
            memcpy(*(*combinations + (*returnSize - 1)), tempCombination, sizeof(int) * tempCombCounter);

            *(*returnColumnSizes + (*returnSize - 1)) = (int *)malloc(sizeof(int));
            *(*(*returnColumnSizes + (*returnSize - 1))) = tempCombCounter;
            *returnColumnSizes = (int **)realloc(*returnColumnSizes, ((*returnSize) * sizeof(int *)));
            // }
        } 
        return;
    }
    for(i = startindex; i < candidatesSize; i++) {
        tempCombination[tempCombCounter] = candidates[i];
        findCombinations(combinations, candidates, candidatesSize, target - candidates[i], \
            returnSize, tempCombCounter + 1, tempCombination, returnColumnSizes, i);
    }
}

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **combinations, \
    int ***returnColumnSizes) {
    // *combinations = (int *)malloc(sizeof(int));
    int tempCombination[target] = {}; 
    findCombinations(&combinations, candidates, candidatesSize, target, returnSize, 0, tempCombination, returnColumnSizes, 0);
    // printf("%d\n", *returnSize);
    return combinations;
}

int main(void) {
    int candidates[] = {2, 3, 6, 7};
    int candidatesSize = sizeof(candidates) / sizeof(int);
    // printf("%d\n", candidatesSize);
    int target = 7;
    // const int maxCombinationLen = target;
    int returnSize = 0;
    // int **combinations = (int **)malloc(sizeof(int *));
    // *combinations = (int *)malloc(sizeof(int));
    int **returnColumnSizes = (int **)malloc(sizeof(int *));
    int **combinations = combinationSum(candidates, candidatesSize, target, &returnSize, combinations, &returnColumnSizes);
    for(int i = 0; i < returnSize; i++) {
        for(int j = 0; j < (*(returnColumnSizes[i])); j++) {
            printf("%d ", combinations[i][j]);
        }
        printf("\n");
        // printf("%d\n", combinations[i][0]);
        // printf("%d\n", *(returnColumnSizes[i]));
    }
    for(int i = 0; i < returnSize; i++) {
        free(combinations[i]);
        combinations[i] = NULL;
    }
    free(combinations);
    combinations = NULL;

    // int a = 4;
    // int b = 4;
    // printf("%d\n", cmpIntegers(&a, &b));
    return 0;
}
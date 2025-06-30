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

bool findDuplicateCombs(int ***combinations, int *tempCombinationCopy, int *returnSize, int tempCombCounter) {
    for(int i = 0; i < (*returnSize); i++) {
        if(memcmp(*(*combinations + i), tempCombinationCopy, tempCombCounter) == 0) {
            return true;
        }
    }
    return false;
}

void findCombinations(int ***combinations, int *candidates, int candidatesSize, int target, \
    int *returnSize, int tempCombCounter, int *tempCombination, int ***returnColumnSizes, int startindex) {
    int i;
    if(target <= 0) {
        if(target == 0) {
            int tempCombinationCopy[tempCombCounter];
            memcpy(tempCombinationCopy, tempCombination, sizeof(int) * tempCombCounter);
            qsort(tempCombinationCopy, tempCombCounter, sizeof(int), cmpIntegers);
            if(!findDuplicateCombs(combinations, tempCombinationCopy, returnSize, tempCombCounter)) {
                *returnSize = *returnSize + 1;
                *combinations = (int **)realloc(*combinations, ((*returnSize + 1)) * sizeof(int *));
                *(*combinations + (*returnSize - 1)) = (int *)malloc(tempCombCounter * sizeof(int));
                memcpy(*(*combinations + (*returnSize - 1)), tempCombinationCopy, sizeof(int) * tempCombCounter);

                *(*returnColumnSizes + (*returnSize - 1)) = (int *)malloc(sizeof(int));
                *(*(*returnColumnSizes + (*returnSize - 1))) = tempCombCounter;
                *returnColumnSizes = (int **)realloc(*returnColumnSizes, ((*returnSize + 1) * sizeof(int *)));
            }
        } 
        return;
    }
    for(i = startindex; i < candidatesSize; i++) {
        tempCombination[tempCombCounter] = candidates[i];
        findCombinations(combinations, candidates, candidatesSize, target - candidates[i], \
            returnSize, tempCombCounter + 1, tempCombination, returnColumnSizes, i + 1);
    }
}

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **combinations, \
    int ***returnColumnSizes) {
    int tempCombination[target] = {}; 
    findCombinations(&combinations, candidates, candidatesSize, target, returnSize, 0, tempCombination, returnColumnSizes, 0);
    return combinations;
}

int main(void) {
    int candidates[] = {10,1,2,7,6,1,5};
    int candidatesSize = sizeof(candidates) / sizeof(int);
    int target = 8;
    int returnSize = 0;
    int **returnColumnSizes = (int **)malloc(sizeof(int *));
    int **combinations = combinationSum(candidates, candidatesSize, target, &returnSize, combinations, &returnColumnSizes);
    for(int i = 0; i < returnSize; i++) {
        for(int j = 0; j < (*(returnColumnSizes[i])); j++) {
            printf("%d ", combinations[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < returnSize; i++) {
        free(combinations[i]);
        combinations[i] = NULL;
    }
    free(combinations);
    combinations = NULL;
    return 0;
}
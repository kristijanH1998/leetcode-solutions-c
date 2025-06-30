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

// note: this function will print/store all permutations of valid combinations, for example if Input: 
// candidates = [2,3,6,7], target = 7, then [7], [2, 2, 3], [2, 3, 2], [3, 2, 2] will all be returned, but only
// [7] and [2, 2, 3] should be returned. The solution to this is to qsort() all arrays before they are stored
// in 'combinations', and before storing new ones they must be compared with existing arrays there to avoid
// duplicates
bool findCombinations(int ***combinations, int *candidates, int candidatesSize, int target, \
    int *returnSize, int tempCombCounter, int *tempCombination) {
    int i;

    if(target <= 0) {
        // for(i = 0; i < *(*(*combinations + returnSize) + returnColumnSizes[returnSize]); i++) {

        // }
        if(target == 0) {
            printf("Combination found!\n");
            for(i = 0; i < tempCombCounter; i++) {
                printf("%d ", tempCombination[i]);
            }
            printf("\n");
            return true;
        } 
        return false;
    }
    // bool combFound = false;
    for(i = 0; i < candidatesSize; i++) {
        tempCombination[tempCombCounter] = candidates[i];
        findCombinations(combinations, candidates, candidatesSize, target - candidates[i], \
            returnSize, tempCombCounter + 1, tempCombination);
    }
}

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes) {
    int **combinations = (int **)malloc(sizeof(int *));
    *combinations = (int *)malloc(sizeof(int));
    int tempCombination[target] = {}; 
    findCombinations(&combinations, candidates, candidatesSize, target, returnSize, 0, tempCombination);
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
    combinationSum(candidates, candidatesSize, target, &returnSize, returnColumnSizes);
    return 0;
}
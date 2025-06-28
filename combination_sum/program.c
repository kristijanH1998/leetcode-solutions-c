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

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes) {

    return NULL;
}

int main(void) {

    return 0;
}
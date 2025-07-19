#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

static int cmpInts(const void *i1, const void *i2) {
    return (*(int **)i1)[0] - (*(int **)i2)[0]; 
}

int** merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes) {
    // if(intervals == NULL || (*intervals) == NULL || intervalsColSize == NULL || returnSize == NULL || \
    //     returnColumnSizes == NULL || (*returnColumnSizes) == NULL) {
    //     return NULL;
    // }
    if(intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int i, j;
    // for(i = 0; i < intervalsSize; i++) {
    //     for(j = 0; j < *intervalsColSize; j++) {
    //         printf("%d ", intervals[i][j]);
    //     }
    //     printf("\n");
    // }
    qsort(intervals, intervalsSize, sizeof(int *), cmpInts);
    int **result = (int**)malloc(sizeof(int*));
    *(result + 0) = (int*)malloc(2 * sizeof(int));
    int resSize = 0;
    *(*(result + resSize) + 0) = *(*(intervals + 0) + 0);
    *(*(result + resSize) + 1) = *(*(intervals + 0) + 1);
    for(i = 0; i < (intervalsSize - 1); i++) {
        if(*(*(result + resSize) + 1) >= *(*(intervals + i + 1) + 0)) {
            *(*(result + resSize) + 0) = MIN(*(*(result + resSize) + 0), *(*(intervals + i + 1) + 0));
            *(*(result + resSize) + 1) = MAX(*(*(result + resSize) + 1), *(*(intervals + i + 1) + 1));
        } else /*if (*(*(intervals + i) + 1) >= *(*(intervals + i + 1) + 0))*/{
            // *(*(result + resSize) + 0) = MIN(*(*(intervals + i) + 0), *(*(intervals + i + 1) + 0));
            // *(*(result + resSize) + 1) = MAX(*(*(intervals + i + 1) + 1), *(*(intervals + i) + 1));
            resSize++;
            result = (int**)realloc((int**)result, (resSize + 1) * sizeof(int*));
            *(result + resSize) = (int*)malloc(2 * sizeof(int));
            *(*(result + resSize) + 0) = *(*(intervals + i + 1) + 0);
            *(*(result + resSize) + 1) = *(*(intervals + i + 1) + 1);
        }
    }
    *returnColumnSizes = (int*)malloc(resSize * sizeof(int));
    for(i = 0; i < resSize; i++) {
        *(*returnColumnSizes + i) = 2;
    }
    // printf("%d\n", resSize);
    *returnSize = resSize;
    return result;
}

int main(void) {
    // printf("%d\n", MAX(41, 2));
    int intervalsSize = 2;
    int intervalsColSize = 2;
    int **intervals = (int**)malloc(intervalsSize * sizeof(int*));
    for(int i = 0; i < intervalsSize; i++) {
       *(intervals + i) = (int*)malloc(intervalsColSize * sizeof(int));
    }
    // *(*(intervals + 0) + 0) = 1;
    // *(*(intervals + 0) + 1) = 3;
    // *(*(intervals + 1) + 0) = 2;
    // *(*(intervals + 1) + 1) = 6;
    // *(*(intervals + 2) + 0) = 8;
    // *(*(intervals + 2) + 1) = 10;
    // *(*(intervals + 3) + 0) = 15;
    // *(*(intervals + 3) + 1) = 18;
    *(*(intervals + 0) + 0) = 1;
    *(*(intervals + 0) + 1) = 4;
    *(*(intervals + 1) + 0) = 4;
    *(*(intervals + 1) + 1) = 5;
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **result = merge(intervals, intervalsSize, &intervalsColSize, &returnSize, &returnColumnSizes);
    int i;
    for(i = 0; i <= returnSize; i++) {
        printf("%d %d\n", *(*(result + i) + 0), *(*(result + i) + 1));
    }
    return 0;
}
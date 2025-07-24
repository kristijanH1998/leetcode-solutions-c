#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static bool codeFound = false;

void findCode(int n, int first, int count, int code[]) {
    extern bool codeFound;
    printf("%d ", first);
    code[count] = first;
    if(count == (int)pow(2, n)) {
        // for(int j = 0; j < n; j++) {
        //     if(first == pow(2, j)) {
        //         printf("graycode found!");
        //         codeFound = true;
        //         break;
        //     }
        // }
        if(first == pow(2, (n - 1))) {
            codeFound = true;
            printf("graycode found!\n");
        }
        // printf("\n");
        return;
    }
    int current;
    for(int i = 0; i < n; i++) {
        current = first + (int)pow(2, i);
        if((current > 0) && (current < pow(2, n))) {
            if(codeFound) return; else findCode(n, current, count + 1, code);
        }
        current = first - (int)pow(2, i);
        if((current > 0) && (current < pow(2, n))) {
            if(codeFound) return; else findCode(n, current, count + 1, code);
        }
    }
}

int *grayCode(int n, int *returnSize) {
    int codeSize = (int)pow(2, n);
    int *code = (int*)malloc(codeSize * sizeof(int));
    int first = 0;
    int codeTemp[codeSize] = {};
    findCode(n, first, 1, codeTemp);
    // for(int i = 0; i < codeSize; i++) {
    //     printf("%d ", code[i]);
    // }
    // printf("\n");
    return code;
}

int main(void) {
    int returnSize = 0;
    int *code = grayCode(3, &returnSize);
    free(code);
    return 0;
}
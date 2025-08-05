#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scramble(int swapInd, char *s1, char *s2, int start, int end, bool swap, char **scrambles, int *scramblesCnt) {
    if(!(swapInd > start && swapInd <= end) || (start >= end)) {
        return;
    }
    // if(end - start == 1) {
    //     // (*scramblesCnt)++;
    //     // strcpy(*(scrambles + ((*scramblesCnt) - 1)), s1);
    //     // scrambles = realloc(scrambles, ((*scramblesCnt) + 1) * sizeof(char *));
    //     // *(scrambles + (*scramblesCnt)) = (char*)malloc(sLen * sizeof(char));
    //     // return s1;
    //     return;
    // }

    int sLen = strlen(s1);
    char sCpy[sLen];
    strcpy(sCpy, s1);
    
    char *leftHalf = strndup(s1 + start, swapInd - start);
    char *rightHalf = strndup(s1 + swapInd, end - swapInd + 1);
    printf("%s\n", leftHalf);
    printf("%s\n", rightHalf);
    int i, j;
    int rightHalfLen = strlen(rightHalf);
    for(i = 0; i < rightHalfLen; i++) {
        sCpy[start + i] = rightHalf[i];
    }
    // printf("%s\n", sCpy);
    int leftHalfLen = strlen(leftHalf);
    for(j = 0; j < leftHalfLen; j++, i++) {
        sCpy[start + i] = leftHalf[j];
    }
    printf("%s\n", sCpy);
    // printf("%d %d\n", leftHalfLen, rightHalfLen);

    // return sCpy;
}

bool isScramble(char *s1, char *s2) {
    if(s1 == NULL || s2 == NULL) {
        return false;
    }
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    if(s1Len != s2Len || s1Len == 0) {
        return false;
    }
    char **scrambles = (char **)malloc(sizeof(char*));
    *(scrambles) = (char*)malloc(s1Len * sizeof(char));
    int scramblesCnt = 0;
    // for(int i = 1; i < s1Len; i++) {
    //     scramble(i, s1, scrambles, &scramblesCnt);
    // }
    // scramble(4, s1, 0, 5, true, scrambles, &scramblesCnt);
    // scramble(4, s1, 1, 5, true, scrambles, &scramblesCnt);
    // scramble(2, s1, 0, 5, true, scrambles, &scramblesCnt);
    int i;
    for(i = 0; i < s1Len; i++) {
        scramble(i, s1, s2, 1, 3, true, scrambles, &scramblesCnt);
    }



    return false;
}

int main() {
    char *s1 = "great";
    char *s2 = "rgeat";
    printf(isScramble(s1, s2) ? "true\n" : "false\n");
    return 0;
}
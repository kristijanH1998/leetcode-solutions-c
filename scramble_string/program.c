#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// my solution:
void scramble(int swapInd, char *s1, char *s2, int start, int end, bool *result) {
    if(!(swapInd > start && swapInd <= end) || (start >= end)) {
        return;
    }
    if(end - start <= 1) {
    //     // (*scramblesCnt)++;
    //     // strcpy(*(scrambles + ((*scramblesCnt) - 1)), s1);
    //     // scrambles = realloc(scrambles, ((*scramblesCnt) + 1) * sizeof(char *));
    //     // *(scrambles + (*scramblesCnt)) = (char*)malloc(sLen * sizeof(char));
    //     // return s1;
    //     return;
        if(strcmp(s1, s2) == 0) {
            *result = true;
            return;
        }
    }
    int sLen = strlen(s1);
    char *leftHalf = strndup(s1 + start, swapInd - start);
    char *rightHalf = strndup(s1 + swapInd, end - swapInd + 1);
    printf("%s", leftHalf);
    printf(" %s", rightHalf);
    int i, j;
    int rightHalfLen = strlen(rightHalf);
    char sCpy[sLen + 1];
    strcpy(sCpy, s1);
    for(i = 0; i < rightHalfLen; i++) {
        sCpy[start + i] = rightHalf[i];
    }
    // printf("%s\n", sCpy);
    int leftHalfLen = strlen(leftHalf);
    for(j = 0; j < leftHalfLen; j++, i++) {
        sCpy[start + i] = leftHalf[j];
    }
    printf(" %s\n", sCpy);
    // printf("%d %d\n", leftHalfLen, rightHalfLen);
    // return sCpy;
    if(strcmp(sCpy, s2) == 0) {
        *result = true;
        return;
    }
    for(i = 0; i < swapInd; i++) {
        scramble(i, s1, s2, start, swapInd - 1, result);
        scramble(i, s1, s2, swapInd, end, result);
    }
    return;
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
    bool result = false;
    if(strcmp(s1, s2) == 0) {
        return true;
    } else {
        int i;
        for(i = 0; i < s1Len; i++) {
            scramble(i, s1, s2, 0, s1Len - 1, &result);
        }
    }
    return result;
}

// void scramble(int swapInd, char *s1, char *s2, int start, int end, bool *result) {
//     if(!(swapInd > start && swapInd <= end) || (start >= end)) {
//         return;
//     }
//     if(end - start <= 1) {
//         if(strcmp(s1, s2) == 0) {
//             *result = true;
//             return;
//         }
//     }
//     int sLen = strlen(s1);
//     char *leftHalf = strndup(s1 + start, swapInd - start);
//     char *rightHalf = strndup(s1 + swapInd, end - swapInd + 1);
//     int i, j;
//     int rightHalfLen = strlen(rightHalf);
//     char sCpy[sLen + 1];
//     strcpy(sCpy, s1);
//     for(i = 0; i < rightHalfLen; i++) {
//         sCpy[start + i] = rightHalf[i];
//     }
//     int leftHalfLen = strlen(leftHalf);
//     for(j = 0; j < leftHalfLen; j++, i++) {
//         sCpy[start + i] = leftHalf[j];
//     }
//     if(strcmp(sCpy, s2) == 0) {
//         *result = true;
//         return;
//     }
//     for(i = 0; i < swapInd; i++) {
//         scramble(i, s1, s2, start, swapInd - 1, result);
//         scramble(i, s1, s2, swapInd, end, result);
//     }
//     return;
// }

// bool isScramble(char *s1, char *s2) {
//     if(s1 == NULL || s2 == NULL) {
//         return false;
//     }
//     int s1Len = strlen(s1);
//     int s2Len = strlen(s2);
//     if(s1Len != s2Len || s1Len == 0) {
//         return false;
//     }
//     bool result = false;
//     if(strcmp(s1, s2) == 0) {
//         return true;
//     } else {
//         int i;
//         for(i = 0; i < s1Len; i++) {
//             scramble(i, s1, s2, 0, s1Len - 1, &result);
//         }
//     }
//     return result;
// }

// chatGPT refined version of my solution:
// void scramble(int swapInd, char *s1, char *s2, int start, int end, bool *result) {
//     if (*result) return; // early exit if result is already found
//     if (start >= end || swapInd <= start || swapInd > end) {
//         return;
//     }
//     if (end - start <= 1) {
//         if (strcmp(s1, s2) == 0) {
//             *result = true;
//         }
//         return;
//     }
//     int sLen = strlen(s1);
//     char *leftHalf = strndup(s1 + start, swapInd - start);
//     char *rightHalf = strndup(s1 + swapInd, end - swapInd + 1);
//     int i, j;
//     int rightHalfLen = strlen(rightHalf);
//     int leftHalfLen = strlen(leftHalf);
//     // Allocate space for null-terminated copy
//     char sCpy[sLen + 1];
//     strcpy(sCpy, s1);
//     for (i = 0; i < rightHalfLen; i++) {
//         sCpy[start + i] = rightHalf[i];
//     }
//     for (j = 0; j < leftHalfLen; j++, i++) {
//         sCpy[start + i] = leftHalf[j];
//     }
//     sCpy[sLen] = '\0'; // ensure null termination
//     if (strcmp(sCpy, s2) == 0) {
//         *result = true;
//         free(leftHalf);
//         free(rightHalf);
//         return;
//     }
//     // Recurse on both halves
//     for (i = start + 1; i <= end && !(*result); i++) {
//         scramble(i, s1, s2, start, swapInd - 1, result);
//         scramble(i, s1, s2, swapInd, end, result);
//     }
//     free(leftHalf);
//     free(rightHalf);
// }
// bool isScramble(char *s1, char *s2) {
//     if (s1 == NULL || s2 == NULL) {
//         return false;
//     }
//     int s1Len = strlen(s1);
//     int s2Len = strlen(s2);
//     if (s1Len != s2Len || s1Len == 0) {
//         return false;
//     }
//     if (strcmp(s1, s2) == 0) {
//         return true;
//     }
//     bool result = false;
//     for (int i = 1; i < s1Len && !result; i++) {
//         scramble(i, s1, s2, 0, s1Len - 1, &result);
//     }
//     return result;
// }

int main() {
    char *s1 = "abc";
    char *s2 = "acb";
    // char *s2 = "tgrea";
    printf(isScramble(s1, s2) ? "true\n" : "false\n");
    return 0;
}
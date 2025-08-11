#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char *s) {
    int i, j;
    int sLen = strlen(s);
    for(i = 0, j = sLen - 1; i <= j; i++, j--) {
        if(s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

char ***substrings(char *s, int sLen, char *currSubstr, char ***substrArr, int takeChars, int cursor, int *returnSize, int subCount) {
    // int sLen = strlen(s);
    // char temp[sLen];
    // int start, subLen, first;
    // first = 0;
    // while(first < sLen) {
    //     for(start = first, subLen = 1; subLen <= sLen; start = 0, subLen++) {
    //         while(start < sLen) {
    //             strncpy(temp, s + start, subLen);
    //             temp[sLen] = '\0';
    //             printf("%s ", temp);
    //             // subLen++;
    //             start += subLen;
    //         }
    //         printf("\n");
    //     }
    //     first++;
    // }
    // printf("%d\n", takeChars);
    if(cursor >= (sLen)) {
        // puts(currSubstr);
        substrArr = (char***)realloc(substrArr, (*returnSize + 1) * sizeof(char **));
        (*returnSize)++;
        return NULL;
    }
    *(substrArr + *returnSize) = (char**)realloc(*(substrArr + *returnSize), (subCount + 1) * sizeof(char*));
    *(*(substrArr + *returnSize) + subCount) = (char*)malloc(sLen * sizeof(char));
    // strncpy(currSubstr + cursor, s + cursor, takeChars);
    strncpy(*(*(substrArr + *returnSize) + subCount), s + cursor, takeChars);
    
    int i; 
    for(i = 1; i < sLen; i++) {
        char currSubstrCpy[sLen + 1];
        memset(currSubstrCpy, 0, sizeof(currSubstrCpy));
        strcpy(currSubstrCpy, currSubstr);
        substrings(s, sLen, currSubstrCpy, substrArr, i, cursor + takeChars, returnSize, subCount + 1);
    }
    
    return NULL;
}

char ***partition(char *s, int *returnSize, int **returnColumnSizes) {
    int sLen = strlen(s);
    char currSubstr[sLen + 1];
    memset(currSubstr, 0, sizeof(currSubstr));
    char ***substrArr = (char ***)malloc(sizeof(char **));
    *(substrArr) = (char **)malloc(sizeof(char *));
    *(*(substrArr)) = (char *)malloc(sLen * sizeof(char));
    substrArr = substrings(s, sLen, currSubstr, substrArr, 1, 0, returnSize, 0);
    // for(int i = 0; i < *returnSize; i++) {

    // }
    return NULL;
}

int main() {
    // printf("%d\n", isPalindrome("ebcba"));
    int returnSize = 1;
    int *returnColumnSizes[] = {};
    partition("aab", &returnSize, returnColumnSizes);
    return 0;
}
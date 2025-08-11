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

char **substrings(char *s, int sLen, char *currSubstr, char **substrArr, int takeChars, int cursor) {
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
    if(cursor >= (sLen)) {
        puts(currSubstr);
        return NULL;
    }
    strncpy(currSubstr + cursor, s + cursor, takeChars);
    char currSubstrCpy[sLen + 1];
    strcpy(currSubstrCpy, currSubstr);
    int i; 
    for(i = 1; i < sLen; i++) {
        substrings(s, sLen, currSubstrCpy, substrArr, i, cursor + takeChars);
    }
    
    return NULL;
}

char ***partition(char *s, int *returnSize, int **returnColumnSizes) {
    int sLen = strlen(s);
    char currSubstr[sLen + 1];
    substrings(s, sLen, currSubstr, NULL, 0, 0);

    return NULL;
}

int main() {
    // printf("%d\n", isPalindrome("ebcba"));
    int returnSize = 0;
    int *returnColumnSizes[] = {};
    partition("abcde", &returnSize, returnColumnSizes);
    return 0;
}
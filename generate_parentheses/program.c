#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **findParenthesis(int n, int pos, char *string, int open, int close, char ***parenthesis_arr, int **returnSize) {
    if(close == n) {
        string[pos] = '\0';
        // printf("%s\n", string);
        *parenthesis_arr = (char **)realloc(*parenthesis_arr, (**returnSize + 1) * sizeof(char *));
        *(*parenthesis_arr + **returnSize) = (char *)malloc((n * 2 + 1) * sizeof(char));
        strcpy(*(*parenthesis_arr + **returnSize), string);
        (**returnSize)++;
        return *parenthesis_arr;
    }
    if(open < n) {
        string[pos] = '(';
        findParenthesis(n, pos + 1, string, open + 1, close, parenthesis_arr, returnSize);
    }
    if(close < open) {
        string[pos] = ')';
        findParenthesis(n, pos + 1, string, open, close + 1, parenthesis_arr, returnSize);
    }   
}

char **generateParenthesis(int n, int *returnSize) {
    if(n < 1 || n > 8) {
        return NULL;
    }
    char **parenthesis_arr = NULL;
    char *string = (char *)malloc((n * 2 + 1) * sizeof(char));
    findParenthesis(n, 0, string, 0, 0, &parenthesis_arr, &returnSize);
    for(int i = 0; i < (*returnSize); i++) {
        printf("%s\n", *(parenthesis_arr + i));
    }
    return parenthesis_arr;
}

int main(void) {
    int returnSize = 0;
    generateParenthesis(5, &returnSize);
    printf("Size of returned array of parenthesis strings: %d\n", returnSize);
    return 0;
}
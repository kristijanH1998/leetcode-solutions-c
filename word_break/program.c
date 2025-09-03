#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void breakString(char *currentS, char **wordDict, int wordDictSize, char *dictStrToCut, int *test) {
    // int leftEnd = strstr(currentS, dictStrToCut) - currentS;
    // char leftSide[leftEnd + 2];
    // strncpy(leftSide, currentS, leftEnd + 1);
    // int rightStart = leftEnd + strlen(dictStrToCut);
    // char rightSide[strlen(currentS) - rightStart + 2];
    // strncpy(rightSide, currentS + rightStart, strlen(currentS) - rightStart);
    // char *leftSide = 
    // printf("%s %d\n", currentS, strlen(currentS));
    if(*test == 1) {
        return;
    }
    if(strlen(currentS) == 0) {
        // return true;
        // puts("True");
        *test = 1;
        return;
    } 
    if(strlen(currentS) < strlen(dictStrToCut) || strstr(currentS, dictStrToCut) == NULL) {
        return;
    }
    char newCurrentS[strlen(currentS) - strlen(dictStrToCut) + 1];
    int atIndex = strstr(currentS, dictStrToCut) - currentS;
    int i, j = 0;
    for(i = 0; i < atIndex; i++, j++) {
        newCurrentS[j] = currentS[i];
    }
    for(i = atIndex + strlen(dictStrToCut); i < strlen(currentS); i++, j++) {
        newCurrentS[j] = currentS[i];
    }
    newCurrentS[strlen(currentS) - strlen(dictStrToCut)] = '\0';
    // puts(newCurrentS);
    for(i = 0; i < wordDictSize; i++) {
        if(*test == 0) {
            breakString(newCurrentS, wordDict, wordDictSize, wordDict[i], test);
        } else {
            break;
        }
    }
}

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    // for(int i = 0; i < wordDictSize; i++) {
    //     printf("%s ", wordDict[i]);
    // }
    // printf("\n");
    // int i;
    // for(i = 0; i < wordDictSize; i++) {

    // }
    int test = 0;
    breakString(s, wordDict, wordDictSize, wordDict[0], &test);
    return test == 1;
}

int main() {
    char *wordDict[] = {"cats", "dog", "sand", "and", "cat"};
    // char *wordDict[] = {"leet", "code"};
    // char *wordDict[] = {"apple", "pen"};
    int wordDictSize = sizeof(wordDict) / sizeof(char *);
    // printf("%d\n", wordDictSize);
    char *s = "catsandog";
    // char *s = "leetcode";
    // char s[] = "applepenapple";
    int test = wordBreak(s, wordDict, wordDictSize);
    fputs(test > 0 ? "True\n" : "False\n", stdout);
    //////////////////////////
    // char *(*strings)[wordDictSize];
    // strings = &wordDict;
    // for(int i = 0; i < wordDictSize; i++) {
        // printf("%s ", (*strings)[i]);
    // }
    // printf("\n");
    // char s2[] = "catsandog";
    // char *tok = strtok(s2, "nd");
    // printf("%d %s\n", strlen(tok), tok);
    // char **strings2;
    // strings2 = &wordDict;
    // printf("%d\n", strstr(s, "dog") - s);


    // char *currentS = "catsandogturtle";
    // char *dictStrToCut = "dog";
    // char newCurrentS[strlen(currentS) - strlen(dictStrToCut) + 1];
    // int atIndex = strstr(currentS, dictStrToCut) - currentS;
    // printf("%d\n", atIndex);
    // int i, j = 0;
    // for(i = 0; i < atIndex; i++, j++) {
    //     newCurrentS[j] = currentS[i];
    // }
    // printf("%d\n", atIndex + strlen(dictStrToCut));
    // for(i = atIndex + strlen(dictStrToCut); i < strlen(currentS); i++, j++) {
    //     newCurrentS[j] = currentS[i];
    // }
    // newCurrentS[strlen(currentS) - strlen(dictStrToCut)] = '\0';
    // printf("%s\n", newCurrentS);


    // int leftEnd = strstr(currentS, dictStrToCut) - currentS;
    // char leftSide[leftEnd + 2];
    // leftSide[leftEnd + 1] = '\0';
    // if(leftEnd > 0) {
    //     strncpy(leftSide, currentS, leftEnd);
    // }
    
    // int rightStart = leftEnd + strlen(dictStrToCut);
    // printf("%d\n", rightStart);
    // char rightSide[strlen(currentS) - rightStart + 1];
    // printf("%d\n", strlen(currentS) - rightStart + 1);
    // rightSide[strlen(currentS) - rightStart] = '\0';
    // if(rightStart < (strlen(currentS) - 1)) {
    //     strncpy(rightSide, currentS + rightStart, strlen(currentS) - rightStart);
    // }
    // char newCurrentS[strlen(leftSide) + strlen(rightSide) + 1];
    // strcat(newCurrentS, leftSide);
    // strcat(newCurrentS, rightSide);
    // printf("%s\n", newCurrentS);

    return 0;
}
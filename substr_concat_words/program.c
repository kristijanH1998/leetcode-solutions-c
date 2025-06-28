// 30.Substring with concatenation of all words
/*
Approach: Create an array of strings, where each string will be one permutation of strings in 'words' array
Next, for each of those permutations, try to find it inside string 's', by for each character index in 's' checking
whether next <length of permutation> characters in 's' match the characters in the permutation. If yes, return
the index at which this is true.

Easier approach:
Example: Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Since all strings in 'words' must be the same length, to find a permutation of them in 's', start at beginning
of 's' and focus on first 3+3+3=9 characters in 's'. First try to find "bar" in that section of 's', then see
if "foo" is there, and then if "the" is there, and if all three checks pass, that means that starting at index 0,
a permutation of strings in 'words' array exists as first 9 characters in 's' string. 
Repeat the same process starting at index 3 of 's' string, moving 3 indices from start of 's' because 3
equals the length of each of strings in 'words'. If all three checks pass, return index 3 as well. Move through
's' like this until last 9 characters are being analyzed. Once that is done, no more checks are necessary.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    int res = 1;
    while(n > 0) {
       res *= n;
       n--;
    }
    return res;
}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize) {
    if(words == NULL || (*words == NULL) || s == NULL || returnSize == NULL) {
        return NULL;
    }
    int i, j, k, l;
    // for(int i = 0; i < wordsSize; i++) {
    //     printf("%s\n", *(words + i));
    // }
    int wordLength = strlen(words[0]);
    int matches = 0;
    int totalChars = strlen(s);
    bool matchIndices[wordsSize] = {};
    for(l = 0; l < wordsSize; l++) {
        matchIndices[l] = false;
    }
    int *res = (int *)malloc(sizeof(int) * (totalChars / wordLength));
    int resSize = 0;
    for(k = 0; k < totalChars; k += wordLength) {
        for(j = k; j < (k + (wordsSize * wordLength)); j += wordLength) {
            for(i = 0; i < wordsSize; i++) {
                if(strncmp(words[i], s + j, wordLength) == 0) {
                    if(!matchIndices[i]) {
                        matchIndices[i] = true;
                        matches++;
                        break;
                    } else {
                        continue;
                    }
                }
            }
        }
        for(l = 0; l < wordsSize; l++) {
            matchIndices[l] = false;
        }
        if(matches == wordsSize) {
            // printf("%d\n", k);
            *(res + resSize) = k;
            resSize++;
        } 
        matches = 0;
    }
    *returnSize = resSize;
    return res;
}

int main(void) {
    // printf("%d\n", factorial(6));
    char *s = "barfoofoobarthefoobarman";
    char *words[] = {"bar","foo","the"};
    int wordsSize = sizeof(words) / sizeof(char*);
    int returnSize = 0;
    int *res = findSubstring(s, words, wordsSize, &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", *(res + i));
    }
    printf("\n");
    free(res);
    return 0;
}
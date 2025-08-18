#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateIndices(int *, int, int, int);

// int numDistinct(char *s, char *t) {
//     int matches = 0;
//     int sLen = strlen(s);
//     int tLen = strlen(t);
//     int start = 0;
//     int charsFound = 0;
//     int i, j;
//     while(start <= (sLen - tLen)) {
//         j = 0;
//         for(i = start; i < sLen; i++) {
//             if(t[j] == s[i]) {
//                 charsFound++;
//                 j++;
//             }
//             if(charsFound == tLen) {
//                 matches++;
//                 charsFound--;
//             }
//         }
//         charsFound = 0;
//         start++;
//     }
//     return matches;
// }

char *buildStr(char *s, int indices[], int numIndices) {
    int i;
    char *str = (char *)malloc(numIndices + 1);
    for(i = 0; i < numIndices; i++) {
        str[i] = s[indices[i]];
    }
    str[numIndices] = '\0';
    return str;
}

int numDistinct(char *s, char *t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    int indices[tLen];
    int i;
    for(i = 0; i < tLen; i++) {
        indices[i] = i;
        // printf("%d ", indices[i]);
    }
    // int pos = tLen - 1;
    // while(pos >= 0) {
    //     while(indices[pos] < sLen) {
    //         for(i = 0; i < tLen; i++) {
    //             printf("%d ", indices[i]);
    //         }
    //         printf("\n");
    //         (indices[pos])++;
    //     }
    //     (indices[pos - 1])++;
    //     pos--;
    // }
    // printf("\n");
    // puts(buildStr(s, indices, tLen));
    generateIndices(indices, tLen, sLen, 0);



    return 0;
}

void generateIndices(int *indices, int indSize, int limit, int pos) {
    int i;
    // int temp[indSize];
    // for(i = 0; i < indSize; i++) {
    //     printf("%d ", indices[i]);
    // }
    // printf("\n");
    // for(i = 0; i < indSize; i++) {
    //     // printf("%d ", indices[i]);
    //     memcpy(temp, indices, indSize * sizeof(int));
    //     (temp[i])++;
    //     generateIndices(temp, indSize);
    // }
    // printf("\n");
    
    // if(indices[pos] > limit) {
    //     return;
    // }
    if(pos == indSize) {
        bool sorted = true;
        for(i = 0; i < (indSize - 1); i++) {
            if(indices[i] >= indices[i + 1]) {
                sorted = false;
            }
        }
        if(sorted) {
            for(i = 0; i < indSize; i++) {
                printf("%d ", indices[i]);
            }
            printf("\n");
        }  
    }
    int temp[indSize];
    memcpy(temp, indices, indSize * sizeof(int));
    while(temp[pos] <= (limit - (indSize - (pos + 1)))) {
        generateIndices(temp, indSize, limit, pos + 1);
        (temp[pos])++;
    }
}

int main(void) {
    char *s = "babgbag";
    char *t = "bag";
    int res = numDistinct(s, t);
    printf("%d\n", res);
    return 0;
}
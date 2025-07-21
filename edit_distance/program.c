#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b,c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

// Levenshtein algorithm (DP)
int minDistance(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    char matrix[len1 + 1][len2 + 1];
    int i, j;
    for(i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }
    for(i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for(i = 1; i <= len1; i++) {
        for(j = 1; j <= len2; j++) {
            if(word1[i - 1] == word2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = MIN(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
            }
        }
    }
    // for(i = 0; i <= len1; i++) {
    //     for(j = 0; j <= len2; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    return matrix[len1][len2];
}

int main(void) {
    // char word1[] = "horse";
    // char word2[] = "ros";
    char word1[] = "intention";
    char word2[] = "execution";
    printf("%d\n", minDistance(word1, word2));
    // printf("%d\n", MIN(6,2,-3));
    return 0;
}
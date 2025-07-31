#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isInterleave(char *s1, char *s2, char *s3) {
    if(s1 == NULL || s2 == NULL || s3 == NULL) {
        return false;
    }
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int s3Len = strlen(s3);
    if(s1Len < 0 || s1Len > 100 || s2Len < 0 || s2Len > 100 || s3Len < 0 || s3Len > 200 || !(s3Len == (s1Len + s2Len))) {
        return false;
    }
    if(s1Len == 0) {
        return !strcmp(s3, s2);
    } else if(s2Len == 0) {
        return !strcmp(s3, s1);
    }
    int i, j;
    bool interleave = false;
    for(i = 0, j = 0; (i + j) < s3Len; ) {
        if(s3[i + j] != s1[i] && s3[j + i] != s2[j]) {
            interleave = false;
            break;
        }
        while((i + j <= s3Len) && s3[i + j] == s1[i]) {
            i++;
        }
        while((i + j <= s3Len) && s3[j + i] == s2[j]) {
            j++;
        }
        // if()
    }
    if((i + j - 1) == s3Len) {
        interleave = true;
        return interleave;
    }
    printf("%d %d %d\n", i, j, s3Len);
    for(i = 0, j = 0; (i + j) < s3Len; ) {
        if(s3[j + i] != s2[j] && s3[i + j] != s1[i]) {
            interleave = false;
            break;
        }
        while((i + j <= s3Len) && s3[j + i] == s2[j]) {
            j++;
        }
        while((i + j <= s3Len) && s3[i + j] == s1[i]) {
            i++;
        }
    }
    if((i + j - 1) == s3Len) {
        interleave = true;
    }
    printf("%d %d %d\n", i, j, s3Len);
    
    return interleave;
}

int main(void) {
    // char *s1 = "aabcc";
    // char *s2 = "dbbca";
    // char *s3 = "aadbbcbcac";
    // char *s1 = "aabcc";
    // char *s2 = "dbbca";
    // char *s3 = "aadbbbaccc";
    // char *s1 = "";
    // char *s2 = "";
    // char *s3 = "";
    char *s1 = "aa";
    char *s2 = "ab";
    char *s3 = "aaba";
    printf(isInterleave(s1, s2, s3) ? "true\n" :  "false\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bool isInterleave(char *s1, char *s2, char *s3) {
//     if(s1 == NULL || s2 == NULL || s3 == NULL) {
//         return false;
//     }
//     int s1Len = strlen(s1);
//     int s2Len = strlen(s2);
//     int s3Len = strlen(s3);
//     if(s1Len < 0 || s1Len > 100 || s2Len < 0 || s2Len > 100 || s3Len < 0 || s3Len > 200 || !(s3Len == (s1Len + s2Len))) {
//         return false;
//     }
//     if(s1Len == 0) {
//         return !strcmp(s3, s2);
//     } else if(s2Len == 0) {
//         return !strcmp(s3, s1);
//     }
//     int i, j;
//     bool interleave = false;
//     for(i = 0, j = 0; (i + j) < s3Len; ) {
//         if(s3[i + j] != s1[i] && s3[j + i] != s2[j]) {
//             interleave = false;
//             break;
//         }
//         while((i + j <= s3Len) && s3[i + j] == s1[i]) {
//             i++;
//         }
//         while((i + j <= s3Len) && s3[j + i] == s2[j]) {
//             j++;
//         }
//         // if()
//     }
//     if((i + j - 1) == s3Len) {
//         interleave = true;
//         return interleave;
//     }
//     printf("%d %d %d\n", i, j, s3Len);
//     for(i = 0, j = 0; (i + j) < s3Len; ) {
//         if(s3[j + i] != s2[j] && s3[i + j] != s1[i]) {
//             interleave = false;
//             break;
//         }
//         while((i + j <= s3Len) && s3[j + i] == s2[j]) {
//             j++;
//         }
//         while((i + j <= s3Len) && s3[i + j] == s1[i]) {
//             i++;
//         }
//     }
//     if((i + j - 1) == s3Len) {
//         interleave = true;
//     }
//     printf("%d %d %d\n", i, j, s3Len);
    
//     return interleave;
// }

//second attempt: recursion
// typedef enum currentStr {FIRST, SECOND} currentStr;

// bool exhaust(char *s1, char *s2, char *s3, currentStr current, int takeCount, int charsTaken) {
//     if(charsTaken == strlen(s3)) {
//         return true;
//     }
//     char *curr = (current == FIRST) ? s1 : s2;
//     int currLen = strlen(curr);
//     int i;
    
//     for(i = 0; i < takeCount; i++) {
//         if(s3[i] != curr[i]) {
//             return false;
//         }
//     }
//     for(i = 0; i < currLen; i++) {
        
//     }
// }

// bool isInterleave(char *s1, char *s2, char *s3) {
//     bool interleave = false;
//     int s1Len = strlen(s1);
//     int s2Len = strlen(s2);
//     int s3Len = strlen(s3);
//     if(s1Len + s2Len != s3Len) {
//         return false;
//     }
    

//     return interleave;
// }

//third attempt: nested for loops

// bool isInterleave(char *s1, char *s2, char *s3) {
//     // let i be number of chars compared from s1 and j number of chars compared from s2, using nested loops in 2 phases
//     // test if comparing first 1 char from s1 and first 1 char from s2 with first two chars in s3 respectively
//     // results in equality, if yes, proceed in this pattern
//     // phase 2 is starting with comparing of chars from s2 to those in s3, then chars in s1 with those in s3
//     int i, j;
//     int s1Len = strlen(s1);
//     int s2Len = strlen(s2);
//     int s3Len = strlen(s3);
//     char *s3Temp = s3; 
//     for(i = 1; i < s1Len; i++) {
//         if(strncmp(s1, s3, i) == 0) {
//             s3 = s3 + i;
//             for(j = 1; j < s2Len; j++) {
//                 if(strncmp(s2, s3, j) == 0) {
//                 }
//             }
//         } 
//     }
//     for(j = 1; j < s2Len; j++) {
//         if(strncmp(s2, s3, j) == 0) {
//             s3 = s3 + j;
//             for(i = 1; i < s1Len; i++) {
//                 if(strncmp(s1, s3, i) == 0) {
//                 }
//             }
//         } 
//     }
// }
/*

The "Interleaving Strings" problem determines if a third string (s3) is formed by interleaving two other strings (s1 and s2). This means s3 must contain all characters of s1 and s2, preserving their relative order within s3, and the length of s3 must equal the combined length of s1 and s2.
The problem can be solved using dynamic programming or recursion with memoization.
Dynamic Programming Approach (Bottom-Up)

    Length Check: Verify if len(s3) == len(s1) + len(s2). If not, s3 cannot be an interleaving, so return False. 

DP Table Initialization: Create a 2D boolean array dp of size (len(s1) + 1) x (len(s2) + 1). dp[i][j] will represent whether the prefix of s3 of length i+j can be formed by interleaving the first i characters of s1 and the first j characters of s2. 
Base Case: dp[0][0] = True (empty strings interleave to form an empty string).
Filling the DP Table: Iterate through i from 0 to len(s1) and j from 0 to len(s2). 

    If i == 0 and j > 0: dp[0][j] is True if dp[0][j-1] is True and s2[j-1] matches s3[j-1].

If j == 0 and i > 0: dp[i][0] is True if dp[i-1][0] is True and s1[i-1] matches s3[i-1].
If i > 0 and j > 0: dp[i][j] is True if:

    dp[i-1][j] is True AND s1[i-1] matches s3[i+j-1] (take character from s1)

OR dp[i][j-1] is True AND s2[j-1] matches s3[i+j-1] (take character from s2)

Result: The final answer is dp[len(s1)][len(s2)].

Recursive Approach with Memoization (Top-Down)

    Length Check: Same as above.

Memoization Table: Create a 2D array (or dictionary/map) memo to store results of subproblems to avoid recomputing.
Recursive Function is_interleave(i, j):

    Base Case: If i == len(s1) and j == len(s2), return True.

Memoization Check: If memo[i][j] is already computed, return its value.
Recursive Calls:

    If i < len(s1) and s1[i] matches s3[i+j], recursively call is_interleave(i+1, j). 

If j < len(s2) and s2[j] matches s3[i+j], recursively call is_interleave(i, j+1).

Store and Return: Store the result in memo[i][j] and return it.

Both approaches ensure that all characters are used and their relative order is maintained. Dynamic programming is generally preferred for its iterative nature and often better performance in practice for this type of problem.

*/

// Iterative DP approach
bool isInterleave(char *s1, char *s2, char *s3) {
    if(s1 == NULL || s2 == NULL || s3 == NULL) {
        return false;
    }
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int s3Len = strlen(s3);
    if(s3Len != (s1Len + s2Len)) {
        return false;
    }
    if(s3Len == 0) {
        return true;
    }
    bool dp[s1Len + 1][s2Len + 1];
    int i, j;
    dp[0][0] = true;
    for(j = 1; j <= s2Len; j++) {
        if((dp[0][j-1] == true) && (s2[j - 1] == s3[j - 1])) {
            dp[0][j] = true;
        } else {
            dp[0][j] = false;
        }
    }
    for(i = 1; i <= s1Len; i++) {
        if((dp[i - 1][0] == true) && (s1[i - 1] == s3[i - 1])) {
            dp[i][0] = true;
        } else {
            dp[i][0] = false;
        }
    }
    for(i = 1; i <= s1Len; i++) {
        for(j = 1; j <= s2Len; j++) {
            if(((dp[i - 1][j] == true) && (s1[i - 1] == s3[i + j - 1])) || \
                ((dp[i][j - 1] == true) && (s2[j - 1] == s3[i + j - 1]))) {
                dp[i][j] = true;
            } else {
                dp[i][j] = false;
            }
        }
    }
    for(i = 0; i <= s1Len; i++) {
        for(j = 0; j <= s2Len; j++) {
            printf((dp[i][j] == true) ? "T " : "F ");
        }
        printf("\n");
    }
    return dp[s1Len][s2Len];
}


// recursive DP approach:
// bool testInterleave(char *s1, char *s2, char *s3, int i, int j, bool inter) {
//     bool ans = inter;
//     if(i == (strlen(s1)) && (j == strlen(s2))) {
//         printf("Found");
//         ans = ans || true;
//     }
//     if((i < strlen(s1)) && s1[i] == s3[i + j]) {
//         ans = inter || testInterleave(s1, s2, s3, i + 1, j, inter);
//     } else if((j < strlen(s2)) && s2[j] == s3[i + j]) {
//         ans = inter || testInterleave(s1, s2, s3, i, j + 1, inter);
//     }
//     return ans;
// }

// bool isInterleave2(char *s1, char *s2, char *s3) {
//     if(s1 == NULL || s2 == NULL || s3 == NULL) {
//         return false;
//     }
//     int s1Len = strlen(s1);
//     int s2Len = strlen(s2);
//     int s3Len = strlen(s3);
//     if(s3Len != (s1Len + s2Len)) {
//         return false;
//     }
//     int i, j;
//     i = j = 0;
//     return testInterleave(s1, s2, s3, i, j, false);
// }

bool dfs(char *s1, char *s2, char *s3, int i, int j, int **memo) {
    if (memo[i][j] != -1) return memo[i][j];
    
    if (i == strlen(s1) && j == strlen(s2)) {
        return memo[i][j] = true;
    }
    
    if (i < strlen(s1) && s1[i] == s3[i + j]) {
        if (dfs(s1, s2, s3, i + 1, j, memo)) {
            return memo[i][j] = true;
        }
    }
    if (j < strlen(s2) && s2[j] == s3[i + j]) {
        if (dfs(s1, s2, s3, i, j + 1, memo)) {
            return memo[i][j] = true;
        }
    }
    
    return memo[i][j] = false;
}

bool isInterleave2(char *s1, char *s2, char *s3) {
    if (!s1 || !s2 || !s3) return false;
    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
    if (len1 + len2 != len3) return false;

    int **memo = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        memo[i] = (int *)malloc((len2 + 1) * sizeof(int));
        for (int j = 0; j <= len2; j++) {
            memo[i][j] = -1;
        }
    }

    bool result = dfs(s1, s2, s3, 0, 0, memo);

    for (int i = 0; i <= len1; i++) free(memo[i]);
    free(memo);

    return result;
}

int main(void) {
    char *s1 = "aabcc";
    char *s2 = "dbbca";
    char *s3 = "aadbbcbcac";
    // char *s1 = "aabcc";
    // char *s2 = "dbbca";
    // char *s3 = "aadbbbaccc";
    // char *s1 = "";
    // char *s2 = "";
    // char *s3 = "";
    // char *s1 = "aa";
    // char *s2 = "ab";
    // char *s3 = "aaba";
    // char *s1 = "aabcc";
    // char *s2 = "dbbca";
    // char *s3 = "aadbcbbcac";
    printf(isInterleave(s1, s2, s3) ? "true\n" :  "false\n");
    printf(isInterleave2(s1, s2, s3) ? "true\n" : "false\n");
    return 0;
}
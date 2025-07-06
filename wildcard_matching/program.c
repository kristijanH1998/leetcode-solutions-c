#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

// bool isMatch(char *s, char *p) {
//     if(s == NULL || p == NULL) {
//         fprintf(stderr, "Invalid strings\n");
//         exit(EXIT_FAILURE);
//     }
//     int sizeStr = strlen(s);
//     int sizePat = strlen(p);
//     if(sizePat == 0) {
//         fprintf(stderr, "Pattern string not specified.\n");
//         exit(EXIT_FAILURE);
//     }
//     int i, j;
//     //check that all characters in s are in English alphabet
//     for(i = 0; i < sizeStr; i++) {
//         if(!isalpha(s[i])) {
//             puts("Illegal string s.");
//             exit(-1);
//         }
//     }
//     i = j = 0;
//     while(j < sizePat) {
//         // if(i >= sizeStr) {
//         //     return false;
//         // }
//         if(p[j] != '*' && p[j] != '?') {
//             if(!isalpha(p[j])) {
//                 // fprintf(stderr, "Pattern string error: %s\n", strerror(errno));
//                 // perror("Pattern string error.");
//                 fprintf(stderr, "Pattern string illegal character found.\n");
//                 exit(-1);
//             }
//             if(s[i++] == p[j++]) {
//                 continue;
//             } else {
//                 return false;
//             }
//         } else if (p[j] == '?') {
//             if(s[i++] != '\0') {
//                 j++;
//                 continue;
//             }
//         } else if (p[j] == '*') {
//             // while((s[i] != p[j + 1]) && (s[i] != '\0')) {
//             //     i++;
//             // }
//             // while(s[i + 1] == p[j + 1]) {
//             //     i++;
//             // }
//             // j++;
//             int cmpLen = 1;
//             while(p[j + cmpLen] != '*' && p[j + cmpLen] != '\0') {
//                 cmpLen++;
//             }
//             while(strncmp(p + j + 1, s + i, cmpLen) != 0) {
//                 i++;
//             }
//             j = j + cmpLen;
//         }
//     }
//     if(i < sizeStr) {
//         return false;
//     }
//     return true;
// }

// #define MIN_NUM(int_arr, size, min, result) \
//     do { \
//         (result) = (int_arr)[0]; \
//         for(int i = 1; i < (size); i++) { \
//             if((int_arr)[i] < (result) && (int_arr)[i] > (min)) { \
//                 (result) = ((int_arr)[i]); \
//             } \
//         } \
//     } while(0) 

//finds smallest integer in integer array 'arr', larger than minimum integer 'min'
int findSmallest(int *arr, int size, int min) {
    int res = INT_MAX;
    int i;
    bool found = false;
    for(i = 0; i < size; i++) {
        if((arr[i] < res) && (arr[i] > min)) {
            found = true;
            res = arr[i];
        }
    }
    return found ? res : -1;
}

bool isMatch(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i;
    int stars = 0;
    // find number of asterisks in 'p'
    for(i = 0; i < pLen; i++) {
        if(p[i] == '*') {
            stars++;
        }
    }
    // if no asterisks in 'p', then just check for regular letters and question marks
    if(stars == 0) {
        if(sLen != pLen) {
            return false;
        }
        for(i = 0; i < pLen; i++) {
            if(p[i] == '?') {
                continue;
            } else {
                if(s[i] == p[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    // printf("%d\n", stars);
    char **substrings = (char **)malloc((stars + 1) * sizeof(char *));
    int substringsPos = 0;
    int j;
    // if there are asterisks(stars) in pattern string, extract all substrings separated by stars and store 
    // them in 'substrings'
    if(stars > 0) {
        // i = (p[0] == '*') ? 1 : 0;
        for(i = 0; i < pLen; i++){
            j = i;
            while((p[i] != '*') && (i < pLen)) {
                i++;
            }
            if(((p[i] == '*') || (p[i] == '\0') ) && (i > j)) {
                *(substrings + substringsPos) = (char *)malloc((i - j + 1) * sizeof(char));
                strncpy(*(substrings + substringsPos), p + j, (i - j) * sizeof(char));
                *(*(substrings + substringsPos) + (i - j)) = '\0';
                // puts(*(substrings + substringsPos));
                substringsPos++;
            }
        }
    }
    // print substrings 
    for(i = 0; i < substringsPos; i++) {
        puts(*(substrings + i));
    }

    // if no substrings extracted from 'p' (meaning 'p' only contains asterisks or nothing at all), return true
    // because asterisk(s) allow all values for 's', even empty string
    if(substringsPos == 0) {
        return true;
    }

    // now time to look for each substring within the 's' string, and save its index in the 's' string
    // after this step, we must verify that these indices are in ascending order. If they are not, then 's'
    // violates the pattern in 'p'

    // definition of substrIndices, a matrix that will store all indices at which each substring from 'p' is 
    // located within 's'. Note: substrings from 'p' are separated by asterisks
    int substrIndices[substringsPos][sLen] = {};
    for(i = 0; i < substringsPos; i++) {
        for(j = 0; j < sLen; j++) {
            substrIndices[i][j] = -1;
        }
    }
    // for(i = 0; i < substringsPos;i++) {
    //     for(j = 0; j < sLen;j++) {
    //         printf("%d ", substrIndices[i][j]);
    //     }
    //     printf("\n");
    // }

    // store ALL indices from 's' at which substrings from 'p' (strings separated by asterisks) are found
    int k = 0;
    for(i = 0; i < substringsPos; i++) {
        for(j = 0; j < sLen; j++) {
        // for(j = (sLen - 1); j >= 0; j--) {
            if(strncmp(*(substrings + i), s + j, strlen(*(substrings + i))) == 0) {
                printf("%s found!\n", *(substrings + i));
                while(substrIndices[i][k] != -1) {
                    k++;
                }
                substrIndices[i][k] = j;
                // break;
            }
        // } 
        }
        k = 0;
    }
    // check that ALL substrings have been found!
    for(i = 0, k = 0; i < substringsPos; i++, k = 0) {
        // while(substrIndices[i][k] != -1) {
        //     printf("%d ", substrIndices[i][k]);
        //     k++;
        // }
        while(k < sLen) {
            printf("%d ", substrIndices[i][k]);
            k++;
        }
        printf("\n");
    }
    // printf("%d\n", substringsPos);

    /* 
    saving indices (from 's') at which substrings from 'p' are found in 's', in such a manner that for the first
    substring we save smallest index at which it exists in 's', and then for each next substring, we try to find
    smallest index at which it appears in 's' that is larger than previous index stored before it (index of the
    previous substring). If once this process is over an array of integers that is generated is in ascending order,
    that means that substrings in 's' appear in the same order they are encountered in 'p', given that in 'p'
    they are separated by asterisks
    */
    int smallestMatches[substringsPos] = {};
    smallestMatches[0] = findSmallest(substrIndices[0], substringsPos, -1);
    for(i = 1; i < substringsPos; i++) {
        smallestMatches[i] = findSmallest(substrIndices[i], substringsPos, smallestMatches[i - 1]);
    }
    for(i = 0; i < substringsPos; i++) {
        printf("%d\n", smallestMatches[i]);
    }
    
    // checking whether array of smallest matches of substrings is in ascending order, and that no integer is -1
    // because if -1 is found, that means that that substring from 'p' was not found in 's', or that no suitable
    // index of it could be found that would conform to smallestMatches being the ascending array of integers
    for(i = 0; i < (substringsPos - 1); i++) {
        if((smallestMatches[i] >= 0) && (smallestMatches[i] < smallestMatches[i + 1])) {
            continue;
        } else {
            // puts("No match!");
            return false;
        }
    }

    // last check, to test for cases when 'p' doesn't start and/or end with asterisk, then 's' should fail if 
    // it has any characters beyond first and last (before first and after last) substrings from 'p', which are
    // stored in 'substrings'
    
    // find lowest and highest indices in substrIndices[][], which correspond to earliest and latest locations
    // in 's' where substrings from 'p' are found
    int minIndex = INT_MAX;
    int maxIndex = INT_MIN;
    for(i = 0; i < substringsPos; i++) {
        for(j = 0; (j < sLen) && (substrIndices[i][j] >= 0); j++) {
            if(substrIndices[i][j] < minIndex) {
                minIndex = substrIndices[i][j];
            }
            if(substrIndices[i][j] > maxIndex) {
                maxIndex = substrIndices[i][j];
            }
        }
    }
    printf("Min index with substring: %d\nMax index with substring: %d\n", 
        minIndex != INT_MAX ? minIndex : -1, maxIndex != INT_MIN ? maxIndex : -1);
    
    // if minIndex and maxIndex haven't been updated in last for loop, and all indices in substrIndices are -1,
    // then no matching indices were found, so return false
    if(minIndex == INT_MAX || maxIndex == INT_MIN) {
        return false;
    }

    // if 'p' doesn't start with an asterisk, but the first substring from 'p' is found at index in 's' higher
    // than 0, that means that some characters exist in 's' before the first substring from 'p', which in
    // absence of asterisk is a violation of the pattern, so return false
    if((p[0] != '*') && (minIndex > 0)) {
        return false;
    }
    
    // if 'p' doesn't end with an asterisk, but the portion of 's' at an index of last found substring (from 'p') 
    // doesn't equal that last found substring (also stored in 'substrings'), then that means there exist
    // characters in 's' beyond the last substring from 'p', and due to no asterisk at end of 'p', that's a 
    // violation of the pattern
    if((p[pLen - 1] != '*') && (maxIndex >= 0) && \
    (strncmp(s + maxIndex, *(substrings + (substringsPos - 1)), sLen - maxIndex) != 0)) {
        return false;
    }
    return true;
}

int main(void) {
    // char s[] = "aaabbccccccb";
    // char p[] = "a*cc?b";
    char s[] = "aayyyybbyccddyytt";
    char p[] = "*aa*bb*cc*dd*tt";
    // char s[] = "aaabbccccccb";
    // char p[] = "a*cc*b";
    // char s[] = "aabbccddccpaa";
    // char p[] = "*cc*aa*bb";
    // char s[] = "bbccddccpaaeeepplllq";
    // char p[] = "bb*dd*paa*ee";
    // char s[] = "b";
    // char p[] = "b*";
    // char s[] = "ryyu";
    // char p[] = "ryyu";
    // char s[] = "rqq";
    // char p[] = "*q";
    // char *p = NULL;
    bool match = isMatch(s, p);
    // if(match) {
    //     puts("true");
    // } else {
    //     puts("false");
    // }
    puts(match ? "Match!" : "No match!");
    // int nums[5] = {1, 2, 23, 5, 11};
    // printf("%d\n", findSmallest(nums, sizeof(nums) / sizeof(int), 2));
    return 0;
}
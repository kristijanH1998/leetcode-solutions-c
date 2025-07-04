#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

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

bool isMatch(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i;
    int stars = 0;
    for(i = 0; i < pLen; i++) {
        if(p[i] == '*') {
            stars++;
        }
    }
    // printf("%d\n", stars);
    char **substrings = (char **)malloc((stars + 1) * sizeof(char *));
    int substringsPos = 0;
    int j;
    // if there are asterisks(stars) in pattern string, extract all substrings separated by stars and store 
    // them in 'substrings'
    if(stars > 0) {
        for(i = 0; i < pLen; i++){
            j = i;
            while(p[i] != '*') {
                i++;
            }
            if((p[i] == '*') && (i > j)) {
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
    // now time to look for each substring within the 's' string, and save its index in the 's' string
    // after this step, we must verify that these indices are in ascending order. If they are not, then 's'
    // violates the pattern in 'p'
    for(i = 0; i < substringsPos; i++) {
        for(j = 0; j < sLen; j++) {
            if(strncmp(*(substrings + i), s + j, strlen(*(substrings + i))) == 0) {
                printf("%s found!\n", *(substrings + i));
                break;
            }
        }
    }


    
    return true;
}

int main(void) {
    // char s[] = "aaabbccccccb";
    // char p[] = "a*cc?b";
    char s[] = "haabbcch";
    char p[] = "*aa*b?*cc*h*";
    // char *p = NULL;
    bool match = isMatch(s, p);
    // if(match) {
    //     puts("true");
    // } else {
    //     puts("false");
    // }
    puts(match ? "true" : "false");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define A 1
// #define I 9
// #define J 10
// #define Z 26

// void decode(char *s, int sLen, int start, int numChars, int *decodings) {
//     if(start >= (sLen - 1)) {
//         (*decodings)++;
//         return;
//     }
//     if(s[start] == '0'){
//         return;
//     }
//     if(numChars == 1) {
//         printf("%c ", s[start]);
//         int first = s[start] - '0';
//         if(!(first >= A && first <= I)) {
//             return;
//         }
//     } else if(numChars == 2) {
//         printf("%c%c ", s[start], s[start + 1]);
//         int first = s[start] - '0';
//         int second = s[start + 1] - '0';
//         int totVal = first * 10 + second;
//         if(!(totVal >= J && totVal <= Z)) {
//             return;
//         }
//     }
//     if((sLen - 1 - start) >= 1) {
//         decode(s, sLen, start + 1, 1, decodings);
//     }
//     if((sLen - 1 - start) >= 2) {
//         decode(s, sLen, start + 2, 2, decodings);
//     }
//     return;
// }

// int numDecodings(char *s) {
//     if(s == NULL) {
//         return 0;
//     }
//     int sLen = strlen(s);
//     if(sLen == 0) {
//         return 0;
//     }
//     int decodings = 0;
//     decode(s, sLen, 0, 1, &decodings);
//     printf("\n");
//     decode(s, sLen, 0, 2, &decodings);
//     printf("\n");
//     return decodings;
// }

void decode(char *s, int sLen, int start, int *decodings) {
    if(start == sLen) {
        (*decodings)++;
        return;
    }
    if(s[start] == '0') {
        return;
    }
    // Try single digit
    if(start < sLen) {
        int val = s[start] - '0';
        if(val >= 1 && val <= 9) {
            decode(s, sLen, start + 1, decodings);
        }
    }
    // Try two digits
    if(start + 1 < sLen) {
        int val = (s[start] - '0') * 10 + (s[start + 1] - '0');
        if(val >= 10 && val <= 26) {
            decode(s, sLen, start + 2, decodings);
        }
    }
}

int numDecodings(char *s) {
    if (s == NULL || *s == '\0') {
        return 0;
    }
    int decodings = 0;
    decode(s, strlen(s), 0, &decodings);
    return decodings;
}

int main(void) {
    char *s = "12";
    // char *s = "11106";
    // char *s = "226";
    // char *s = "111111111111111111111111111111111111111111111";
    printf("%d\n", numDecodings(s));
    return 0;
}
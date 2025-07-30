#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOTS 3
#define MAXINTLEN 3

char **restoreIpAddresses(char *s, int *returnSize) {
    // starting indices for each dot:
    int dot1 = 1;
    int dot2 = 3;
    int dot3 = 5;
    // int dot4 = 7;
    int sLen = strlen(s);
    int tempLen = sLen + DOTS + 1;
    char tempAddr[tempLen];
    memset(tempAddr, 0, sLen + DOTS);
    tempAddr[tempLen - 1] = '\0';
    char **addresses = (char **)malloc(sizeof(char *));
    int i, j;
    for(; dot1 <= MAXINTLEN; dot1++) {
        for(dot2 = dot1 + 2; (dot2 <= (tempLen - 4)) && ((dot2 - dot1) <= (MAXINTLEN + 1)); dot2++) {
            for(dot3 = dot2 + 2; (dot3 <= (tempLen - 2)) && ((dot3 - dot2) <= (MAXINTLEN + 1)); dot3++) {
                if(dot3 < (tempLen - MAXINTLEN - 2)) {
                    continue;
                } else {


                    // if all integers in IP address are valid, fill tempAddr with this combination and save it to addresses
                    for(i = 0, j = 0; i < (tempLen - 1); i++) {
                        if(i == dot1 || i == dot2 || i == dot3) {
                            tempAddr[i] = '.';
                        } else {
                            tempAddr[i] = s[j++];
                        }
                    }
                    printf("%s\n", tempAddr);
                    memset(tempAddr, 0, sLen + DOTS);
                }
                // break;
            }
            // break;
        }
        // break;
    }
    

    return addresses;
}

int main(void) {
    char s[] = "25525511135";
    // char *s = "0000";
    // char *s = "121511";
    // char s[] = "101023";
    int returnSize = 0;
    char **addresses = restoreIpAddresses(s, &returnSize); 
    // for(int i = 0; i < returnSize; i++) {
    //     puts(*(addresses + i));
    // }
    // printf("%d\n", atoi("442"));

    return 0;
}
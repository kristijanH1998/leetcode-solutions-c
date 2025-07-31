#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOTS 3
#define MAXINTLEN 3
#define INTS 4
#define MAXDIGITS 20

char **restoreIpAddresses(char *s, int *returnSize) {
    if(s == NULL) {
        return NULL;
    }
    // starting indices for each dot:
    int dot1 = 1;
    int dot2 = 3;
    int dot3 = 5;
    // int dot4 = 7;
    int sLen = strlen(s);
    if(sLen < INTS || sLen > MAXDIGITS) {
        return NULL;
    }
    int tempLen = sLen + DOTS + 1;
    char tempAddr[tempLen];
    memset(tempAddr, 0, sLen + DOTS);
    tempAddr[tempLen - 1] = '\0';
    char **addresses = (char **)malloc(sizeof(char *));
    int i, j, int1, int2, int3, int4, valids;
    valids = 1;
    int1 = int2 = int3 = int4 = 0;
    char tokTempAddr[tempLen];
    char *intTok1, *intTok2, *intTok3, *intTok4;
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
                    // printf("%s\n", tempAddr);
                    // test validity of generated IP address
                    // printf("%d %d %d\n", dot1, dot2, dot3);
                    // printf("%s\n", strtok(tempAddr, "."));
                    // printf("%s\n", strtok(NULL, "."));
                    // printf("%s\n", strtok(NULL, "."));
                    // printf("%s\n", strtok(NULL, "\0"));
                    if(dot3 < (tempLen - 2)) {
                        strcpy(tokTempAddr, tempAddr);
                        intTok1 = strtok(tokTempAddr, ".");
                        intTok2 = strtok(NULL, ".");
                        intTok3 = strtok(NULL, ".");
                        intTok4 = strtok(NULL, ".");
                        if(((intTok1[0] == '0') && (strlen(intTok1) > 1)) || \
                        ((intTok2[0] == '0') && (strlen(intTok2) > 1)) || \
                        ((intTok3[0] == '0') && (strlen(intTok3) > 1)) || \
                        ((intTok4[0] == '0') && (strlen(intTok4) > 1))) {
                            continue;
                        }
                        int1 = atoi(intTok1);
                        int2 = atoi(intTok2);
                        int3 = atoi(intTok3);
                        int4 = atoi(intTok4);
                        // tempAddr = (void*)tempCharPtr;
                        // printf("%d %d %d %d\n", int1, int2, int3, int4);
                        if(((int1 >= 0) && (int1 <= 255)) && ((int2 >= 0) && (int2 <= 255)) && ((int3 >= 0) && (int3 <= 255)) \
                        && ((int4 >= 0) && (int4 <= 255))) {
                            *(addresses + (valids - 1)) = (char*)malloc(tempLen * sizeof(char));
                            memcpy(*(addresses + (valids - 1)), tempAddr, sizeof(tempAddr));
                            valids++;
                            addresses = (char**)realloc(addresses, valids * sizeof(char *));
                            // puts("valid");
                        }
                    }
                    int1 = int2 = int3 = int4 = 0;
                    memset(tempAddr, 0, sLen + DOTS);
                }
                // break;
            }
            // break;
        }
        // break;
    }
    *returnSize = valids - 1;
    return addresses;
}

int main(void) {
    // char s[] = "25525511135";
    // char *s = "0000";
    // char *s = "121511";
    // char s[] = "101023";
    char *s = "0";
    int returnSize = 0;
    char **addresses = restoreIpAddresses(s, &returnSize);
    printf("Valid addresses: %d\n", returnSize); 
    for(int i = 0; i < returnSize; i++) {
        // puts(*(addresses + i));
        printf("%s\n", *(addresses + i));
    }
    // printf("%d\n", atoi("442"));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

bool isMatch(char *s, char *p) {
    if(s == NULL || p == NULL) {
        fprintf(stderr, "Invalid strings\n");
        exit(EXIT_FAILURE);
    }
    int sizeStr = strlen(s);
    int sizePat = strlen(p);
    if(sizePat == 0) {
        fprintf(stderr, "Pattern string not specified.\n");
        exit(EXIT_FAILURE);
    }
    int i, j;
    //check that all characters in s are in English alphabet
    for(i = 0; i < sizeStr; i++) {
        if(!isalpha(s[i])) {
            puts("Illegal string s.");
            exit(-1);
        }
    }
    i = j = 0;
    while(j < sizePat) {
        // if(i >= sizeStr) {
        //     return false;
        // }
        if(p[j] != '*' && p[j] != '?') {
            if(!isalpha(p[j])) {
                // fprintf(stderr, "Pattern string error: %s\n", strerror(errno));
                // perror("Pattern string error.");
                fprintf(stderr, "Pattern string illegal character found.\n");
                exit(-1);
            }
            if(s[i++] == p[j++]) {
                continue;
            } else {
                return false;
            }
        } else if (p[j] == '?') {
            if(s[i++] != '\0') {
                j++;
                continue;
            }
        } else if (p[j] == '*') {
            while((s[i] != p[j + 1]) && (s[i] != '\0')) {
                i++;
            }
            while(s[i + 1] == p[j + 1]) {
                i++;
            }
            j++;
        }
    }
    if(i < sizeStr) {
        return false;
    }
    return true;
}

int main(void) {
    char s[] = "aaabbcccccc";
    char p[] = "a*c";
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
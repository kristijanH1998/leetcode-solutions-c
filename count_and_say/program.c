#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *count_and_say(int n) {
    if(n < 1 || n > 30) {
        printf("Invalid input: %s", strerror(errno));
        return "";
    }
    if(n == 1) {
        char *rlrs = (char *)malloc(2 * sizeof(char));
        *(rlrs + 0) = '1';
        *(rlrs + 1) = '\0';
        return rlrs;
    }
    char *rleStr = count_and_say(n - 1);
    size_t rleLen = strlen(rleStr);
    char *rleRes = (char *)malloc(2 * rleLen + 1);
    int count = 1;
    int i, j;
    for(i = 0, j = 0; i < rleLen; i++) {
        if(*(rleStr + i + 1) == *(rleStr + i)) {
            count++;
        } else {
            *(rleRes + (j++)) = (count + '0');
            *(rleRes + (j++)) = *(rleStr + i);
            count = 1;
        }
    }
    free(rleStr);
    rleRes[j] = '\0';
    return rleRes;
}

int main(void) {
    char *res;
    for(int i = 1; i <= 30; i++) {
        res = count_and_say(i);
        printf("%s\n\n", res);
    }
    free(res);
    // printf("%s\n", count_and_say(-1));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int myAtoi(char* s) {
    int i = 0;
    while(s[i] == ' ') {
        i++;
    }
    signed char pos = 1;
    if(s[i] == '-' || s[i] == '+') {
        if(s[i] == '-'){
            pos = -1;
        }
        i++;
    }
    while((s[i] - '0' == 0)) {
        i++;
    }
    long res = 0;
    for(; i < strlen(s); i++) {
        if(!(s[i] - '0' >= 0 && s[i] - '0' <= 9)){
            break;
        }
        if(((res * pos * 10) - (s[i] - '0')) <= (-1 * pow(2, 31))) {
            return (-1 * pow(2, 31));
        }
        if(((res * pos * 10) + (s[i] - '0')) >= ((pow(2, 31) - 1))) {
            return (pow(2, 31) - 1);
        }
        res = (res * 10) + (s[i] - '0');
    }
    res = res * pos; 
    return (int)res;
}

int main() { 
    printf("%d\n", myAtoi("-2147483649"));
    return 0;
}
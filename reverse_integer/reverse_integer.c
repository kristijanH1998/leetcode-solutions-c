#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int reverse(int x){
    bool neg = false;
    if(x < 0) {
        neg = true;
        x = x * (-1);
    }
    int digits = 0;
    int temp = x;
    while((x % 10 > 0) || (x / 10 > 0)) {
        digits++;
        x = x / 10;
    }
    x = temp;
    int res = 0;
    while(digits > 0) {
        res = res + ((x % 10) * pow(10, --digits));
        x = x / 10;
    }
    if(neg) {
        res = res * (-1);
    }
    if((res < -pow(2, 31)) || (res > (pow(2, 31) - 1))) {
        return 0;
    }
    return res;
}

int main() {
    int result = reverse(3345);
    printf("%d\n", result);
    return 0;
}
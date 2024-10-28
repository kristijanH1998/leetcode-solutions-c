#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int maxArea(int* height, int heightSize) {
    if(heightSize < 2 || heightSize > pow(10,5)) {
        return 0;
    }
    int right = heightSize - 1;
    int maxA = 0;
    for(int left = 0; left < heightSize; left++) {
        if(height[left] < 0 || height[left] > pow(10, 4)) {
            return 0;
        }
        while(right > left) {
            if(height[right] >= height[left]) {
                if(maxA < (height[left] * (right - left))) {
                    maxA = height[left] * (right - left);
                }   
                right = heightSize - 1;
                break;
            } 
            if(maxA < (MIN(height[right], height[left]) * (right - left))) {
                maxA = MIN(height[right], height[left]) * (right - left);
            }
            right--;
        }
        right = heightSize - 1;
    }
    return maxA;
}

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    printf("%d\n", maxArea(height, sizeof(height) / sizeof(int)));
    return 0;
}
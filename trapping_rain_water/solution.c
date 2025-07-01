#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a) <= (b)) ? (a) : (b))

int trap(int *height, int heightSize) {
    if((height == NULL) || (heightSize <= 0)) {
        return 0;
    }
    int i, j, k, maxLeft, maxRight;
    int water = 0;
    for(k = 0; k < heightSize; k++) {
        maxLeft = 0;
        maxRight = 0;
        for(i = 0, j = heightSize - 1; (i <= k) && (j >= k) && (i != j);) {
            if(i < k) {
                if(height[i] > maxLeft) {
                    maxLeft = height[i];
                }
                i++;
            }
            if(j > k) {
                if(height[j] > maxRight) {
                    maxRight = height[j];
                }
                j--;
            }
        }
        if((maxLeft > height[k]) && (maxRight > height[k])) {
            water = water + (MIN(maxLeft, maxRight) - height[k]); 
        }
        // printf("%d %d\n", maxLeft, maxRight);
        // printf("%d\n", MIN(maxLeft, maxRight) - height[k]);
        printf("%d %d %d %d %d\n", MIN(maxLeft, maxRight), height[k], maxLeft, maxRight, water);
    }
    return water;
}

int main(void) {
    int heights[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = sizeof(heights) / sizeof(int);
    // printf("%d\n", heightSize);
    printf("%d\n", trap(heights, heightSize));
    // printf("%d\n", MIN(-1, 4));
    return 0;
}
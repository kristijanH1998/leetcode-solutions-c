#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a,b) (((a) <= (b)) ? (a) : (b))

// sub-optimal solution: 
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

// second attempt:
// int trap(int *height, int heightSize) {
//     if((height == NULL) || (heightSize <= 0)) {
//         return 0;
//     }
//     int i, j, maxLeftIndex, maxRightIndex;
//     int highest, maxLeft, maxRight;
//     highest = maxLeft = maxRight = INT_MIN;
//     int highestIndex = 0;
//     // finding the tallest index
//     for(i = 0; i < heightSize; i++) {
//         if(height[i] > highest) {
//             highest = height[i];
//             highestIndex = i;
//         }
//     }
//     // finding next tallest indices to the left and right of the tallest index
//     // continue to look for next tallest indices to the left and right, adding water according to the formula from sub-optimal solution
//     int tempIndex = highestIndex - 1;
//     int water = 0;
//     while(tempIndex > 0) {
//         for(i = tempIndex; i >= 0; i--) {
//             if(height[i] > maxLeft) {
//                 maxLeft = height[i];
//                 maxLeftIndex = i;
//             }
//         }
//         while(tempIndex > maxLeftIndex) {
//             water = water + (maxLeft - height[tempIndex]);
//             tempIndex--;
//         }
//         maxLeft = INT_MIN;
//     }
//     tempIndex = highestIndex + 1;
//     while(tempIndex < (heightSize - 1)) {
//         for(j = tempIndex; j <= (heightSize - 1); j++) {
//             if(height[j] > maxRight) {
//                 maxRight = height[j];
//                 maxRightIndex = j;
//             }
//         }
//         while(tempIndex < maxRightIndex) {
//             water = water + (maxRight - height[tempIndex]);
//             tempIndex++;
//         }
//         maxRight = INT_MIN;
//     }
//     printf("%d\n", water);
//     return water;
// }

int main(void) {
    int heights[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = sizeof(heights) / sizeof(int);
    // printf("%d\n", heightSize);
    printf("%d\n", trap(heights, heightSize));
    // printf("%d\n", MIN(-1, 4));
    return 0;
}
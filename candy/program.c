#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int candy(int *ratings, int ratingsSize) {
    if(ratings == NULL || ratingsSize <= 0) {
        return 0;
    }
    if(ratingsSize == 1) {
        return 1;
    }
    int candies[ratingsSize];
    // memset(candies, 1, ratingsSize * sizeof(int));
    int i;
    for(i = 0; i < ratingsSize; i++) {
        candies[i] = 1;
        // printf("%d ", candies[i]);
    }
    // printf("\n");
    // if(ratings[0] > ratings[1]) {
    //     candies[0] = candies[1] + 1;
    // }
    // for(i = 1; i < (ratingsSize - 1); i++) {
    //     if(i - 1 >= 0)
    // }
    // if(ratings[ratingsSize - 1] > ratings[ratingsSize - 2]) {
    // }
    int j;
    for(i = 1; i < ratingsSize; i++) {
        if(ratings[i - 1] < ratings[i]) {
            candies[i] = candies[i - 1] + 1;
        } else if((ratings[i - 1] > ratings[i]) && (candies[i - 1] <= candies[i])) {
            j = i;
            while((j > 0) && (ratings[j - 1] > ratings[j]) && (candies[j - 1] <= candies[j])) {
                (candies[j - 1])++;
                j--;
            }
        } else {
            continue;
        }
    } 
    int minSum = 0;
    for(i = 0; i < ratingsSize; i++) {
        printf("%d ", candies[i]);
        minSum += candies[i];
    }
    printf("\n");
    return minSum;
}

int main() {
    // int ratings[] = {1,0,2};
    // int ratings[] = {5,4,6,2,1,9};
    // int ratings[] = {1,1,1,1};
    int ratings[] = {1,2,4,2};
    printf("%d\n", candy(ratings, sizeof(ratings) / sizeof(int)));
    // printf("%d\n", MIN(5, -2));
    return 0;
}
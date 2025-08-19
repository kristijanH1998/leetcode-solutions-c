#include <stdio.h>
#include <stdlib.h>

int canCompleteCircle(int *gas, int gasSize, int *cost, int costSize) {
    int index = -1;
    if((gasSize != costSize) || (gasSize < 0) || (costSize < 0)) {
        return -1;
    }
    if((gas == NULL) || (cost == NULL)) {
        return -1;
    }
    int i, j;
    int difference = 0;
    for(i = 0; i < gasSize; i++) {
        for(j = i; j < gasSize; j++) {
            difference += gas[j];
            difference -= cost[j - 1];
        }
        for(j = 0; j < i; j++) {
            difference += gas[j];
            difference -= cost[j - 1];
        }
        printf("%d\n", difference);
        if(difference == 0) {
            index = j;
            break;
        } 
        difference = 0;
    }
    return index;
}

int main() {
    int gas[] = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};
    int gasSize = sizeof(gas) / sizeof(int);
    int costSize = sizeof(cost) / sizeof(int);
    // printf("%d %d\n", gasSize, costSize);
    int index = canCompleteCircle(gas, gasSize, cost, costSize);
    printf("%d\n", index);
    return 0;
}
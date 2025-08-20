#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize) {
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
        difference += gas[i];
        printf("+%d ", gas[i]);
        for(j = i + 1; j < gasSize; j++) {
            difference += gas[j];
            if(j == 0) {
                difference -= cost[gasSize - 1];
                printf("+%d -%d ", gas[j], cost[gasSize - 1]);
            } else {
                difference -= cost[j - 1];
                printf("+%d -%d ", gas[j], cost[j - 1]);
            }   
        }
        for(j = 0; j < i; j++) {
            difference += gas[j];
            if(j == 0) {
                difference -= cost[gasSize - 1];
                printf("+%d -%d ", gas[j], cost[gasSize - 1]);
            } else {
                difference -= cost[j - 1];
                printf("+%d -%d ", gas[j], cost[j - 1]);
            }
        }
        difference -= cost[j - 1];
        printf("-%d diff: %d\n", cost[j], difference);
        if(difference == 0) {
            index = i;
            break;
        } 
        difference = 0;
    }
    return index;
}

int main() {
    // int gas[] = {1,2,3,4,5};
    // int cost[] = {3,4,5,1,2};
    int gas[3] = {2, 3, 4};
    int cost[3] = {3, 4, 3};
    int gasSize = sizeof(gas) / sizeof(int);
    int costSize = sizeof(cost) / sizeof(int);
    // printf("%d %d\n", gasSize, costSize);
    int index = canCompleteCircuit(gas, gasSize, cost, costSize);
    printf("%d\n", index);
    return 0;
}
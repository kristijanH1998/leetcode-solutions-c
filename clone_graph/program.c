#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int val;
    int numNeighbors;
    struct Node **neighbors;
};

struct Node *cloneGraph(struct Node *s) {



    return NULL;
}

int main() {
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n1->neighbors = (struct Node **)malloc(2 * sizeof(struct Node*));
    n1->neighbors[0] = n2;
    n1->neighbors[1] = n4;
    // printf("%d %d\n", n1->neighbors[0]->val, n1->neighbors[1]->val);
    n1->numNeighbors = 2;
    n2->neighbors = (struct Node **)malloc(2 * sizeof(struct Node*));
    n2->neighbors[0] = n1;
    n2->neighbors[1] = n3;
    n2->numNeighbors = 2;
    n3->neighbors = (struct Node **)malloc(2 * sizeof(struct Node*));
    n3->neighbors[0] = n2;
    n3->neighbors[1] = n4;
    n3->numNeighbors = 2;
    n4->neighbors = (struct Node **)malloc(2 * sizeof(struct Node*));
    n4->neighbors[0] = n1;
    n4->neighbors[1] = n3;
    n4->numNeighbors = 2;
    struct Node *nodes[4] = {n1, n2, n3, n4};
    int nodesSize = sizeof(nodes) / sizeof(struct Node *); 
    // for(int i = 0; i < nodesSize; i++) {
    //     printf("node %d val %d neighbor vals %d %d\n", i + 1, nodes[i]->val, nodes[i]->neighbors[0]->val, \
    //         nodes[i]->neighbors[1]->val);
    // }
    struct Node ***adjList = (struct Node ***)malloc(nodesSize * sizeof(struct Node **));
    *(adjList) = (struct Node **)malloc(2 * sizeof(struct Node *));
    memcpy(*(adjList), n1->neighbors, 2 * sizeof(struct Node *));
    // printf("%d %d\n", (*(*(adjList) + 0))->val, (*(*(adjList) + 1))->val);
    *(adjList + 1) = (struct Node **)malloc(2 * sizeof(struct Node *));
    memcpy(*(adjList + 1), n2->neighbors, 2 * sizeof(struct Node *));
    *(adjList + 2) = (struct Node **)malloc(2 * sizeof(struct Node *));
    memcpy(*(adjList + 2), n3->neighbors, 2 * sizeof(struct Node *));
    *(adjList + 3) = (struct Node **)malloc(2 * sizeof(struct Node *));
    memcpy(*(adjList + 3), n4->neighbors, 2 * sizeof(struct Node *));
    for(int i = 0; i < nodesSize; i++) {
        printf("%d %d\n", (*(*(adjList + i) + 0))->val, (*(*(adjList + i) + 1))->val);
    }



    struct Node *n1Cpy = cloneGraph(n1);




    return 0;
}
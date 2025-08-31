#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

int findRandom(struct Node *head, struct Node *randPtr) {
    int i = 0;
    while(head != NULL && head != randPtr) {
        i++;
        head = head->next;
    }
    return i;
}

struct Node *copyRandomList(struct Node *head) {
    if(head == NULL) {
        return NULL;
    }
    struct Node *headCpy = (struct Node *)malloc(sizeof(struct Node));
    struct Node *headCpyTemp = headCpy;
    while(head != NULL) {
        headCpy->val = head->val;
        if(head->next) {
            headCpy->next = (struct Node *)malloc(sizeof(struct Node));
        } else {
            headCpy->next = NULL;
        }
        head = head->next;
        headCpy = headCpy->next;
    }
    headCpy = headCpyTemp;
    return headCpy;
}

int main() {
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n5 = (struct Node *)malloc(sizeof(struct Node));
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    n1->val = 7;
    n2->val = 13;
    n3->val = 11;
    n4->val = 10;
    n5->val = 1;
    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;
    struct Node *n1Temp = n1;
    int i;
    printf("Node Addresses:\n");
    for(i = 1; n1 != NULL; i++) {
        printf("n%d: %p rand ptr: %p\n", i, n1, n1->random);
        n1 = n1->next;
    }
    n1 = n1Temp;
    struct Node *headCpy = copyRandomList(n1);
    struct Node *headCpyTemp = headCpy;
    while(headCpy != NULL) {
        printf("%d ", headCpy->val);
        headCpy = headCpy->next;
    }
    headCpy = headCpyTemp;
    printf("\n");
    printf("Copy List Node Addresses:\n");
    for(i = 1; headCpy != NULL; i++) {
        printf("n%d: %p rand ptr: %p\n", i, headCpy, headCpy->random);
        headCpy = headCpy->next;
    }
    // printf("%d\n%d\n", findRandom(n1, n4->random), findRandom(n1, n3->random));
}
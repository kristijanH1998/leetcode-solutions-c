#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// set second to last node to point to NULL (it becomes tail of the list), and last node to point to the
// current head(it becomes new head of the list)

void move_right(struct ListNode **nodesArr, int length) {
    struct ListNode *temp = *(nodesArr + length - 1);
    for(int i = length - 1; i > 0; i--) {
        *(nodesArr + i) = *(nodesArr + (i - 1));
    }
    *(nodesArr + 0) = temp;
    return;
}

struct ListNode *rotate_right(struct ListNode *head, int k) {
    if((k < 0) || (k > (2 * pow(10, 9))) || (head == NULL)) {
        return NULL;
    }
    struct ListNode *start = head;
    int length = 1;
    while(head->next) {
        head = head->next;
        length++;
    }
    head = start;
    if(length == 1 || k == 0) {
        return head;
    }
    while(k > 100 && k % 10 == 0) {
        k = k / 10;
    }
    // printf("%d\n", length);
    struct ListNode **nodesArr = (struct ListNode **)malloc(length * sizeof(struct ListNode *));
    int i;
    for(i = 0; i < length; i++) {
        *(nodesArr + i) = head;
        head = head->next;
        // printf("%d ", (*(nodesArr + i))->val);
    }
    // printf("\n");
    head = start;
    for(i = 0; i < k; i++) {
        (*(nodesArr + (length - 1)))->next = head;
        (*(nodesArr + (length - 2)))->next = NULL;
        head = *(nodesArr + (length - 1));
        start = head;
        move_right(nodesArr, length);
    }
    for(i = 0; i < length; i++) {
        printf("%d ", (*(nodesArr + i))->val);
    }
    printf("\n");
    return start;
}

int main(void){
    struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;
    n1->next = n2;
    n2->next = n3;
    // n3->next = NULL;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    struct ListNode *head = rotate_right(n1, 10);
    while(head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
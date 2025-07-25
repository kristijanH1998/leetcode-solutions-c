#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x) {
    // struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    // struct ListNode *tempHead = head;
    // struct ListNode *tempResult = result;
    // do {
    //     if(x > (head->val)) {
    //         result->val = head->val;
    //         result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    //         result = result->next;
    //     }
    //     head = head->next;
    // } while(head != NULL);
    // head = tempHead;
    // do {
    //     if(x <= (head->val)) {
    //         result->val = head->val;
    //         result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    //         result = result->next;
    //     }
    //     head = head->next;
    // } while(head != NULL);
    // result = NULL;
    // result = tempResult;
    // return result;

    //better solution:
    struct ListNode *tempHead = head;
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    while (head) {
        if (head->val < x) {
            tail->next = malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = head->val;
            tail->next = NULL;
        }
        head = head->next;
    }
    // reset head and repeat for >= x
    head = tempHead;
    while (head) {
        if (head->val >= x) {
            tail->next = malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = head->val;
            tail->next = NULL;
        }
        head = head->next;
    }
    return dummy.next;
}

int main(void) {
    int vals[] = {1,4,3,2,5,2};
    // int vals[] = {2, 1};
    int valsNum = sizeof(vals) / sizeof(int);
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = vals[0];
    struct ListNode *temp = head;
    int i;
    for(i = 1; i < valsNum; i++) {
        head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->next->val = vals[i];
        head = head->next;
    }
    head->next = NULL;
    head = temp;
    for(i = 0; i < valsNum; i++) {
        printf("%d ", head->val);
        head = head->next;
    }
    head = temp;
    printf("\n");
    for(temp = partition(head, 3); temp != NULL; temp = temp->next) {
        printf("%d ", temp->val);
    }
    printf("\n");
    return 0;
}
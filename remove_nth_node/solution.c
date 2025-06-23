#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAXSIZE 30

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode *head) {
    if(head != NULL) {
        while(head != NULL) {
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL) {
        return NULL;
    }
    if(n <= 0) {
        printList(head);
        return head;
    }
    struct ListNode* temp = head;
    struct ListNode* first = head;
    int size = 1;
    while(head->next != NULL) {
        size++;
        head = head->next;
    }
    if(size > MAXSIZE || n > size) {
        return NULL;
    }
    head = temp;
    if(n == size) {
        temp = head;
        head = head->next;
        printList(head); 
    } else {
        for(int i = 0; i < ((size - n) - 1); i++) {
            head = head->next;
        }
        temp = head->next;
        head->next = temp->next;
        printList(first);
    }
    free(temp);
    temp = NULL;
}

int main(void) {
    struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    n1->val = 1;
    struct ListNode *n2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    n1->next = n2;
    n2->val = 2;
    struct ListNode *n3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    n2->next = n3;
    n3->val = 3;
    struct ListNode *n4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    n3->next = n4;
    n4->next = n5;
    n4->val = 4;
    n5->val = 5;
    n5->next = NULL;
    // printf("%d\n", n1->val);
    removeNthFromEnd(n1, 3);
    return 0;
}
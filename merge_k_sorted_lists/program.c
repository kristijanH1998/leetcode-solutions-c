#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    // in this function, keep an array of integers on stack, starting with listsSize zeroes, where each integer
    // at index i represents current node in each of the listsSize linked sublists from 'lists' under consideration
    // (being considered for minimum value).
    // Even better approach is having an array of ListNode* (pointers/addresses of nodes), where pointer at index
    // i in the array is the current node in lists[i] being considered for minimum value before being placed in
    // returned array of ListNode structures

    // printing all linked list nodes in 'lists' array of linked lists
    if(*lists == NULL || sizeof(**lists) != sizeof(struct ListNode)) {
        return *lists;
    }
    int i, j;
    j = 0;
    int total_nodes = 0;
    for(i = 0; i < listsSize; i++) {
        do {
            // printf("%d ", lists[i][j].val);
            total_nodes++;
        } while(lists[i][j++].next != NULL);
        j = 0;
        printf("\n");
    }
    printf("Total number of nodes: %d\n", total_nodes);
    
    // int cursors[listsSize] = {0};
    // int j = cursors[0];
    struct ListNode* current_nodes[listsSize] = {};
    for(i = 0; i < listsSize; i++) {
        current_nodes[i] = lists[i];
        // printf("%d ", current_nodes[i]->val);
    }
    // printf("\n");

    struct ListNode **res_list = (struct ListNode **)malloc(total_nodes * sizeof(struct ListNode*));
    struct ListNode *temp = NULL;
    int res_list_pos = 0;
    int min_val = INT_MAX;
    
    while(res_list_pos < total_nodes) {
        j = 0;
        for(i = 0; i < listsSize; i++) {
            if((current_nodes[i] != NULL) && (current_nodes[i]->val < min_val)) {
                min_val = current_nodes[i]->val;
                temp = current_nodes[i];
                // save counter i to j to be able to advance to next node in the sublist from which a node with minimal value is copied to res_list 
                j = i;
                // res_list[res_list_pos]= current_nodes[i];
                // res_list[res_list_pos]->val = 
            }
        }
        res_list[res_list_pos] = temp;
        res_list_pos++;
        current_nodes[j] = current_nodes[j]->next;
        min_val = INT_MAX;
    }
    
    for(i = 1; i < res_list_pos; i++) {
        res_list[i - 1]->next = res_list[i];
    }
    res_list[i - 1]->next = NULL;

    // for(i = 0; i < res_list_pos; i++) {
    //     printf("%d ", (*(res_list + i))->val);
    // }
    // while(*res_list != NULL) {
    //     printf("%d ", (*res_list)->val);
    //     *res_list = (*res_list)->next;
    // }
    // printf("\n");

    // for(i = 0; i < listsSize; i++) {
    //     for(; j < listsSize; j++) {
    //         if(lists[i][j])
    //     }
    //     j = 0;
    // }
    return *res_list;
}

int main(void) {
    int listsSize = 3;
    struct ListNode **lists = (struct ListNode **)malloc(listsSize * sizeof(struct ListNode *));
    *(lists + 0) = (struct ListNode *)malloc(3 * sizeof(struct ListNode));
    *(lists + 1) = (struct ListNode *)malloc(3 * sizeof(struct ListNode));
    *(lists + 2) = (struct ListNode *)malloc(2 * sizeof(struct ListNode));
    lists[0][0].val = 3;
    lists[0][0].next = &lists[0][1];
    lists[0][1].val = 3;
    lists[0][1].next = &lists[0][2];
    lists[0][2].val = 6;
    lists[0][2].next = NULL;

    lists[1][0].val = 1;
    lists[1][0].next = &lists[1][1];
    lists[1][1].val = 9;
    lists[1][1].next = &lists[1][2];
    lists[1][2].val = 12;
    lists[1][2].next = NULL;

    lists[2][0].val = 3;
    lists[2][0].next = &lists[2][1];
    lists[2][1].val = 7;
    lists[2][1].next = NULL;

    struct ListNode *mergedLists = mergeKLists(lists, listsSize);
    while(mergedLists != NULL) {
        printf("%d ", mergedLists->val);
        mergedLists = mergedLists->next;
    }
    printf("\n");
    return 0;
}
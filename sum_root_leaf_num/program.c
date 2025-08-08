#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void findHeight(struct TreeNode *root, int *maxHeight, int currHeight) {
    if(currHeight > (*maxHeight)) {
        (*maxHeight) = currHeight;
    }
    if(root->left) {
        findHeight(root->left, maxHeight, currHeight + 1);
    }
    if(root->right) {
        findHeight(root->right, maxHeight, currHeight + 1);
    }
}

void findPathSum(struct TreeNode *node, int sum, int *sumTotal) {
    sum = ((sum * 10) + node->val);
    // printf(" %d ", sum);
    if(node->left == NULL && node->right == NULL) {
        *sumTotal += sum;
        sum = sum - (node->val);
        return;
    }
    if(node->left) {
        findPathSum(node->left, sum, sumTotal);
    }
    if(node->right) {
        findPathSum(node->right, sum, sumTotal);
    }
}

int sumNumbers(struct TreeNode *root) {
    // printf("%d %d\n", root->left->val, root->right->val);
    int sum = 0;
    int sumTotal = 0;
    findPathSum(root, sum, &sumTotal);
    printf("%d\n", sumTotal);
    // int height = 0;
    // findHeight(root, &height, 0);
    // printf("%d\n", height);
    return 0;
}

int main() {
    struct TreeNode n1;
    struct TreeNode n2;
    struct TreeNode n3;
    int nodes = 3;
    struct TreeNode *nodeArr[] = {&n1, &n2, &n3};
    for(int i = 0; i < nodes; i++) {
        nodeArr[i]->val = i + 1;
    }
    n1.left = &n2;
    n1.right = &n3;
    n2.left = NULL;
    n2.right = NULL;
    n3.left = NULL;
    n3.right = NULL;
    // printf("%d %d\n", n1.left->val, n1.right->val);
    // struct TreeNode n1;
    // struct TreeNode n2;
    // struct TreeNode n3;
    // struct TreeNode n4;
    // struct TreeNode n5;
    // n1.val = 4;
    // n2.val = 9;
    // n3.val = 0;
    // n4.val = 5;
    // n5.val = 1;
    // n1.left = &n2;
    // n1.right = &n3;
    // n2.left = &n4;
    // n2.right = &n5;
    // n3.left = NULL;
    // n3.right = NULL;
    // n4.left = NULL;
    // n4.right = NULL;
    // n5.left = NULL;
    // n5.right = NULL;
    sumNumbers(&n1);
}
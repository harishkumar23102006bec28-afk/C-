#include <stdlib.h>

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int* result = (int*)malloc(100 * sizeof(int));
    
    struct TreeNode* stack[100];
    int top = -1;
    
    stack[++top] = root;
    
    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        result[(*returnSize)++] = node->val;
        
        // Push left child first so right child is processed first
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
    }
    
    // Reverse the result array to get Left -> Right -> Root
    int left = 0;
    int right = (*returnSize) - 1;
    while (left < right) {
        int temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }
    
    return result;
}

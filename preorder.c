/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

void pret(struct TreeNode* root, int *node, int *size)
{
    if(root==NULL)
        return;   
    
    node[*size] = root->val;
    *size = *size + 1;
    
    pret(root->left, node, size);
    pret(root->right, node, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){

   
    int *node = (int *)malloc(sizeof(int) * 200);
    *returnSize = 0;
     if(root == NULL)
    {
         return node;
        *returnSize = 0;   
    }
    pret(root, node, returnSize);
    return node;
}

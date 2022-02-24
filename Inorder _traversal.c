
/* 
 *  Jay C header files This is a way to find the length
 *  For coding practice pick this code as it is.
 */
 
int getsize(struct TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return 1+getsize(root->left)+getsize(root->right);
    }
}

int* traversal(int *arr, int *pos, struct TreeNode* root)
{
    if(root==NULL)
    {
        return arr;
    }
    else
    {
        arr=traversal(arr,pos,root->left);
        arr[*pos] = root->val;
        *pos = *pos + 1;
        arr=traversal(arr,pos,root->right);
        return arr;
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = getsize(root);
    int *arr = (int*)malloc(sizeof(int)*size);
    *returnSize = size;
    int pos=0;
    arr=traversal(arr, &pos, root);
    return arr;
}


bool bstcycle(struct TreeNode* root, long min, long max)
{
    if(root==NULL)
        return true;
     // Compare the value of current node with min and max, it should always be in between    
    if(root->val <= min || root->val>=max)
        return false;
  
  // When calling left node, make the current node value as max and when calling right make the current node val as min.
  
    return bstcycle(root->left, min, root->val) && bstcycle(root->right, root->val, max);
    
}

bool isValidBST(struct TreeNode* root){

    if(root==NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }
    
    long min = LONG_MIN;
    long max = LONG_MAX;
    // The reason of using long is the boundary condition where the min and max of int value 
    // For example this case fails: [-2147483648,null,2147483647]
    
    return bstcycle(root, min, max);
}

// Leetcode 226

TreeNode* invertTree(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return root;
    }
    
    TreeNode *l = root->left;
    TreeNode *r = root->right;
    
    root->left = r;
    root->right = l;
    
    invertTree(root->left);
    invertTree(root->right);
    return root;
}


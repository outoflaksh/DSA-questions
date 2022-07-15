// Leetcode 654

TreeNode* helper(int left, int right, vector<int>& nums) {
    if (left >= right) {
        return nullptr;
    }
    
    int maxValIdx = left;
    
    for (int i = left; i < right; i++) {
        if (nums[i] > nums[maxValIdx]) {
            maxValIdx = i;
        }
    }
    
    TreeNode* root = new TreeNode(nums[maxValIdx]);
    
    root->left = helper(left, maxValIdx, nums);
    root->right = helper(maxValIdx+1, right, nums);
    
    return root;
    
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return helper(0, nums.size(), nums);
}
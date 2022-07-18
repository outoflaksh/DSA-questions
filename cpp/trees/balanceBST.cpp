// Leetcode 1382

void getTreeNodes(TreeNode* n, vector<int>& nums) {
    if (n == NULL) {
        return;
    }
    
    getTreeNodes(n->left, nums);
    nums.push_back(n->val);
    getTreeNodes(n->right, nums);
}

TreeNode* createBST(vector<int> nums, int left, int right) {
    if (left > right) {
        return NULL;
    } 
    
    int mid = (left + right) / 2;
    
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = createBST(nums, left, mid-1);
    root->right = createBST(nums, mid+1, right);
    
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> vals;
    getTreeNodes(root, vals);
    
    return createBST(vals, 0, vals.size()-1);
}
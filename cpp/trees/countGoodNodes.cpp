// Leetcode 1448

void traverse(TreeNode* n, int highest, int& count) {
    if (n==NULL) {
        return;
    }
    
    if (n->val >= highest) {
        highest = n->val;
        count++;
    }
    
    traverse(n->left, highest, count);
    traverse(n->right, highest, count);
}

int goodNodes(TreeNode* root) {
    int ans = 0;
    traverse(root, root->val, ans);
    
    return ans;
}
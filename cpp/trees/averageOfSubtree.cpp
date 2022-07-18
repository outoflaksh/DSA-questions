// Leetcode 2256

void subtreeAvg(TreeNode* node, int& sum, int& n) {
    if (node == NULL) {
        return;
    }
    
    sum += node->val;
    n++;
    
    subtreeAvg(node->left, sum, n);
    subtreeAvg(node->right, sum, n);
}

void traverse(TreeNode* node, int& count) {
    if (node == NULL) {
        return;
    }
    
    int sum = 0, n = 0;
    subtreeAvg(node, sum, n);
    
    if (sum/n == node->val) {
        count++;
    }
    
    traverse(node->left, count);
    traverse(node->right, count);
}

int averageOfSubtree(TreeNode* root) {
    int ans = 0;
    
    traverse(root, ans);
    
    return ans;
}
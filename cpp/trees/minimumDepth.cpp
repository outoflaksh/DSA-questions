// Leetcode 111

int minLevel = INT_MAX;

// helper func to traverse all paths of the tree given a root
void traverse(TreeNode* n, int level) {
    if (n == nullptr) {
        return;
    }
    
    level++;
    
    if (!n->left && !n->right) {
        // update the minimum depth
        minLevel = min(minLevel, level);
        return;
    }
    
    traverse(n->left, level);
    traverse(n->right, level);
}

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    traverse(root, 0);
    return minLevel;
}
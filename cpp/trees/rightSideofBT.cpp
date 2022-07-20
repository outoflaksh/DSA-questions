// Leetcode 199

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    
    if (root == NULL) {
        return ans;
    }
    
    queue<TreeNode*> q;
    
    q.push(root);
    
    while (!q.empty()) {
        ans.push_back(q.back()->val);
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            TreeNode* n = q.front();
            q.pop();
            
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
    }
    
    return ans;
}


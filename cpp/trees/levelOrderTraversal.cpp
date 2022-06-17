// Leetcode 102

// given the root of a binary tree, return a level order traversal of the tree
// in form of a vector of vectors, with values of nodes from left to right of each level


// soln: performing a BFS on the root of the tree using a queue

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    
    if (root == nullptr) return result;
    
    // we use a queue to keep the visited nodes
    queue<TreeNode*> q;
    q.push(root);
    
    // we add nodes to the queue of each next level while removing the ones from the current level
    // thus always having a queue with the level nodes

    while (!q.empty()) {
        vector<int> level;
        int qSize = q.size();
        
        for (int i = 0; i < qSize; i++) {
            TreeNode* n = q.front();
            q.pop();
            
            level.push_back(n->val);
            
            // adding the children of each node in queue (of a level) to the queue

            if (n->left != nullptr) {
                q.push(n->left);
            }
            
            if (n->right != nullptr) {
                q.push(n->right);
            }
        }
        
        result.push_back(level);
    }
    
    return result;
}

// Time: O(N); Space: O(N)
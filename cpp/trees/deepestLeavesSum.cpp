// brute force solution
// Time & Space: O(N)

class Solution {
    unordered_map<int, int> leafSum;
    int maxLevel = 1;
public:
    void findLeaves(TreeNode* n, int level) {
        if (n == nullptr) {
            return;
        }
        
        level++;
        
        if (n->left == nullptr && n->right == nullptr) {
            //leaf node 
            
            maxLevel = max(maxLevel, level);
            leafSum[level] += n->val;
            
            return;
        }
        
        findLeaves(n->left, level);
        findLeaves(n->right, level);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        findLeaves(root, 0);
        
        return leafSum[maxLevel];
    }
};
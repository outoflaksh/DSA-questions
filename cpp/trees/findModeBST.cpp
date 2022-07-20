// Leetcode 501

class Solution {
    int maxFreq = INT_MIN;
public:
    void traverse(TreeNode* n, unordered_map<int, int>& freq) {
        if (n == NULL) {
            return;
        }
        
        freq[n->val]++;
        
        if (freq[n->val] > maxFreq) {
            maxFreq = freq[n->val];
        }
        
        traverse(n->left, freq);
        traverse(n->right, freq);

    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> mode;
        unordered_map<int, int> freq;
        traverse(root, freq);
        
        for (auto i : freq) {
            if (i.second == maxFreq) {
                mode.push_back(i.first);
            }
        }
        
        return mode;
    }
};
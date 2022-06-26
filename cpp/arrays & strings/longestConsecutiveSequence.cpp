// Leetcode 128. Longest Consecutive Sequence

#include <iostream>
#include <unordered_set>

int longestConsecutive(vector<int>& nums) {
    int maxLen = 0;
    unordered_set<int> unique;
    
    for (int i : nums) {
        unique.insert(i);
    }
    
    for (int i : nums) {
        if (unique.find(i+1) == unique.end()) {
            int currNum = i;
            int currLen = 1;
            
            while (unique.find(currNum - 1) != unique.end()) {
                currNum--;
                currLen++;
            }
            
            if (currLen > maxLen) {
                maxLen = currLen;
            }
        }
    }
    
    return maxLen;   
}

// Time: O(N); Space: O(N)
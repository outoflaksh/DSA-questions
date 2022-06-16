// Leetcode 3

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        int maxLen = 1;
        int low = 0, high = 0;
        unordered_set<char> seen;
        
        while (high < s.length()) {
            if (seen.find(s[high]) == seen.end()) {
                seen.insert(s[high]);
                high++;
            } else {
                if (seen.size() > maxLen) {
                    maxLen = seen.size();
                }
                
                seen.erase(s[low]);
                low++;
            }
        }
            
        if (seen.size() > maxLen) {
            maxLen = seen.size();
        }

        return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << lengthOfLongestSubstring("abcedaeb") << endl; // 5

}

// Time: O(N); Space: O(N)
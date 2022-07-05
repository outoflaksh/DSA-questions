// Leetcode 198: House Robber

#include <iostream>
#include <vector>

using namespace std;


// Approach: we keep adding the max of the last two alternate vals on the curr val in the vector.
// this makes sure that all the possible paths are stored and then we take the max of the last two vals
// as that is the correct answer

int rob(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 1) {
        return nums[0];
    }
    
    if (n == 2) {
        return max(nums[0], nums[1]);
    }
    
    nums[2] += nums[0];
    
    for (int i = 3; i < n; i++) {
        nums[i] += max(nums[i-2], nums[i-3]);
    }
    
    return max(nums[n-1], nums[n-2]);
}

int main() {
    vector<int> v1 = {2, 0, 4, 12, 7};
    cout << rob(v1) << endl;  // 14
}
// Leetcode 55

#include <iostream>

using namespace std;

bool jump(int i, vector<int>& nums) {
    if (i == 0) {
        return true;
    } else {
        for (int j = 0; j < i; j++) {
            if (abs(i-j) <= nums[j]) {
                return jump(j, nums);
            }
        }

        return false;
    }
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    
    return jump(n-1, nums);
}

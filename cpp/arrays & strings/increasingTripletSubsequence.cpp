// Leetcode 334

#include <iostream>
#include <vector>

using namespace std;

// soln: track the two min elements in increasing indices and if there exists a number bigger than
// both of them then a triplet as such exists otherwise not 

int getMax(vector<int>& nums) {
    int maxNum = nums[0];
    
    for (int i : nums) {
        if (i > maxNum) {
            maxNum = i;
        }
    }
    
    return maxNum;
}

bool increasingTriplet(vector<int>& nums) {
    int maxVal = getMax(nums);
    int firstMin = maxVal;
    int secondMin = maxVal;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] <= firstMin) {
            firstMin = nums[i];
        } else if (nums[i] <= secondMin) {
            secondMin = nums[i];
        } else {
            return true;
        }
    }
    
    return false;
}

int main() {
	vector<int> n1{0, 53, 1, -2, 0, 2};
	vector<int> n2{0, 53, 1, -2, 0};

	cout << increasingTriplet(n1) <<  endl; // 1
	cout << increasingTriplet(n2) <<  endl; // 0
}

// Time: O(N); Space: O(1)
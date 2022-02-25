// Two sum but the input array is sorted in non-decreasing order
// Leetcode 167

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        if (numbers[left] + numbers[right] > target) {
            right--;
        } else if (numbers[left] + numbers[right] < target) {
            left++;
        } else {
            break;
        }
    }
    
    return vector<int>{left + 1, right + 1};
}

int main() {
	vector<int> arr{2,7,11,15};

	cout << "[";
	for (int i : twoSum(arr, 9)) {
		cout << i << ", ";
	}
	cout << "]" << endl;
}
// given an array/vector of strings such that it is sorted but rotated
// meaning:- {4,5,1,2,3} -> it is sorted but doesnt start from 1; instead is rotated
// we need to find the index of the rotation point, in this case the idx of 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// soln: binary search approach
// find the mid and if mid value > first value, then it would mean the point lies ahead
// else it would be behind or to the left

int findRotationPoint(const vector<string>& words)
{
    // find the rotation point in the array
    int low = 0;
    int high = words.size() - 1;
    int mid = low + ((high - low) / 2);
    
    while (low <= high) {
        mid = low + ((high - low) / 2);
        if (words[mid][0] >= words[low][0]) {
            low = mid;
        } else {
            high = mid;
        }
        
        if (low+1 == high) {
            break;
        }
    }

    return high;
}

int main() {
    vector<string> words{"safe", "undo", "xmas", "zero", "and", "call", "fall"}; // return idx of "and"

    cout << findRotationPoint(words) << endl; // 4
}

// Time: O(logN); Space: O(1)
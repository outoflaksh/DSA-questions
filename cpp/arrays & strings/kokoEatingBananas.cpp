// Leetcode 875

#include <iostream>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = piles[0];
    
    for (int i : piles) {
        if (i > right) {
            right = i;
        }
    }
    
    while (left < right) {
        int mid = (right + left) / 2;
        int currTime = 0;
        
        for (int i : piles) {
            currTime += (i / mid) + ((i % mid) != 0); 
        }
        
        if (currTime > h) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return right;
}

// Time: O(N*logN); Space: O(1)
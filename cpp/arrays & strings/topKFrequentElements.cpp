// Leetcode 347
// given an array of ints, return the k most frequent values in it

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// we use a max heap to store the frequencies and corresponding value
// since a max heap will always have the max element on its top, we can 
// remove the top k times

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    priority_queue<pair<int, int>> heap;
    vector<int> result;
    
    for (int i : nums) {
        freq[i]++;
    }
    
    for (auto i : freq) {
        heap.push(make_pair(i.second, i.first));
    }
    
    while (k > 0) {
        int c = heap.top().second;
        heap.pop();
        
        result.push_back(c);
        
        k--;
    }
    
    return result;
}

// Time: O(N*logN) (heapifying everytime we remove top of heap); Space: O(N)
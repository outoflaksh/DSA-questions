// Leetcode 746

#include <iostream>
#include <vector>

using namespace std;

// Approach: start at the end index and calculate one step and two steps back
// and whatever is the minimum, we add that to the cost.

int func(int i, vector<int>& cost, int memo[]) {
    if (i==0 || i==1) {
        return cost[i];
    } else {
        if (memo[i] == -1) {
            memo[i] = cost[i] + min(func(i-1, cost, memo), func(i-2, cost, memo));
        }
        
        return memo[i];
    }
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    
    int memo[n+1];
    
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    return min(func(n-1, cost, memo), func(n-2, cost, memo));
    
}

int main() {
    vector<int> v1 = {1, 1, 100, 2, 3, 5, 100, 1};
    vector<int> v2 = {10, 12, 13}; 
    cout << minCostClimbingStairs(v1) << endl; // 9
    cout << minCostClimbingStairs(v2) << endl; // 12
}
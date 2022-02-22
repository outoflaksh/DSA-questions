// Leetcode 121

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// two pointer soln
int maxProfit(vector<int> &prices)
{
    int left = 0, right = 1;
    int profit = 0;

    while (right < prices.size())
    {
        // update left to be the min of the pointers
        if (prices.at(right) < prices.at(left))
        {
            left = right;
        }
        else
        {
            // calc profit at all possible right vals
            profit = max(profit, prices.at(right) - prices.at(left));
        }

        right++;
    }

    return profit;
}

int main()
{
    vector<int> v1{7, 1, 4, 6, 5};
    vector<int> v2{7, 6, 5, 4};
    vector<int> v3{9, 3, 6, 1, 3};

    cout << maxProfit(v1) << endl; // 5
    cout << maxProfit(v2) << endl; // 0
    cout << maxProfit(v3) << endl; // 3
}
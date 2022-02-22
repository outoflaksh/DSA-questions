#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> unique;

    for (int i = 0; i < nums.size(); i++)
    {
        if (unique.find(nums.at(i)) != unique.end())
        {
            return true;
        }

        unique.insert(nums.at(i));
    }

    return false;
}

int main()
{
    vector<int> v1{1, 2, 3, 1};
    cout << containsDuplicate(v1) << endl; // true
}
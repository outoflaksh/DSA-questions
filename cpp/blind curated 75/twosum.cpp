// For a given list/array of integers, and a target,
// print the indices of the two integers in the array
// that give a sum = target and -1 -1 in case
// such a pair does not exist

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool check_key(unordered_map<int, int> m, int key)
{
    if (m.find(key) == m.end())
        return false;

    return true;
}

int main()
{
    vector<int> arr{1, 4, 91, -90, 1}; // size >= 2
    int target = 1;

    unordered_map<int, int> visited;
    int left = -1, right = -1, complement;

    for (int i = 0; i < arr.size(); i++)
    {
        complement = target - arr.at(i);

        if (check_key(visited, complement))
        {
            left = visited[complement];
            right = i;
        }
        else
        {
            visited[arr.at(i)] = i;
        }
    }

    cout << left << ' ' << right; // 2 3
}
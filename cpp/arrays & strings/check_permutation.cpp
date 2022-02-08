// Given two lowercase strings, WAF to check
// if one is a permutation of the other

#include <iostream>
#include <string>

using namespace std;

bool checkPermutation(string s1, string s2)
{
    // unequal length implies not permutations
    if (s1.length() != s2.length())
    {
        return false;
    }

    int positionArray[26] = {}, currentPosition;

    for (char c : s1)
    {
        currentPosition = c - 97;
        positionArray[currentPosition]++;
    }

    for (char c : s2)
    {
        currentPosition = c - 97;
        positionArray[currentPosition]--;
    }

    for (int i : positionArray)
    {
        if (i != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << checkPermutation("abc", "acb") << endl; // 1
    cout << checkPermutation("abc", "ab") << endl;  // 0
    cout << checkPermutation("abc", "adb") << endl; // 0
}
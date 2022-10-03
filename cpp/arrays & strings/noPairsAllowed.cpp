#include <iostream>
#include <string>

using namespace std;

bool pairs(string s)
{
    char curr;

    for (char c : s)
    {
        if (curr == c)
        {
            return true;
        }
        else
        {
            curr = c;
        }
    }

    return false;
}

int main()
{
    cout << pairs("ab") << endl;
}
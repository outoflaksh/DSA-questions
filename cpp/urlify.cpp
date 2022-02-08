// WAF to replace all spaces in a string with "%20"
// The str has sufficient space in the end to accomodate
// the additional chars. The "true length" of the str is also given

#include <iostream>
#include <string>

using namespace std;

string urlify(string s, int trueLength)
{
    int n = s.length() - 1;
    int end = trueLength - 1;

    for (int i = n; i >= 0; i--)
    {

        if (s[end] == ' ')
        {
            s[i] = '0';
            s[i - 1] = '2';
            s[i - 2] = '%';
            i -= 2;
        }
        else
        {
            s[i] = s[end];
        }
        end--;
    }
    return s;
}

int main()
{
    cout << urlify("Mr John Smith    ", 13) << endl; // Mr%20John%20Smith
    cout << urlify("chandler bing  ", 13) << endl;   // chandler%20bing
    cout << urlify("abc", 3) << endl;                // abc
}
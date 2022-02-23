// Return the index of first occurence of needle in haystack
// -1 if needle not in haystack & 0 if length(needle) = 0

#include <iostream>
#include <string.h>

using namespace std;

int strStr(string haystack, string needle) {
    int h = haystack.length();
    int n = needle.length();

    if (h < n) return -1;

    for (int i=0; i<h; i++) {
        if (haystack.substr(i, n) == needle) {
            return i;
        }
    }

    return -1;
}

int main() {
    cout << strStr("hello", "ll") << endl; //2 
}
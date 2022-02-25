// given a string, WAF to return true if there exists a permutation of the string that is a palindrome,
// otherwise return false

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//soln: idea is that for it to have a palindrome, at most one char can have an odd frequency


// hash map soln
bool hasPalindromePermutationMap(const string& str)
{
    // check if any permutation of the input is a palindrome
    unordered_map<char, int> freq;
    
    for (char c : str) {
        if (freq.find(c) == freq.end()) {
            freq.insert(make_pair(c, 0));
        }
        
        freq[c]++;
    }
    
    int oddCount = 0;
    
    for (char c : str) {
        if (freq[c]%2 != 0) {
            oddCount++;
        }
    }
    
    return oddCount <= 1;
}


// hash set soln
bool hasPalindromePermutationSet(const string& str)
{
    // check if any permutation of the input is a palindrome
    unordered_set<char> oddChars;
    
    for (char c : str) {
        if (oddChars.find(c) == oddChars.end()) {
            oddChars.insert(c);
        } else {
        	oddChars.erase(c);
        }
    }

    int oddCount = oddChars.size();
    
    return oddCount <= 1;
}

int main() {
	string s = "ivicc";

	cout << hasPalindromePermutationMap(s) << endl; // true or 1
	cout << hasPalindromePermutationSet(s) << endl; // true or 1
}

// Time: O(n); 
// Space: O(n) -> although since the number of chars in ascii or unicode is limited (e.g. 128) we can argue that space taken is constant
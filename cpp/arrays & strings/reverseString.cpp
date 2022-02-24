// WAF to reverse a string in-place

#include <iostream>
#include <string.h>

using namespace std;

// for loop
string reverseString(string s) {
	if (s.empty()) {
		return "";
	}

	int n = s.length() - 1;

	for (int i = 0; i < n/2; i++) {
		char temp = s[i];
		s[i] = s[n-i];
		s[n-i] = temp;
	}

	return s;
}

// while loop
string reverseString2(string s) {
	if (s.empty()) {
		return "";
	}

	int left = 0, right = s.length()-1;

	while (left < right) {
		char temp = s[left];
		s[left] = s[right];
		s[right] = temp;

		left++;
		right--;
	}

	return s;

}



int main() {
	cout << reverseString("hello world") << endl;
	cout << reverseString2("hello world") << endl;
}